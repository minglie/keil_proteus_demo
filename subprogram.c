/*
*********************************************************************************************************
*********************************************************************************************************
* File : subprogram.c
* By : Minglie
* Date :
*********************************************************************************************************
*/

#define OS_GLOBALS
#include<AT89X52.H>
#include "Function.h"
#include "Main_Constant.h"
#include "ucos.h"




//--------------------Mcu pow-up initialize-----------------
void mcu_init()
{
	tm0_init();
	usart_init();
 
}

void variable_init()
{

}

void tm0_init(){
	TMOD |=0x01;
	TH0=CON_TH0;//装载定时器初始值
  TL0=CON_TL0;
	TR0 = 1; //打开定时器开关，开始定时
}

void usart_init()
{
	SCON=0X50;			//设置为工作方式1
	TMOD |=0X20;			//设置计数器工作方式2
	PCON=0X00;			//SMOD=0，32分频
	TH1=0Xfd;			//计数器初始值设置，注意波特率是9600的
	TL1=0Xfd;
	ES=1;				//打开接收中断
	EA=1;				//打开总中断
	TR1=1;				//打开计数器
}

//--------------------system counter rountine----------------------------------
void tm0_counter() //provide a 5ms clock signal for the system
{
	   if(TF0 == 1)
			{
					OSTimeTick();		
					bt.one.ms1_s=1;
					TF0 = 0;
					TH0=CON_TH0;//装载定时器初始值
					TL0=CON_TH0;
			}
}










void peripheral_init() // 初始化外围
{

	
	
}


void get_keystatus()
{
   delay_us(10);
}


void key_serve(){
   delay_us(10);
}

void delay_us(unsigned int t){
	   t=t*10;
    while(t--);
}


//向串口发送一个字符 
void usart_send_char(unsigned char ch)
{
    SBUF=ch;
    while(TI==0);
    TI=0;
}

//向串口发送一个字符串，strlen为该字符串长度 
void usart_send_string(unsigned char *str,unsigned int strlen)
{
    unsigned int k=0;
    do 
    {
        usart_send_char(*(str + k));
        k++;
    } while(k < strlen);
}

