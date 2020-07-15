/*
 * DIO.h
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */

#ifndef DIO_H_
#define DIO_H_
#include "Types.h"
#include "Macros.h"
#include "avr/io.h"

#define OUTPUT_DIRECTION 1
#define INPUT_DIRECTION 0

#define PORT_OFFSET 0
#define DDR_OFFSET 1
#define PIN_OFFSET 2

#define HIGH_LEVEL  1
#define LOW_LEVEL   0

#define PHYSICAL_PORTA_BASE_ADDRESS  0x3B
#define PHYSICAL_PORTB_BASE_ADDRESS  0x38
#define PHYSICAL_PORTC_BASE_ADDRESS  0x35
#define PHYSICAL_PORTD_BASE_ADDRESS  0x32

#define PIN_0  0
#define PIN_1  1
#define PIN_2  2
#define PIN_3  3
#define PIN_4  4
#define PIN_5  5
#define PIN_6  6
#define PIN_7  7

void Dio_SetPinDirection(u8 *PhysicalPortBaseAddressPtr, u8 PinPosition, u8 PinDirection);

void Dio_WritePin(u8 *PhysicalPortBaseAddressPtr, u8 PinPosition, u8 PinLevel);

u8 Dio_ReadPIN(u8 *PhysicalPortBaseAddressPtr, u8 PinPosition );   //u8 Dio_ReadPIN(u8 PhysicalPortBaseAddressPtr, u8 PinPosition );
                                                                   //if used volatile

void Dio_SetPortDirection(u8 *PhysicalPortBaseAddressPtr, u8 PortDirection) ;

void Dio_WritePortValue(u8 *PhysicalPortBaseAddressPtr ,u8 Value) ;

u8 Dio_ReadPort(u8 *PhysicalPortBaseAddressPtr) ;

void Dio_ActivatePinPullUpResistor(u8 *PhysicalPortBaseAddressPtr ,u8 PinPosition ) ;

void Dio_ActivatePortPullUpRegister(u8 *PhPhysicalPortBaseAddressPtr) ;
void Extrenal_interrupt(u8 Pin);



#endif /* DIO_H_ */
