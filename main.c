/*
 * main.c
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */

#include "Fun.h"


#define NumOfTasks 5


u8 TickCount =0 ;

void main(void)
{
	TIMER0_Init() ;

	Lcd_Init() ;
	Lcd_SendString("MOHAMED") ;

	TaskCreation(0 ,5 ,Red_Led) ;
	TaskCreation(1 ,10 ,Yellow_Led) ;
	TaskCreation(2 ,20 ,Green_Led) ;
	TaskCreation(3 ,5 ,Stepper) ;
	TaskCreation(4 ,100 ,Lcd_Shift) ;


while(1) ;
}
