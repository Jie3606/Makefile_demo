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

// 响应数组大小
#define RESPONSE_SIZE 5

#endif //DEF_H