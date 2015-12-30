/*
*文件：mem.h
*功能：完成内存、寄存器声明；
*
*
*注意事项：
*/
#ifndef MEM
#define MEM
/* 主存、寄存器指针声明 */
extern char *mem_base;//主存的起始地址，动态分配在堆里
extern unsigned mem_size;

extern int* ireg_base;//整数寄存器的起始地址
extern unsigned ireg_size;

extern float* freg_base;//浮点寄存器的起始地址
extern unsigned freg_size;

//这是一个声明，包含这个文件，就已经把这一段声明复制过去了
//只不过定义在main函数里面
//main里面包含了也无所谓，声明可以有多个，定义只能有一个


/* 内存操作函数声明 */                                  //还有各种类型的读写可以做
void mem_uint_write(unsigned operand, int addr);//内存和寄存器在逻辑上最大的区别应该就是内存的数据类型相当丰富
unsigned mem_uint_read(int addr);				 //而MIPS似乎并没有CISC那样的AH、AX可以访问
void mem_int_write(int operand, int addr);
int mem_int_read(int addr);
unsigned mem_uint_read(int addr);
void mem_uint_write(unsigned operand, int addr);
unsigned char mem_ubyte_read(int addr);
void mem_ubyte_write(unsigned char operand, int addr);

/* 寄存器操作函数声明 */
void reg_int_write(int operand, int addr);
int reg_int_read(int addr);
void reg_uint_write(unsigned operand, int addr);
unsigned reg_uint_read(int addr);
void reg_float_write(float operand, int addr);
float reg_float_read(int addr);
void reg_double_write(double operand, int addr);
double reg_double_read(int addr);
#endif