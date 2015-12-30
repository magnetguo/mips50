/*
*文件：id.c
*功能：完成译码函数的编写
*
*
*注意事项：
*/

#include "id.h"

/* ID 将输入的instr指令译码为头文件声明的各字段 */
void ID(unsigned instr) {

	op = (instr>>26) & 0x0000003f;//0000000000111111
	rs1 = (instr>>21) & 0x0000001f;//0000000000011111
	rs2 = (instr>>16) & 0x0000001f;
	rd = (instr>>11) & 0x0000001f;
	func = instr & 0x000007ff;//0000011111111111
	imme_u = instr & 0x0000ffff;//1111111111111111
	imme_i = (int)(short)(instr & 0x0000ffff);//必须先把高位的0全部去掉才能做有符号位扩展
	offset = (((int)(instr<<6))>>6);//先左移，转换类型，算数右移
}