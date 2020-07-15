/*
 * Macros.h
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */

#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(var,bitposition)  var|=(1<<bitposition)   //set bit in register to be 1
#define CLEAR_BIT(var,bitposition)  var&= ~(1<<bitposition) // clear bit value to be 0
#define TOGGLE_BIT(var,bitposition)  var^=(1<<bitposition)// change the recent value for the bit
#define SET_REGISTER(var)  var=0xff// set all bits of register to be 1
#define CLEAR_REGISTER(var) var=0x00// clear all bits of register to be 0
#define SET_REGISTER_VALUE(var,value)   var=value
#define GET_REGISTER(var)   var
#define GET_BIT(var,bitposition)  (var&(1<<bitposition))>>bitposition// check the current value of the bit
#define Bit_Is_Clear(REG,BIT) (!(REG & (1<<BIT)))

#endif /* MACROS_H_ */
