/*
*文件：instructions.c
*功能：完成指令函数的定义；
*
*
*注意事项：
*/
#include "instructions.h"

/* 指令函数实现 */
void instr_ADDI() {
	/* 读入操作数 */
	int operand0 = reg_int_read(rs1);

	/* 执行 */
	int result =  operand0 + imme_i;

	/* 写回 */
	reg_int_write(result ,rs2); 

	/* 显示命令 */
	printf("ADDI R%d R%d %d\n", rs2, rs1, imme_u);
	printf("(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, result);

}

void instr_ADDU() {
	/* 读入操作数 */
	unsigned int operand0 = reg_uint_read(rs1);
	unsigned int operand1 = reg_uint_read(rs2);

	/* 执行 */
	unsigned int result =  operand0 + operand1;

	/* 写回 */
	reg_uint_write(result ,rd); 

	/* 显示命令 */
	printf("ADDU R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%d,(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, result);

}

void instr_ADDUI() {
	/* 读入操作数 */
	unsigned int operand0 = reg_uint_read(rs1);

	/* 执行 */
	unsigned int result =  operand0 + imme_u;

	/* 写回 */
	reg_uint_write(result ,rs2); 

	/* 显示命令 */
	printf("ADDUI R%d R%d %d\n", rs2, rs1, imme_u);
	printf("(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, result);

}

void instr_ORI() {
	/* 读入操作数 */
	unsigned int operand0 = reg_uint_read(rs1);

	/* 执行 */
	unsigned int result =  operand0 | imme_u;

	/* 写回 */
	reg_uint_write(result ,rs2); 

	/* 显示命令 */
	printf("ORI R%d R%d %d\n", rs2, rs1, imme_u);
	printf("(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, result);
}

void instr_XORI() {
	/* 读入操作数 */
	unsigned int operand0 = reg_uint_read(rs1);

	/* 执行 */
	unsigned int result =  operand0 ^ imme_u;

	/* 写回 */
	reg_uint_write(result ,rs2); 

	/* 显示命令 */
	printf("XORI R%d R%d %d\n", rs2, rs1, imme_u);
	printf("(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, result);
}

void instr_LHI() {

	/* 执行 */
	unsigned int result =  imme_u << 16;

	/* 写回 */
	reg_uint_write(result ,rs2); 

	/* 显示命令 */
	printf("LHI R%d %d\n", rs2, imme_u);
	printf("(R%d)=%d\n", rs2, result);
}

void instr_SLLI() {
	/* 读入操作数 */
	unsigned int operand0 = reg_uint_read(rs1);

	/* 执行 */
	unsigned int result =  operand0 << imme_u;

	/* 写回 */
	reg_uint_write(result ,rs2); 

	/* 显示命令 */
	printf("SLLI R%d R%d %d\n", rs2, rs1, imme_u);
	printf("(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, result);
}

void instr_SRLI() {
	/* 读入操作数 */
	unsigned int operand0 = reg_uint_read(rs1);

	/* 执行 */
	unsigned int result =  operand0 >> imme_u;

	/* 写回 */
	reg_uint_write(result ,rs2); 

	/* 显示命令 */
	printf("SLLI R%d R%d %d\n", rs2, rs1, imme_u);
	printf("(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, result);
}

void instr_SRAI() {
	/* 读入操作数 */
	int operand0 = reg_int_read(rs1);

	/* 执行 */
	int result =  operand0 >> imme_u;

	/* 写回 */
	reg_int_write(result ,rs2); 

	/* 显示命令 */
	printf("SRAI R%d R%d %d\n", rs2, rs1, imme_u);
	printf("(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, result);
}

void instr_MULI() {
	/* 读入操作数 */
	int operand0 = reg_int_read(rs1);

	/* 执行 */
	int result =  operand0 * imme_i;

	/* 写回 */
	reg_int_write(result ,rs2); 

	/* 显示命令 */
	printf("MULI R%d R%d %d\n", rs2, rs1, imme_i);
	printf("(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, result);
}

void instr_ADD() {
	/* 读入操作数 */
	int operand0 = reg_int_read(rs1);
	int operand1 = reg_int_read(rs2);

	/* 执行 */
	int result =  operand0 + operand1;

	/* 写回 */
	reg_int_write(result ,rd); 

	/* 显示命令 */
	printf("ADD R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%d,(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, result);

}

void instr_J() {
	//printf("offset: %08X\n", offset);
	/* 执行 */
	printf("J %d\n", offset);

	/* 改变pc */
	pc += offset*4-4;
}

void instr_LW() {
	/* 读入操作数 */
	int operand0 = reg_int_read(rs1);

	/* 执行 */
	int addr = operand0 + imme_i;//计算地址
	int result = mem_int_read(addr);

	/* 写回 */
	reg_int_write(result, rs2);

	/* 显示命令 */
	printf("LW R%d (%d)R%d\n", rs2, imme_i, rs1);
	printf("the loaded is:%d\n", result);

	
}

void instr_SW() {
	/* 读入操作数 */
	int operand0 = reg_int_read(rs1);
	int operand1 = reg_int_read(rs2);

	/* 执行 */
	int addr = operand0 + imme_i;//计算地址
	mem_int_write(operand1, addr);//写回

	/* 显示命令 */
	printf("SW (%d)R%d R%d\n", imme_i, rs1, rs2);
	printf("the stored is: %d\n", operand1);

}

void instr_LB() {
	/* 读入操作数 */
	int operand0 = reg_int_read(rs1);

	/* 执行 */
	int addr = operand0 + imme_i;//计算地址
	int result = (int)mem_ubyte_read(addr);

	/* 写回 */
	reg_int_write(result, rs2);

	/* 显示命令 */
	printf("LB R%d (%d)R%d\n", rs2, imme_i, rs1);
	printf("the loaded is:%d\n", result);
}

void instr_SB() {
	/* 读入操作数 */
	//为什么没有SBH，可能就是存的时候都是物理存储，不需要认识
	int operand0 = reg_int_read(rs1);
	//unsigned char operand1 = reg_int_read(rs2);
	//不行，会改变物理数值
	int operand1 = reg_int_read(rs2);

	/* 执行 */
	int addr = operand0 + imme_i;//计算地址
	mem_ubyte_write((unsigned char)operand1, addr);//写回

	/* 显示命令 */
	printf("SB (%d)R%d R%d\n", imme_i, rs1, rs2);
	printf("the stored is: %d\n", operand1);

}

void instr_AND() {
	/* 读入操作数 */
	unsigned int operand0 = reg_uint_read(rs1);
	unsigned int operand1 = reg_uint_read(rs2);

	/* 执行 */
	unsigned int result =  operand0 & operand1;

	/* 写回 */
	reg_uint_write(result ,rd); 

	/* 显示命令 */
	printf("AND R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%d,(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, result);

}

void instr_MOD() {
	/* 读入操作数 */
	int operand0 = reg_int_read(rs1);
	int operand1 = reg_int_read(rs2);

	/* 执行 */
	int result =  operand0 % operand1;

	/* 写回 */
	reg_int_write(result ,rd); 

	/* 显示命令 */
	printf("MOD R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%d,(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, result);

}

void instr_MODU() {
	/* 读入操作数 */
	unsigned int operand0 = reg_uint_read(rs1);
	unsigned int operand1 = reg_uint_read(rs2);

	/* 执行 */
	unsigned int result =  operand0 % operand1;

	/* 写回 */
	reg_uint_write(result ,rd); 

	/* 显示命令 */
	printf("MODU R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%d,(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, result);

}

void instr_OR() {
	/* 读入操作数 */
	unsigned int operand0 = reg_uint_read(rs1);
	unsigned int operand1 = reg_uint_read(rs2);

	/* 执行 */
	unsigned int result =  operand0 | operand1;

	/* 写回 */
	reg_uint_write(result ,rd); 

	/* 显示命令 */
	printf("OR R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%d,(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, result);

}

void instr_SEQ() {
	/* 读入操作数 */
	int operand0 = reg_int_read(rs1);
	int operand1 = reg_int_read(rs2);

	/* 执行 */
	int result =  operand0 == operand1;

	/* 写回 */
	reg_int_write(result ,rd); 

	/* 显示命令 */
	printf("SEQ R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%d,(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, result);

}

void instr_SEQU() {
	/* 读入操作数 */
	unsigned int operand0 = reg_uint_read(rs1);
	unsigned int operand1 = reg_uint_read(rs2);

	/* 执行 */
	int result =  operand0 == operand1;

	/* 写回 */
	reg_uint_write(result ,rd); 

	/* 显示命令 */
	printf("SEQU R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%d,(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, result);

}

void instr_SLL() {
	/* 读入操作数 */
	unsigned int operand0 = reg_uint_read(rs1);
	unsigned int operand1 = reg_uint_read(rs2);

	/* 执行 */
	unsigned int result =  operand0 << operand1;

	/* 写回 */
	reg_uint_write(result ,rd); 

	/* 显示命令 */
	printf("SLL R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%d,(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, result);


}

void instr_SRA() {
	/* 读入操作数 */
	int operand0 = reg_int_read(rs1);
	int operand1 = reg_int_read(rs2);

	/* 执行 */
	int result =  operand0 >> operand1;

	/* 写回 */
	reg_int_write(result ,rd); 

	/* 显示命令 */
	printf("SRA R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%d,(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, result);


}

void instr_SRL() {
	/* 读入操作数 */
	unsigned int operand0 = reg_uint_read(rs1);
	unsigned int operand1 = reg_uint_read(rs2);

	/* 执行 */
	unsigned int result =  operand0 >> operand1;

	/* 写回 */
	reg_uint_write(result ,rd); 

	/* 显示命令 */
	printf("SRL R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%d,(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, result);


}

void instr_MUL() {
	/* 读入操作数 */
	int operand0 = reg_int_read(rs1);
	int operand1 = reg_int_read(rs2);

	/* 执行 */
	int result =  operand0 * operand1;

	/* 写回 */
	reg_int_write(result ,rd); 

	/* 显示命令 */
	printf("MUL R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%d,(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, result);


}

void instr_DIVP() {
	/* 读入操作数 */
	int operand0 = reg_int_read(rs1);
	int operand1 = reg_int_read(rs2);

	/* 执行 */
	int result =  operand0 / operand1;

	/* 写回 */
	reg_int_write(result ,rd); 

	/* 显示命令 */
	printf("MUL R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%d,(R%d)=%d,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, result);

}

//区别在于读入数据和输出数据是整型的，中间转换成浮点运算
void instr_DIV() {
	/* 读入操作数 */
	float operand0 = (float)reg_int_read(rs1);
	float operand1 = (float)reg_int_read(rs2);

	/* 执行 */
	float result =  operand0 / operand1;

	/* 写回 */
	reg_int_write((int)result ,rd); 

	/* 显示命令 */
	printf("DIV R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%f,(R%d)=%f,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, (int)result);
}

void instr_DIVU() {
	/* 读入操作数 */
	float operand0 = (float)reg_uint_read(rs1);
	float operand1 = (float)reg_uint_read(rs2);

	/* 执行 */
	float result =  operand0 / operand1;

	/* 写回 */
	reg_uint_write((unsigned int)result ,rd); 

	/* 显示命令 */
	printf("DIVU R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%f,(R%d)=%f,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, (unsigned int)result);
}

void instr_MULT() {
	/* 读入操作数 */
	float operand0 = (float)reg_int_read(rs1);
	float operand1 = (float)reg_int_read(rs2);

	/* 执行 */
	float result =  operand0 * operand1;

	/* 写回 */
	reg_int_write((int)result ,rd); 

	/* 显示命令 */
	printf("MULT R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%f,(R%d)=%f,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, (int)result);
}

void instr_MULTU() {
	/* 读入操作数 */
	float operand0 = (float)reg_uint_read(rs1);
	float operand1 = (float)reg_uint_read(rs2);

	/* 执行 */
	float result =  operand0 * operand1;

	/* 写回 */
	reg_uint_write((unsigned int)result ,rd); 

	/* 显示命令 */
	printf("DIVU R%d R%d R%d\n", rd, rs1, rs2);
	printf("(R%d)=%f,(R%d)=%f,(R%d)=%d\n", rs1, operand0, rs2, operand1, rd, (unsigned int)result);
}

void instr_NOP() {

}

void instr_BEQZ() {
	/* 读入操作数 */
	int operand0 = reg_int_read(rs1);

	/* 执行 */
	int cond =  operand0 == 0;

	/* 显示命令 */
	printf("BEQZ R%d %d\n", rs1, imme_i);

	/* 改变pc */
	if (cond)
		pc += imme_i-4;
}

void instr_BNEZ() {
	/* 读入操作数 */
	int operand0 = reg_int_read(rs1);

	/* 执行 */
	int cond =  operand0 == 0;

	/* 显示命令 */
	printf("BEQZ R%d %d\n", rs1, imme_i);

	/* 改变pc */
	if (cond)
		pc += imme_i-4;
}

void instr_ADDD() {
	/* 读入操作数 */
	double operand0 = reg_double_read(rs1);
	double operand1 = reg_double_read(rs2);

	/* 执行 */
	double result =  operand0 + operand1;

	/* 写回 */
	reg_double_write(result ,rd); 

	/* 显示命令 */
	printf("ADDD F%d F%d F%d\n", rd, rs1, rs2);
	printf("(F%d)=%lf,(F%d)=%lf,(F%d)=%lf\n", rs1, operand0, rs2, operand1, rd, result);

}

void instr_ADDF() {
	/* 读入操作数 */
	float operand0 = reg_float_read(rs1);
	float operand1 = reg_float_read(rs2);

	/* 执行 */
	float result =  operand0 + operand1;

	/* 写回 */
	reg_float_write(result ,rd); 

	/* 显示命令 */
	printf("ADDF F%d F%d F%d\n", rd, rs1, rs2);
	printf("(F%d)=%f,(F%d)=%f,(F%d)=%f\n", rs1, operand0, rs2, operand1, rd, result);

}

void instr_DIVD() {
	/* 读入操作数 */
	double operand0 = reg_double_read(rs1);
	double operand1 = reg_double_read(rs2);

	/* 执行 */
	double result =  operand0 / operand1;

	/* 写回 */
	reg_double_write(result ,rd); 

	/* 显示命令 */
	printf("DIVD F%d F%d F%d\n", rd, rs1, rs2);
	printf("(F%d)=%lf,(F%d)=%lf,(F%d)=%lf\n", rs1, operand0, rs2, operand1, rd, result);

}

void instr_DIVF() {
	/* 读入操作数 */
	float operand0 = reg_float_read(rs1);
	float operand1 = reg_float_read(rs2);

	/* 执行 */
	float result =  operand0 / operand1;

	/* 写回 */
	reg_float_write(result ,rd); 

	/* 显示命令 */
	printf("DIVF F%d F%d F%d\n", rd, rs1, rs2);
	printf("(F%d)=%f,(F%d)=%f,(F%d)=%f\n", rs1, operand0, rs2, operand1, rd, result);

}

void instr_CVTD2F() {
	/* 读入操作数 */
	double operand0 = reg_double_read(rs1);

	/* 执行 */
	float result = (float)operand0;

	/* 写回 */
	reg_float_write(result ,rd); 

	/* 显示命令 */
	printf("CVTD2F F%d F%d\n", rd, rs1);
	printf("(F%d)=%lf,(F%d)=%f\n", rs1, operand0, rd, result);

}

void instr_CVTD2I() {
	/* 读入操作数 */
	double operand0 = reg_double_read(rs1);

	/* 执行 */
	int result = (int)operand0;
	//这里应该不是仅仅只有逻辑改变，数的物理存储肯定是改变的

	/* 写回 */
	reg_int_write(result ,rd); 

	/* 显示命令 */
	printf("CVTD2I F%d F%d\n", rd, rs1);
	printf("(F%d)=%lf,(F%d)=%d\n", rs1, operand0, rd, result);

}

void instr_GTD() {
	/* 读入操作数 */
	double operand0 = reg_double_read(rs1);
	double operand1 = reg_double_read(rs2);

	/* 执行 */
	FPS =  operand0 > operand1;

	/* 显示命令 */
	printf("GTD F%d F%d\n", rs1, rs2);
	printf("(F%d)=%lf,(F%d)=%lf,FPS=%d\n", rs1, operand0, rs2, operand1, FPS);

}

void instr_GTF() {
	/* 读入操作数 */
	float operand0 = reg_float_read(rs1);
	float operand1 = reg_float_read(rs2);

	/* 执行 */
	FPS =  operand0 > operand1;

	/* 显示命令 */
	printf("GTF F%d F%d\n", rs1, rs2);
	printf("(F%d)=%f,(F%d)=%f,FPS=%d\n", rs1, operand0, rs2, operand1, FPS);

}

void instr_MOVD() {
	/* 读入操作数 */
	double operand0 = reg_double_read(rs1);

	/* 写回 */
	reg_double_write(operand0, rd);

	/* 显示命令 */
	printf("MOVD F%d F%d\n", rd, rs1);
	printf("(F%d)=%lf,(F%d)=%lf\n", rs1, operand0, rd, operand0);
}

void instr_MOVF() {
	/* 读入操作数 */
	float operand0 = reg_float_read(rs1);

	/* 写回 */
	reg_float_write(operand0, rd);

	/* 显示命令 */
	printf("MOVF F%d F%d\n", rd, rs1);
	printf("(F%d)=%f,(F%d)=%f\n", rs1, operand0, rd, operand0);
}

void instr_MOVFP2I() {
	/* 读入操作数 */
	float operand0 = reg_float_read(rs1);

	/* 写回 */
	reg_int_write((int)operand0, rd);

	/* 显示命令 */
	printf("MOVFP2I R%d F%d\n", rd, rs1);
	printf("(F%d)=%f,(R%d)=%d\n", rs1, operand0, rd, (int)operand0);
}

void instr_MOVI2FP() {
	/* 读入操作数 */
	int operand0 = reg_int_read(rs1);

	/* 写回 */
	reg_float_write((float)operand0, rd);

	/* 显示命令 */
	printf("MOVI2FP F%d R%d\n", rd, rs1);
	printf("(R%d)=%d,(F%d)=%f\n", rs1, operand0, rd, (float)operand0);
}

void instr_MOVI2S() {
	/* 读入操作数 */
	int operand0 = reg_int_read(rs1);

	/* 写回 */
	FPS = operand0;

	/* 显示命令 */
	printf("MOVI2S R%d\n", rs1);
	printf("(R%d)=%d\n", rs1, operand0);
}

void instr_MOVS2I() {
	/* 写回 */
	reg_int_write(FPS ,rd);

	/* 显示命令 */
	printf("MOVS2I R%d\n", rd);
	printf("(R%d)=%d\n", rd, FPS);
}

void instr_NEGF() {
	/* 读入操作数 */
	//unsigned int operand0 = (unsigned int)reg_float_read(rs1);
	//必须从浮点寄存器转存到进来，不然源就错了
	//必须是地址操作，不然物理结构就错了！
	//只能够直接取负，地址操作不应该开放接口给他
	float operand0 = reg_float_read(rs1);
	
	/* 操作 */
	//unsigned int result = operand0 ^ 0x80000000;
	//按位异或，不应该是与，不然一直就是负的
	float result = 0.0 - operand0;
	//float result = operand0 ^ 0x80000000;

	/* 写回 */
	reg_float_write(result, rd);

	/* 显示命令 */
	printf("NEGF F%d F%d\n", rd, rs1);
	printf("(F%d)=%f, (F%d)=%f\n", rs1, operand0, rd, result);
}

void instr_NEGD() {
	/* 读入操作数 */
	double operand0 = reg_double_read(rs1);

	/* 操作 */
	//double result = operand0 ^ 0x8000000000000000;
	//不可以，不支持double的异或
	double result = 0.0 - operand0;

	/* 写回 */
	reg_double_write(result, rd);

	/* 显示命令 */
	printf("NEGD F%d F%d\n", rd, rs1);
	printf("(F%d)=%lf, (F%d)=%lf\n", rs1, operand0, rd, result);

}

