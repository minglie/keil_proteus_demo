#include <AT89X52.H>
#include "Function.h"
#include "Main_Constant.h"
#include "ucos.h"

/*
*********************************************************************************************************
*********************************************************************************************************
* File : main.c
* By : Minglie
* Date :
*********************************************************************************************************
*/

void main()
{
    mcu_init();
    while (1)
    {
        tm0_counter();
        //此if语句最长周期不能超过800us,否则可能通信错误
        if (bt.one.ms1_s)
        {
            if (system_step++ >= 5)
                system_step = 0;
            if (system_step == 0)
            {
                get_keystatus();
            }
            else if (system_step == 1)
            {
                key_serve();
            }
            bt.one.ms1_s = 0;
        }
    }
}




void test(){
    while (1)
    {
       delay_us(10);
    }
}




















//串口接收中断函数
// void serial() interrupt 4 using 3
// {
//     if (RI)
//     {
//         unsigned char ch;
//         RI = 0;
//         ch = SBUF;
//         usart_rx_buf[usart_rx_count] = ch;
//         usart_rx_count++;
//         if (usart_rx_count == 1)
//         {
//             usart_rx_count = 0;
//             bt.one.rx_f = 1;
//             usart_send_string(usart_rx_buf, 1);
//             //	 usart_send_char(0x55);
//         }
//     }
// }
