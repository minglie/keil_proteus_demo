/*
*********************************************************************************************************
*********************************************************************************************************
* File : Main_constant.h
* By : Minglie
* Date :
*********************************************************************************************************
*/


#ifndef __Main_Constant_H
#define __Main_Constant_H


#define CON_TIME_TM0 1000//设置定时器0的计时长度
#define CON_TH0 (65536-CON_TIME_TM0)/256//计算定时器0高8位装入值
#define CON_TL0 (65536-CON_TIME_TM0)%256 //计算定时器0低8位装入值





#define TASK0_PORT P1_0
#define TASK1_PORT P1_1
#define TASK2_PORT P1_1




//----------------------------global variable define---------------------------------------------------
#ifdef OS_GLOBALS
#define OS_EXT
#else
#define OS_EXT extern
#endif

typedef union
{
	struct
	{
		unsigned low : 4;
		unsigned up : 4;

	}half;
	struct
	{
		unsigned b0 : 1;
		unsigned b1 : 1;
		unsigned b2 : 1;
		unsigned b3 : 1;
		unsigned b4 : 1;
		unsigned b5 : 1;
		unsigned b6 : 1;
		unsigned b7 : 1;
	}one;
	unsigned char all;
}CHAR_TypeDef;


typedef union
{
	struct
	{
		unsigned low_vol_num_b210 : 3; //低包电压值
		unsigned up_vol_num_b543 : 3; //高包电压值
		unsigned charge_b6 : 1; //充电器插入标志
		unsigned bat_low_up_b7 : 1; //当前正在充电的包，0为下，1为上
	}one;
	unsigned char all;
} ptl_rx_stack_TypeDef;

typedef struct
{
	struct struct_tcb
	{
		unsigned rdy : 1;
		unsigned enable : 1;
	}one;
	unsigned char delay;
	unsigned char step;
}OSTCB_TypeDef;


OS_EXT volatile union bits_decompound //announce a union save special bits
{
	struct struct0
	{
		unsigned ms1_s : 1; //
		unsigned ms5_s : 1; //5ms timer sign bit
		unsigned rx_f : 1; //串口收到数据标志
	}one;
	unsigned char all[2];
}bt;


OS_EXT unsigned char usart_rx_buf[1];
OS_EXT unsigned char usart_rx_count;


OS_EXT unsigned char system_counter;
OS_EXT unsigned char system_step;

#endif