 ＝ /*
*文件：main.c
*功能：完成内存、寄存器的初始化；
*	  完成指令、数据的初始化；
*     完成控制逻辑（取指、译码、执行、写回）
*
*编译：gcc -o isa main.c instructions.c mem.c id.c 
*     不用带h文件，会自己找的
*运行：./isa
*输入：重复输入 Enter
*
*注意事项：由于更新方式有差别，为了控制逻辑的简洁，pc在每个函数里面自己更新
*/
#include <stdio.h>
#include <stdlib.h>

//#ifndef MEM
#include "mem.h"
//#endif

//#ifndef _H_ID
#include "id.h"
//#endif

//#ifndef _H_INSTRUCTIONS
#include "instructions.h"
//#endif

#include "op_and_func.h"

//#define DEBUG

/* 主存和寄存器定义，外部声明的全局变量 */
char *mem_base;
unsigned mem_size = 10000;//假设主存的大小是10000个字节

int* ireg_base;
unsigned ireg_size = 32;//32个寄存器整型寄存器

float* freg_base;
unsigned freg_size = 32;//32个浮点寄存器

int FPS;//浮点状态寄存器

/* 译码变量定义，外部定义的全局变量 */
unsigned op;//操作码
unsigned rs1;//源寄存器1
unsigned rs2;//源寄存器2
unsigned rd;//目的寄存器
unsigned func;//R功能
unsigned imme_u;//无符号扩展立即数
int imme_i;//有符号扩展立即数
int offset;//地址偏移量

/* 译码枚举变量声明 */
//extern enum Func oper_val;
//extern enum Oper func_val;

unsigned pc = 0x00000004;//认为程序的起始地址在4，必须是4的倍数！
unsigned instr;

int main(void) {

	/* 分配空间，内存物理上就是char的组合 */
	mem_base = (char *)malloc(sizeof(char)*mem_size);
	if(mem_base == NULL) {
		//如果分配失败
		fprintf(stderr, "no enouph space for mem!\n");
		exit(1);
	}

	ireg_base = (int *)malloc(sizeof(char)*ireg_size);
	if(ireg_base == NULL) {
		//如果分配失败
		fprintf(stderr, "no enouph space for reg!\n");
		exit(1);
	}

	freg_base = (float *)malloc(sizeof(float)*freg_size);
	if(freg_base == NULL) {
		//如果分配失败
		fprintf(stderr, "no enouph space for reg!\n");
		exit(1);
	}
	/*******************************************************/
	/*  指令、数据初始化 */
	mem_uint_write(0xa4010014, 0x00000004);//LW R0+0x00000014 (20) R1  101001(41), 00000, 00001, 0x0014
	mem_uint_write(0x04220001, 0x00000008);//000001,00001, 00010, 0000000000000001,ADDI, R1, R2, 1
	mem_uint_write(0xb8020014, 0x0000000c);//SW R0+0x00000014      R2  101110(46), 00000, 00010, 0x0014     
	mem_uint_write(0xc7fffffc, 0x00000010);//110001(49),11111111111111111111111100 ,j -4*4
	mem_uint_write(1, 0x00000014);

	reg_int_write(1, 1);//R1=1
	reg_int_write(0, 0);//R0=0，一直

	/*******************************************************/
	/* 控制逻辑 */
	//instr = mem_uint_read(pc);//取第一条指令
	//printf("instr0: %08X\n", instr);//8位16进制输出
	while(pc) {
		//pc放在函数里面修改，是不是不合适？
		/* 取指令 */
		printf("pc: 0x%08X\n", pc);
		instr = mem_uint_read(pc);//取第一条指令
		printf("instr: 0x%08X\n", instr);//8位16进制输出

		/* 译码 */
		//printf("%02X\n", op);//2位16进制
		ID(instr);
		printf("op: %d\n", op);

		if(op) {//如果不是R型指令
			oper_val = (enum Oper) op;//强制类型转换
			switch(oper_val) {
				case ADDI: instr_ADDI(); break;
				case J: instr_J(); break;
				case LW: instr_LW(); break;
				case SW: instr_SW(); break;
				default: {
					fprintf(stderr, "can not be ided for instruction %u\n", op);
					pc = 0;//结束程序
				}
			}
		}
		else {//如果是R型指令
			func_val = (enum Func) func;
			switch(func_val) {
				case ADD: instr_ADD(); break;
				case ADDU: instr_ADDU(); break;
				default: {
					fprintf(stderr, "can not be ided for instruction R func %u\n", func);
					pc = 0;//结束程序
				}
			}
		}

		/* 改变pc值 */
		pc += 4;
		getchar();
	}//pc=0，循环结束，程序结束

	//#ifdef DEGUB

	//#endif

	/* free */
	free(ireg_base);
	free(mem_base);
	free(freg_base);

	return 0;
} /* main */


