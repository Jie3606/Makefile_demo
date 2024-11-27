#include <stdint.h>

// 定义寄存器结构体
typedef struct {
    uint8_t device_id;           // 0x00: 设备 ID
    uint8_t reserved;            // 0x01: 保留位（未使用）
    uint8_t temperature;         // 0x02: 温度值
    uint8_t max_temperature;     // 0x03: 最高温度值
    uint8_t battery_level_high;  // 0x04: 电池电量高位
    uint8_t battery_level_low;   // 0x05: 电池电量低位
    uint8_t power_output_enable; // 0x06: 电源输出 Enable（影响 0x07）
    uint8_t power_output_status; // 0x07: 电源输出状态（受 0x06 影响）
} DeviceRegisters;

// 初始化寄存器结构体的函数
void initializeDeviceRegisters(DeviceRegisters *regs) {
    regs->device_id = 0x01;
    regs->reserved = 0x00;
    regs->temperature = 0x32;
    regs->max_temperature = 0x50;
    regs->battery_level_high = 0x03;
    regs->battery_level_low = 0xA5;
    regs->power_output_enable = 0x01;
    regs->power_output_status = 0x01;
}
