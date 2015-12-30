操作系统：Mac OSX 10.10
编译环境：clang 6.1.0, make 3.81
已经提供Makefile，可以直接make
操作：已经设置好内存、寄存器组中的初始状态，可以直接[Enter]观看效果
regs:
R1=1, R0=0
mem:
0x00000004: 0xa4010014(LW R1 (20)R1)
0x00000008: 0x04220001(ADDI R2 R1 1)
0x0000000c: 0xb8020014(SW (20)R0 R2)
0x00000010: 0xc7fffffc(J -4)
0x00000014: 1((20)R1 = 1)
文件说明：
main.c：设置指令、数据；取指、译码、执行、pc更新等功能调用
instructions.c：实现50条mips指令
id.c：实现译码功能
mem.c：实现内存、寄存器读取操作模拟
op_and_operations.h：操作码枚举变量定义
instructions.h、id.h、mem.h：接口声明头文件
