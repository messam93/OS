/*
 * DIO.c
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */

#include "DIO.h"



void Dio_SetPinDirection(u8 *PhysicalPortBaseAddressPtr, u8 PinPosition, u8 PinDirection)
{
	if(PinDirection==OUTPUT_DIRECTION)
	{
		SET_BIT(*(PhysicalPortBaseAddressPtr - DDR_OFFSET),PinPosition) ;
	}
	else if(PinDirection==INPUT_DIRECTION)
	{
		CLEAR_BIT(*(PhysicalPortBaseAddressPtr - DDR_OFFSET),PinPosition) ;
	}
}

void Dio_WritePin(u8 *PhysicalPortBaseAddressPtr, u8 PinPosition, u8 PinLevel)
{
	   if(PinLevel==HIGH_LEVEL)
		{
			SET_BIT(*(PhysicalPortBaseAddressPtr - PORT_OFFSET),PinPosition) ;
		}
		else if(PinLevel==LOW_LEVEL)
		{
			CLEAR_BIT(*(PhysicalPortBaseAddressPtr - PORT_OFFSET),PinPosition) ;
		}
}

u8 Dio_ReadPIN(u8 *PhysicalPortBaseAddressPtr, u8 PinPosition )                    //u8 Dio_ReadPIN(u8 PhysicalPortBaseAddressPtr,u8 PinPosition )
{                                                                                   // {
                                                                                    // return GET_BIT(*(volatile u8*)(PhysicalPortBaseAddressPtr - PIN_OFFSET),PinPosition) ;
	                                                                                  //  }
      return GET_BIT(*(PhysicalPortBaseAddressPtr - PIN_OFFSET),PinPosition) ;
}

void Dio_SetPortDirection(u8 *PhysicalPortBaseAddressPtr, u8 PortDirection)
{
	if (PortDirection==OUTPUT_DIRECTION)
	{
		SET_REGISTER(*(PhysicalPortBaseAddressPtr-DDR_OFFSET)) ;
	}
	else if(PortDirection==INPUT_DIRECTION)
	{
		CLEAR_REGISTER(*(PhysicalPortBaseAddressPtr-DDR_OFFSET)) ;
	}
}

void Dio_WritePortValue(u8 *PhysicalPortBaseAddressPtr ,u8 Value)
{
	SET_REGISTER_VALUE(*(PhysicalPortBaseAddressPtr-PORT_OFFSET),Value) ;
}

u8 Dio_ReadPort(u8 *PhysicalPortBaseAddressPtr)
{
	return (GET_REGISTER(*(PhysicalPortBaseAddressPtr-PIN_OFFSET))) ;
}

void Dio_ActivatePinPullUpResistor(u8 *PhysicalPortBaseAddressPtr ,u8 PinPosition )
{
	SET_BIT(*(PhysicalPortBaseAddressPtr-PORT_OFFSET),PinPosition) ;
}

void Dio_ActivatePortPullUpResistor(u8 *PhysicalPortBaseAddressPtr)
{
	SET_REGISTER(*(PhysicalPortBaseAddressPtr-PORT_OFFSET)) ;
}
void Extrenal_interrupt(u8 Pin)
{
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	SET_BIT(GICR,Pin);
	SET_BIT(SREG,SREG_I);
}


