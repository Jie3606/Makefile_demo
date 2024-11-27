/**
 *@file def.h
 * @author jieliu (jieliu@msi.com)
 * @brief 全局宏定义
 * @version 0.1
 * @date 2024-11-06
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DEF_H
#define DEF_H

#include <stdint.h>

// 错误码
#define ERROR_INVALID_ADDRESS 0x01      //无效地址
#define ERROR_WRITE_TO_READ_ONLY 0x02   //尝试写入只读缓存器
#define ERROR_READ_FROM_WRITE_ONLY 0x03 //尝试读取只写缓存器
#define ERROR_INVALID_OPERATION 0x04    //无效操作码
#define ERROR_INVALID_DATA_FIELD 0x05   //读取操作时数据字段非0x00

// 通讯指令格式定义
#define START_BYTE1 0xFA
#define START_BYTE2 0xFA
#define OPERATION_WRITE 0x01
#define OPERATION_READ 0x02

#define READ_RESPONSE_DATA_DEF 0X00
#define ERROR_RESPONSE_REGISTER_DEF 0x00
#define ERROR_RESPONSE_OPERATION_DEF 0x13
#define OPERATION_WRITE_RESPONSE 0x11
#define OPERATION_READ_RESPONSE 0x12


// 设备寄存器地址定义
#define DEVICE_ID             0x00
#define RESERVED_BIT          0x01
#define TEMPERATURE_DATA      0x02
#define MAX_TEMPERATURE       0x03
#define TEMPERATURE_DATA      0x04
#define BATTERY_LEVEL_LOW     0x05
#define POWER_OUTPUT_ENABLE   0x06
#define POWER_STATUS          0x07


#define STAR_FLAG 0xFA
#define DATE_RETURN_FLAG 0x00

// 响应数组大小
#define RESPONSE_SIZE 5

#endif //DEF_H