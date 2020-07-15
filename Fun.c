/*
 * Fun.c
 *
 *  Created on: Jul 15, 2020
 *      Author: Empire
 */

#include "Fun.h"

typedef struct
	{
		u8 Periodicety ;
		void (*Fptr)(void) ;
	}Task;

	Task arr[NumOfTasks] ;

	extern u8 TickCount  ;
void TIMER0_Init(void)
{
	//choose timer0 ctc mode
		CLEAR_BIT(TCCR0 ,WGM00) ;
		SET_BIT(TCCR0 ,WGM01) ;

		//1 msec period for ISR
		SET_REGISTER_VALUE(OCR0 ,11) ;

		//enable global and timer0 interrupt
		SET_BIT(SREG,SREG_I) ;
		SET_BIT(TIMSK,OCIE0) ;

		//choose 1024 prescaler
		SET_BIT(TCCR0 ,CS00) ;
		CLEAR_BIT(TCCR0 ,CS01) ;
		SET_BIT(TCCR0 ,CS02) ;
}

void Red_Led(void)
{
	Dio_SetPinDirection(PHYSICAL_PORTA_BASE_ADDRESS ,PIN_0 ,OUTPUT_DIRECTION) ;
	TOGGLE_BIT(*(u8*)PHYSICAL_PORTA_BASE_ADDRESS ,PIN_0) ;
}

void Yellow_Led(void)
{
	Dio_SetPinDirection(PHYSICAL_PORTA_BASE_ADDRESS ,PIN_1 ,OUTPUT_DIRECTION) ;
	TOGGLE_BIT(*(u8*)PHYSICAL_PORTA_BASE_ADDRESS ,PIN_1) ;
}

void Green_Led(void)
{
	Dio_SetPinDirection(PHYSICAL_PORTA_BASE_ADDRESS ,PIN_2 ,OUTPUT_DIRECTION) ;
	TOGGLE_BIT(*(u8*)PHYSICAL_PORTA_BASE_ADDRESS ,PIN_2) ;
}

void Stepper(void)
{
	static u8 Pin =0 ;
	Dio_SetPinDirection(PHYSICAL_PORTB_BASE_ADDRESS ,PIN_0 ,OUTPUT_DIRECTION) ;
	Dio_SetPinDirection(PHYSICAL_PORTB_BASE_ADDRESS ,PIN_1 ,OUTPUT_DIRECTION) ;
	Dio_SetPinDirection(PHYSICAL_PORTB_BASE_ADDRESS ,PIN_2 ,OUTPUT_DIRECTION) ;
	Dio_SetPinDirection(PHYSICAL_PORTB_BASE_ADDRESS ,PIN_3 ,OUTPUT_DIRECTION) ;

	Dio_WritePin(PHYSICAL_PORTB_BASE_ADDRESS ,PIN_0 ,LOW_LEVEL) ;
	Dio_WritePin(PHYSICAL_PORTB_BASE_ADDRESS ,PIN_1 ,LOW_LEVEL) ;
	Dio_WritePin(PHYSICAL_PORTB_BASE_ADDRESS ,PIN_2 ,LOW_LEVEL) ;
	Dio_WritePin(PHYSICAL_PORTB_BASE_ADDRESS ,PIN_3 ,LOW_LEVEL) ;

	Dio_WritePin(PHYSICAL_PORTB_BASE_ADDRESS ,Pin ,HIGH_LEVEL) ;
	Pin++ ;
	Pin%=4 ;
}

void Lcd_Shift(void)
{
	static u8 lcdsize=0 ;
	Lcd_Send_Command(0x1c) ;
	lcdsize++ ;
	if(lcdsize==15)
	{
      lcdsize=0 ;
	// return home
	  Lcd_Send_Command(0x02) ;
	}
}

void Schedule(void)
		{
		    u8 i ;
			for(i=0 ;i<NumOfTasks ;i++)
			{
	            if((TickCount%arr[i].Periodicety)==0)
	            {
	            	arr[i].Fptr() ;
	            }
	            else
	            {

	            }
			}
		}


void TaskCreation(u8 Priority ,u8 Periodicety ,void (*Fp)(void))
	{
		arr[Priority].Periodicety = Periodicety ;
		arr[Priority].Fptr = Fp ;
	}

ISR(TIMER0_COMP_vect)
{
	TickCount ++ ;
	Schedule() ;
}


