/*
 * UART_Private.h
 *
 *  Created on: Nov 17, 2018
 *      Author: eng-magdy
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/*============================================================*/
/*==========        Registers Definitions           ==========*/
/*============================================================*/

//Array of Uart CTL REGs
extern volatile uint32_t * UART_CTL_REGs[6];

//Array of Uart IBRD REGs
extern volatile uint32_t * UART_IBRD_REGs[6];

//Array of Uart FBRD REGs
extern volatile uint32_t * UART_FBRD_REGs[6];

//Array of Uart LCRH REGs
extern volatile uint32_t * UART_LCRH_REGs[6];

//Array of Uart CC REGs
extern volatile uint32_t * UART_CC_REGs[6];

//Array of Uart IM REGs
extern volatile uint32_t * UART_IM_REGs[6];

//Array of Uart FR REGs
extern volatile uint32_t * UART_FR_REGs[6];

//Array of Uart DR REGs
extern volatile uint32_t * UART_DR_REGs[6];

//Array of Uart ICR REGs
extern volatile uint32_t * UART_ICR_REGs[6];


#endif /* UART_PRIVATE_H_ */
