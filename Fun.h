/*
 * Fun.h
 *
 *  Created on: Jul 15, 2020
 *      Author: Empire
 */

#ifndef FUN_H_
#define FUN_H_

#include "Macros.h""
#include "Types.h"
#include "AVR_con.h"
#include "DIO.h"
#include "LCD.h"


#define NumOfTasks 5

void TIMER0_Init(void) ;
void Red_Led(void) ;
void Yellow_Led(void) ;
void Green_Led(void) ;
void Stepper(void) ;
void Lcd_Shift(void) ;
void Schedule(void) ;
void TaskCreation(u8 Priority ,u8 Periodicety ,void (*Fp)(void));

#endif /* FUN_H_ */
