/*
*********************************************************************************************************
*********************************************************************************************************
* File : ucos.h
* By : Minglie
* Date :
*********************************************************************************************************
*/

#ifndef __Ucos_H
#define __Ucos_H


#include "Main_Constant.h"

void os_init();
void task0(void);


#define OSTCBCur 0
#define OSTimeDly(k) {task[OSTCBCur].one.rdy =0; task[OSTCBCur].delay =k-1; }

#define OSTimeTick()\
{\
if(task[0].delay ==0) task[0].one.rdy=1;\
else task[0].delay --;\
task0();\
}\

#define config_max_tasks 1 //最大任务个数
OS_EXT OSTCB_TypeDef task[config_max_tasks];

#endif



