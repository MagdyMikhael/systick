/*
 * GPIO_Private.h
 *
 *  Created on: Nov 18, 2018
 *      Author: eng-magdy
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_
/*============================================================*/
/*==========               includes                 ==========*/
/*============================================================*/
#include <stdint.h>
/*============================================================*/
/*==========        Registers Definitions           ==========*/
/*============================================================*/

//Array of GPIO AFSEL REGs
extern volatile uint32_t * GPIO_AFSEL_REGs[6];

//Array of GPIO DEN REGs
extern volatile uint32_t * GPIO_DEN_REGs[6];

//Array of GPIO PTCL REGs
extern volatile uint32_t * GPIO_PTCL_REGs[6];

//Array of GPIO LOCK REGs
extern volatile uint32_t * GPIO_LOCK_REGs[6];

//Array of GPIO CR REGs
extern volatile uint32_t * GPIO_CR_REGs[6];

//Array of GPIO PUR REGs
extern volatile uint32_t * GPIO_PUR_REGs[6];

//Array of GPIO DIR REGs
extern volatile uint32_t * GPIO_DIR_REGs[6];

//Array of GPIO DATA REGs
extern volatile uint32_t * GPIO_DATA_REGs[6];
#endif /* GPIO_PRIVATE_H_ */
