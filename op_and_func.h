/*
*文件：op_and_func.h
*功能：完成操作码和func字段的声明；
*
*
*注意事项：
*/

/* 操作码 */
#ifndef OP_H
#define OP_H
enum Oper
{
	/* R型指令，Op为0 */
	OP_R, 

	/* I型指令 1-48 */
	/* ->整数指令 1-30 */
	ADDI, ADDUI, ANDI, MODI, MODUI, ORI, LHI, NOP, SLLI, SRAI, SRLI, 
	SUBI, SUBUI, XORI, MULI, MULUI, DIVPI, DIVPUI, SEQI, SEQUI, SGEI,
	SGEUI, SGTI, SGTUI, SLEI, SLEUI, SLTI, SLTUI, SNEI, SNEUI, 

	/* ->分支指令 31-36 */
	BEQZ, BNEZ, BFPF, BFPT, JR, JALR, 

	/* ->访存指令 37-48 */
	LB, LBU, LH, LHU, LW, LF, LD, SB, SH,
	SW, SF, SD,

	/* J型指令 49-52 */
	J, JAL, TRAP, RFE
} oper_val;

/* Func */
enum Func 
{
	/* ->整数操作 0-27 */
	ADD, ADDU, AND, MOD, MODU, OR, SEQ, SEQU, SGE, SGEU, SGT, SGTU,
	SLE, SLEU, SLT, SLTU, SNE, SNEU, SLL, SRA, SRL, SUB, SUBU, XOR,
	MUL, MULU, DIVP, DIVPU, 

	/* ->浮点操作 28-35 */
	ADDD, ADDF, DIVD, DIVF, MULTD, MULTF, SUBD, SUBF, 

	/* ->整数操作，但是目的寄存器为浮点寄存器，隐含类型转换 36-39 */
	DIV, DIVU, MULT, MULTU,

	/* ->浮点操作，一些转换和比较操作 40-57 */
	CVTD2F, CVTD2I, CVTF2D, CVTF2I, CVTI2D, CVTI2F,
	GTD, GTF, LED, LEF, EQD, EQF, GED, GEF, LTD, LTF,
	NED, NEF,

	/* ->数据移动 58-63 */
	MOVD, MOVF, MOVFP2I, MOVI2FP, MOVI2S, MOVS2I,

	/* ->浮点操作,取负 64-65 */
	NEGF, NEGD
} func_val;

//类似结构体，前面只是类型名字，后面才是变量名字
//还是，h定义，你也包含了，就可以用了
#endif



