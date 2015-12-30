/*
*文件：mem.c
*功能：完成内存、寄存器的定义；
*
*
*注意事项：
*/
#include <stdio.h>
#include "mem.h"

/*--------------------------------------------------------*/
/* mem_uint_write 将uint类型数据写入内存中 */
void mem_uint_write(unsigned operand, int addr) {
	*(unsigned *)(mem_base + addr) = operand;//指针的类型转换，char* 转换为 uint*
}

/*--------------------------------------------------------*/
/* mem_uint_read 将uint类型数据从内存中读出 */
unsigned mem_uint_read(int addr) {
	return *(unsigned *)(mem_base + addr);
}

/*--------------------------------------------------------*/
/* mem_int_write 将int类型数据写入内存中 */
void mem_int_write(int operand, int addr) {
	*(int *)(mem_base + addr) = operand;//指针的类型转换，char* 转换为 int*
}

/*--------------------------------------------------------*/
/* mem_int_read 将int类型数据从内存中读出 */
int mem_int_read(int addr) {
	return *(int *)(mem_base + addr);
}

/*--------------------------------------------------------*/
/* mem_ubyte_read 将ubyte类型数据从内存中读出 */
unsigned char mem_ubyte_read(int addr) {
	return *(unsigned char*)(mem_base + addr);
}

/*--------------------------------------------------------*/
/* mem_ubyte_write 将ubyte类型数据写入内存中 */
void mem_ubyte_write(unsigned char operand, int addr) {
	*(unsigned char *)(mem_base + addr) = operand;
}

/***************************************************************/
/* reg_int_write 将int类型数据写入寄存器中 */
void reg_int_write(int operand, int addr) {
	//printf("operand: %d\n", operand);
	*(ireg_base + addr) = operand;
	//printf("%d\n", *((int *)(ireg_base + addr)));
	//注意int和char之间的差别，既然传进来的是寄存器号，那必须4倍
	//已经改用int，不再需要
}

/*--------------------------------------------------------*/
/* reg_int_read 将int类型数据从寄存器中读出 */
int reg_int_read(int addr) {
	return *(ireg_base + addr);
}

/*--------------------------------------------------------*/
/* reg_uint_write 将uint类型数据写入寄存器中 */
void reg_uint_write(unsigned operand, int addr) {
	*(unsigned *)(ireg_base + addr) = operand;//指针的类型转换，int* 转换为 uint*
}

/*--------------------------------------------------------*/
/* reg_uint_read 将uint类型数据从寄存器中读出 */
unsigned reg_uint_read(int addr) {
	return *(unsigned *)(ireg_base + addr);
}
//addr开始形参是uint，实参却用了int。二者要对应

/*--------------------------------------------------------*/
/* reg_float_write 将float类型数据写入寄存器中 */
void reg_float_write(float operand, int addr) {
	//这里的地址都是已经考虑了类型在里面的，都是以类型作为单位的了
	*(freg_base + addr) = operand;
	//此处不用指针类型转换，因为声明的就是float类型
}

/*--------------------------------------------------------*/
/* reg_float_read 将float类型数据从寄存器中读出 */
float reg_float_read(int addr) {
	return *(freg_base + addr);
}

/*--------------------------------------------------------*/
/* reg_double_write 将double类型数据写入寄存器中 */
void reg_double_write(double operand, int addr) {
	//这里的地址都是已经考虑了类型在里面的，都是以类型作为单位的了
	*(double*)(freg_base + addr) = operand;
	//此处不用指针类型转换，因为声明的就是float类型
}

/*--------------------------------------------------------*/
/* reg_double_read 将double类型数据从寄存器中读出 */
double reg_double_read(int addr) {
	return *(double*)(freg_base + addr);
}