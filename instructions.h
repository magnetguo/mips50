/*
*文件：instructions.h
*功能：完成指令函数的声明；
*
*
*注意事项：
*/
#ifndef _H_INSTRUCTIONS
#define _H_INSTRUCTIONS

//#ifndef ID
//#include "id.h"
//#endif
//不是这么用的！

//#ifndef ID
//#include "mem.h"
//#endif
#include <stdio.h>
#include "mem.h"

/* 译码变量声明，外部定义的全局变量 */
extern unsigned op;//操作码
extern unsigned rs1;//源寄存器1
extern unsigned rs2;//源寄存器2
extern unsigned rd;//目的寄存器
extern unsigned func;//R功能
extern unsigned imme_u;//无符号扩展立即数
extern int imme_i;//有符号扩展立即数
extern int offset;//地址偏移量

/* 外部声明 */
extern unsigned pc;
extern int FPS;

/* 指令函数声明 */
/** I型整数指令，16条 */
void instr_ADDI();
void instr_ADDUI();
void instr_NOP();
void instr_BEQZ();
void instr_BNEZ();
void instr_ORI();
void instr_LB();
void instr_SB();
void instr_LW();
void instr_SW();
void instr_LHI();
void instr_SLLI();
void instr_SRAI();
void instr_SRLI();
void instr_XORI();
void instr_MULI();

/** R型整数指令，17条 */
void instr_ADDU();
void instr_ADD();
void instr_AND();
void instr_MOD();
void instr_MODU();
void instr_OR();
void instr_SEQ();
void instr_SEQU();
void instr_SLL();
void instr_SRA();
void instr_SRL();
void instr_MUL();
void instr_DIVP();
void instr_DIV();
void instr_DIVU();
void instr_MULT();
void instr_MULTU();

/** J型指令，1条 */
void instr_J();

/** R型浮点指令，16条 */
void instr_ADDF();
void instr_ADDD();
void instr_DIVD();
void instr_DIVF();
void instr_CVTD2F();
void instr_CVTD2I();
void instr_GTD();
void instr_GTF();
void instr_MOVD();
void instr_MOVF();
void instr_MOVFP2I();
void instr_MOVI2FP();
void instr_MOVI2S();
void instr_MOVS2I();
void instr_NEGF();
void instr_NEGD();
#endif