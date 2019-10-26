/*
*********************************************************************************************************
*********************************************************************************************************
* File : ucos.c
* By : Minglie
* Date :
*********************************************************************************************************
*/
#include<AT89X52.H>
#include "Main_Constant.h"
#include "ucos.h"

void os_init()
{

	
}


void task0()
{
	if (task[OSTCBCur].one.rdy)
	{
		switch (task[OSTCBCur].step)
		{
			case 0: {
				//初始化发送，并发送起始位1ms
				TASK0_PORT = 0;
				OSTimeDly(7);
				task[OSTCBCur].step = 1;
				break;
			}
			case 1: {//拉高延时1ms准备发送数据
				TASK0_PORT = 1;
				OSTimeDly(7);
				task[OSTCBCur].step = 0;
				break;
			}
	}	
}
}
