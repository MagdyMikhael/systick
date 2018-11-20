/*
 * PLL.h
 *
 *  Created on: Nov 1, 2018
 *      Author: eng-magdy
 */

#ifndef PLL_H_
#define PLL_H_
/*============================================================*/
/*==========               includes                 ==========*/
/*============================================================*/
#include "STD_Types.h"
/*============================================================*/
/*==========              ProtoTypes                ==========*/
/*============================================================*/
void PLL_Enable(void);

/*============================================================*/
/*==========              definitions               ==========*/
/*============================================================*/
#define XTAL_Value (uint8_t)(0x15<<6)
#define SYSDIV2_Value (uint8_t)(4<<22)

//RCC2 BITs

#define BYPASS2 11U
#define PWRDN2  13U
#define DIV400  30U
#define USERCC2 31U


//SYSCTL_RIS_R BITs
#define PLLLRIS 6U

#endif /* PLL_H_ */
