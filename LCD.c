/*
 * LCD.c
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */

#include "LCD.h"

// following data sheet for LCD 2x16
void Lcd_Init(void)
{
	Dio_SetPortDirection((u8*)PHYSICAL_PORTC_BASE_ADDRESS ,OUTPUT_DIRECTION) ;  //D0 TO D7

	Dio_SetPinDirection((u8*)PHYSICAL_PORTD_BASE_ADDRESS ,PIN_0 ,OUTPUT_DIRECTION) ; //RS
	Dio_SetPinDirection((u8*)PHYSICAL_PORTD_BASE_ADDRESS ,PIN_1 ,OUTPUT_DIRECTION) ; //RW
	Dio_SetPinDirection((u8*)PHYSICAL_PORTD_BASE_ADDRESS ,PIN_2 ,OUTPUT_DIRECTION) ; //E

   _delay_ms(50) ;
   //DISPLAY ON ,CURSOR OFF ,BLINKING OFF
   Lcd_Send_Command(0x0c) ;
   _delay_ms(2) ;
   //8 BIT MODE ,2 LINES ,5X7 DOT
   Lcd_Send_Command(0X38) ;
   _delay_ms(2) ;
   //display clear
   Lcd_Send_Command(0x01) ;
   _delay_ms(2) ;
   //incrementnt AC register after write
   Lcd_Send_Command(0x06) ;
   _delay_ms(2) ;

}

void Lcd_SendChar(u8 chardata)
{
	//select data register (RS)
 Dio_WritePin((u8*)PHYSICAL_PORTD_BASE_ADDRESS ,PIN_0 ,HIGH_LEVEL) ;
    //select write operation (RW)
 Dio_WritePin((u8*)PHYSICAL_PORTD_BASE_ADDRESS ,PIN_1 ,LOW_LEVEL) ;
   //write data on PORTC
 Dio_WritePortValue((u8*)PHYSICAL_PORTC_BASE_ADDRESS,chardata) ;
  //Activate E pin
 Dio_WritePin((u8*)PHYSICAL_PORTD_BASE_ADDRESS ,PIN_2 ,HIGH_LEVEL) ;
 _delay_ms(2) ;
 //Deactivate E pin
 Dio_WritePin((u8*)PHYSICAL_PORTD_BASE_ADDRESS ,PIN_2 ,LOW_LEVEL) ;
}

void Lcd_SendString(u8 *StringPtr)  //or (u8 stringptr[])
{
  while (*StringPtr!=0)
  {
	  Lcd_SendChar(*StringPtr) ; //Lcd_SendChar does rs ,rw ,e
	  StringPtr ++ ;
  }
}

void Lcd_Send_Command(u8 CommandData)
{
	//select instruction register (RS)
 Dio_WritePin((u8*)PHYSICAL_PORTD_BASE_ADDRESS ,PIN_0 ,LOW_LEVEL) ;
    //select write operation (RW)
 Dio_WritePin((u8*)PHYSICAL_PORTD_BASE_ADDRESS ,PIN_1 ,LOW_LEVEL) ;
   //write command on PORTC
 Dio_WritePortValue((u8*)PHYSICAL_PORTC_BASE_ADDRESS,CommandData) ;
  //Activate E pin
 Dio_WritePin((u8*)PHYSICAL_PORTD_BASE_ADDRESS ,PIN_2 ,HIGH_LEVEL) ;
 _delay_ms(2) ;
 //Deactivate E pin
 Dio_WritePin((u8*)PHYSICAL_PORTD_BASE_ADDRESS ,PIN_2 ,LOW_LEVEL) ;
}
void Gotoxy (u8 Y,u8 X)
{
	if (X>0 && X<=16)
	{
	    switch(Y)
	    {
		    case 1:
		    	Lcd_Send_Command(X+127);
		    break;
		    case 2:
		    	Lcd_Send_Command(X+191);
		    break;
		    default:
		    break;
	    }
	}
}

