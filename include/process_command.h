/**
 *@file process_command.h
 * @author jieliu (jieliu@msi.com)
 * @brief 命令处理器头文件
 * @version 0.1
 * @date 2024-11-06
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef PROCESS_COMMAND_H
#define PROCESS_COMMAND_H
#include <stdint.h>
// 缓存器默认值
extern uint8_t registers[8];

extern void process_command_error(uint8_t errno, uint8_t *response);
extern void process_command_read(uint8_t register_addr, uint8_t data, uint8_t *response);
extern void process_command_write(uint8_t register_addr, uint8_t data, uint8_t *response);
extern void process_command(uint8_t *command, uint8_t *response);
extern void send_response(uint8_t *response);

#endif // PROCESS_COMMAND_H