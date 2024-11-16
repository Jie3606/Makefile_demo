/**
 *@file process_command.c
 * @author jieliu (jieliu@msi.com)
 * @brief 命令处理器
 * @version 0.1
 * @date 2024-11-06
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "process_command.h"
#include "def.h"
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint8_t registers[8] = {
    0x01, // 0x00: 设备 ID
    0x00, // 0x01: 保留位
    0x32, // 0x02: 温度
    0x50, // 0x03: 最高温度
    0x03, // 0x04: 电池电量高位
    0xA5, // 0x05: 电池电量低位
    0x01, // 0x06: 电源输出 Enable (此缓存器设定会影响到 0x07 缓存器)
    0x01  // 0x07: 电源输出状态 (此缓存器会受到 0x06 影响)
};

void process_command_error(uint8_t errno, uint8_t *response)
{
    response[0] = 0xFA;
    response[1] = 0xFA;
    response[2] = 0x13;
    response[3] = 0x00;
    response[4] = errno;
    send_response(response);
}

void process_command_read(uint8_t register_addr, uint8_t data, uint8_t *response)
{
    // 检查是否为只写寄存器
    if (register_addr == 0x06)
    {
        process_command_error(ERROR_READ_FROM_WRITE_ONLY, response);
        return;
    }
    // 检查数据字段是否为 0x00
    if (data != 0x00)
    {
        process_command_error(ERROR_INVALID_DATA_FIELD, response);
        return;
    }
    response[0] = 0xFA;
    response[1] = 0xFA;
    response[2] = 0x12;
    response[3] = register_addr;
    response[4] = registers[register_addr];
    send_response(response);
}

void process_command_write(uint8_t register_addr, uint8_t data, uint8_t *response)
{
    // 检查是否为只读寄存器
    switch (register_addr)
    {
    case 0x00: // 设备 ID
    case 0x02: // 温度
    case 0x04: // 电池电量高位
    case 0x05: // 电池电量低位
    case 0x07: // 电源状态
        process_command_error(ERROR_WRITE_TO_READ_ONLY, response);
        return;
    default:
        registers[register_addr] = data;

        if (register_addr == 0x06)
        {
            registers[0x07] = data;
        }
        response[0] = 0xFA;
        response[1] = 0xFA;
        response[2] = 0x11;
        response[3] = register_addr;
        response[4] = data;
        send_response(response);
        break;
    }
}
void process_command(uint8_t *command, uint8_t *response)
{
    if (command[0] != 0xFA || command[1] != 0xFA)
    {
        process_command_error(ERROR_INVALID_OPERATION, response);
        return;
    }
    uint8_t operation = command[2];
    uint8_t register_addr = command[3];
    uint8_t data = command[4];
    if (register_addr > 0x07)
    {
        process_command_error(ERROR_INVALID_ADDRESS, response);
        return;
    }
    if (operation == 0x01)
    {
        process_command_write(register_addr, data, response);
    }
    else if (operation == 0x02)
    {
        process_command_read(register_addr, data, response);
    }
    else
    {
        process_command_error(ERROR_INVALID_OPERATION, response);
    }
}

// 发送响应的函数
void send_response(uint8_t *response)
{
    printf("Response: ");
    for (int i = 0; i < RESPONSE_SIZE; i++)
    {
        printf("%02X ", response[i]);
    }
    printf("\n");
}
