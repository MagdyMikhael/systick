/*
 * utilites.h
 *
 * Created: 2/20/2018 10:15:13 PM
 *  Author: magdy
 */ 


#ifndef UTILITES_H_
#define UTILITES_H_

#define ASSIGN_BIT(reg,bit_no,value) reg=((~(1<<bit_no))&reg)|(value<<bit_no)
#define GET_BIT(reg,bits_no)  (reg &(1<<bits_no))>>bits_no
#define CLR_BIT(reg,bits_no)   reg &= ~(1<<bits_no)
#define SET_BIT(reg,bits_no)  reg|=(1<<bits_no)
#define SET_TWO_BITS(Reg,bitNum1,bitNum2) Reg=Reg|(1<<bitNum1)|(1<<bitNum2)
#define SET_THREE_BITS(Reg,bitNum1,bitNum2,bitNum3) Reg=Reg|(1<<bitNum1)|(1<<bitNum2)|(1<<bitNum3)
#define SET_FOUR_BITS(Reg,bitNum1,bitNum2,bitNum3,bitNum4) Reg=Reg|(1<<bitNum1)|(1<<bitNum2)|(1<<bitNum3)|(1<<bitNum4)
#define TOGGLE_BIT(reg,bits_no)  reg^=(1<<bits_no)
#define SET_REG(reg) reg= 0xff
#define CLR_REG(reg)  reg = 0x00
#define TOGGLE_REG(reg) reg^=0xff
#define ASSIGN_REG(reg,value)   reg=value
#define GET_LOW_NIBLE(reg) reg& 0x0f
#define CLR_LOW_NIBLE(reg ) reg&= 0xf0
#define SET_LOW_NIBLE(reg ) reg|=0x0f
#define TOGGLE_LOW_NIBLE(reg) reg^=0x0f
#define ASSIGN_LOW_NIBLE(reg,value) reg=(reg&0xf0)|(value&0x0f)
#define GET_HIGH_NIBLE(reg) (reg& 0x0f )>> 4
#define CLR_HIGH_NIBLE(reg) reg&=0x0f
#define SET_HIGH_NIBLE(reg) reg|=0xf0
#define TOGGLE_HIGH_NIBLE(reg) reg^=0xf0
#define ASSIGN_HIGH_NIBLE(reg,value) reg=(reg&0x0f)|(value<<4)
#define ADD_BIT_VALUE(bitNum,value)  (value<<bitNum)




#endif /* UTILITES_H_ */
