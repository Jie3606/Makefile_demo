/**
 *@file test.h
 * @author jieliu (jieliu@msi.com)
 * @brief 测试代码头文件
 * @version 0.1
 * @date 2024-11-06
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef TEST_H
#define TEST_H

#include <stdint.h>
#include <stddef.h>

extern uint8_t test_cases_incomplete[];
extern uint8_t test_cases_normal[];

extern void print_registers();

extern void test_cases_complete(uint8_t *test_data, size_t length);

extern void test_case_incomplete(uint8_t (*test_data)[5], size_t comm_num);

void test();

#endif //TEST_H
