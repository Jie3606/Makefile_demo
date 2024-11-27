
#include <stdint.h>

// 定义通讯协议指令的结构体
typedef struct {
    uint8_t start1;    // 第一个起始码字节，固定为 0xFA
    uint8_t start2;    // 第二个起始码字节，固定为 0xFA
    uint8_t operation; // 操作码，0x01 表示写入，0x02 表示读取
    uint8_t register_addr; // 缓存器地址，有效范围为 0x00 到 0x07
    uint8_t data;      // 数据，范围为 0x00 到 0xF9
} ProtocolCommand;