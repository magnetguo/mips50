/*
*文件：id.h
*功能：完成译码码的声明
*
*
*注意事项：
*/

#define _H_ID

unsigned op;//操作码
unsigned rs1;//源寄存器1
unsigned rs2;//源寄存器2
unsigned rd;//目的寄存器
unsigned func;//R功能
unsigned imme_u;//无符号扩展立即数
int imme_i;//有符号扩展立即数
int offset;//地址偏移量
//没有初始化，所以也是可以的！


void ID(unsigned instr);
