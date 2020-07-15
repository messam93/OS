/*
 * LCD.h
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */

#ifndef LCD_H_
#define LCD_H_

#include "Dio.h"
#include "Macros.h"
#include "AVR_con.h"
#include "Types.h"
void Lcd_Init(void);
void Lcd_SendChar(u8 chardata);
void Lcd_SendString(u8 *StringPtr);
void Curser (u8 Y,u8 X);
void Lcd_Send_Command(u8 CommandData);

#endif /* LCD_H_ */
