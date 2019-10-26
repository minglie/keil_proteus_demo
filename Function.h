/*
*********************************************************************************************************
*********************************************************************************************************
* File : Function.h
* By : Minglie
* Date :
*********************************************************************************************************
*/

/* Function header file, all the function be used in program */

#ifndef __Function_H
#define __Function_H
//-------------------Main and Common Subprogram routine-----
void mcu_init();
void variable_init();
void tm0_init();
void usart_init();
void tm0_counter(); 
void peripheral_init();
void usart_send_char(unsigned char ch);
void usart_send_string(unsigned char *str,unsigned int strlen);
void get_keystatus();
void delay_us(unsigned int t);
void key_serve();
#endif
