/*
 * UART_Private.c
 *
 *  Created on: Nov 17, 2018
 *      Author: eng-magdy
 */
/*============================================================*/
/*==========               includes                 ==========*/
/*============================================================*/
#include <stdint.h>
#include "STD_Types.h"
#include "UART_Private.h"

/*============================================================*/
/*==========        Registers Definitions           ==========*/
/*============================================================*/

//Array of Uart CTL REGs
volatile uint32_t * UART_CTL_REGs[6]={0x4000C030,
                                      0x4000D030,
                                      0x4000E030,
                                      0x4000F030,
                                      0x40010030,
                                      0x40011030,
                                      0x40012030,
                                      0x40013030

};

//Array of Uart IBRD REGs
volatile uint32_t * UART_IBRD_REGs[6]={0x4000C024,
                                       0x4000D024,
                                       0x4000E024,
                                       0x4000F024,
                                       0x40010024,
                                       0x40011024,
                                       0x40012024,
                                       0x40013024

};

//Array of Uart FBRD REGs
volatile uint32_t * UART_FBRD_REGs[6]={0x4000C028,
                                       0x4000D028,
                                       0x4000E028,
                                       0x4000F028,
                                       0x40010028,
                                       0x40011028,
                                       0x40012028,
                                       0x40013028

};

//Array of Uart LCRH REGs
volatile uint32_t * UART_LCRH_REGs[6]={0x4000C02C,
                                       0x4000D02C,
                                       0x4000E02C,
                                       0x4000F02C,
                                       0x4001002C,
                                       0x4001102C,
                                       0x4001202C,
                                       0x4001302C

};

//Array of Uart CC REGs
volatile uint32_t * UART_CC_REGs[6]={0x4000CFC8,
                                     0x4000DFC8,
                                     0x4000EFC8,
                                     0x4000FFC8,
                                     0x40010FC8,
                                     0x40011FC8,
                                     0x40012FC8,
                                     0x40013FC8

};

//Array of Uart IM REGs
volatile uint32_t * UART_IM_REGs[6]={0x4000C038,
                                     0x4000D038,
                                     0x4000E038,
                                     0x4000F038,
                                     0x40010038,
                                     0x40011038,
                                     0x40012038,
                                     0x40013038

};

//Array of Uart FR REGs
volatile uint32_t * UART_FR_REGs[6]={0x4000C018,
                                     0x4000D018,
                                     0x4000E018,
                                     0x4000F018,
                                     0x40010018,
                                     0x40011018,
                                     0x40012018,
                                     0x40013018

};

//Array of Uart DR REGs
volatile uint32_t * UART_DR_REGs[6]={0x4000C000,
                                     0x4000D000,
                                     0x4000E000,
                                     0x4000F000,
                                     0x40010000,
                                     0x40011000,
                                     0x40012000,
                                     0x40013000

};

//Array of Uart ICR REGs
volatile uint32_t * UART_ICR_REGs[6]={0x4000C044,
                                      0x4000D044,
                                      0x4000E044,
                                      0x4000F044,
                                      0x40010044,
                                      0x40011044,
                                      0x40012044,
                                      0x40013044

};

