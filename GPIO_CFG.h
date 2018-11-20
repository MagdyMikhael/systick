/*
 * GPIO_CFG.h
 *
 *  Created on: Nov 20, 2018
 *      Author: eng-magdy
 */

#ifndef GPIO_CFG_H_
#define GPIO_CFG_H_

/*============================================================*/
/*==========               includes                 ==========*/
/*============================================================*/
#include <stdint.h>

/*============================================================*/
/*==========              ProtoTypes                ==========*/
/*============================================================*/
void GPIO_WritePinDir(uint8_t PIN_NUM,uint8_t Val);
void GPIO_WritePinVal(uint8_t PIN_NUM,uint8_t Val);
void GPIO_ReadPinVal(uint8_t PIN_NUM,uint8_t *Val);
void GPIO_TogglePinVal(uint8_t PIN_NUM);

/*============================================================*/
/*==========              Definitions               ==========*/
/*============================================================*/
#define UN_LOCK 0x4C4F434B;
#define CR_VALUE 0xff

#define PORT_DIR_OUT 0xff
#define PORT_DIR_IN 0x00

#define PORT_DEN 0xff

#define PORT_AFSEL 0x00

#define PORT_PUR 0xff
#endif /* GPIO_CFG_H_ */
