/*
 * GPIO_Prog.c
 *
 *  Created on: Nov 20, 2018
 *      Author: eng-magdy
 */

/*============================================================*/
/*==========               includes                 ==========*/
/*============================================================*/
#include "GPIO_CFG.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include <stdint.h>
#include "STD_Types.h"
#include "tm4c123gh6pm.h"
#include "utilites.h"
/*============================================================*/
/*==========             Functions Bodies           ==========*/
/*============================================================*/
void GPIO_WritePinDir(uint8_t PIN_NUM,uint8_t Val){
    //calculate pin port and its offset
    uint8_t Pin_Location=PIN_NUM/8;
    uint8_t Pin_Index=PIN_NUM%8;

    //Enable GPIO PORT
    SET_BIT(SYSCTL_RCGCGPIO_R,Pin_Location);

    //Enable Digital
    SET_BIT(*GPIO_DEN_REGs[Pin_Location],Pin_Index);

    //Diable alternative Function
    CLR_BIT(*GPIO_AFSEL_REGs[Pin_Location],Pin_Index);

    //Enable encrypted pins
    *GPIO_LOCK_REGs[Pin_Location]=UN_LOCK;
    *GPIO_CR_REGs[Pin_Location]=CR_VALUE;

    //Enable pull up resistor if configered input
    if(Val==STD_LOW){
        SET_BIT(*GPIO_PUR_REGs[Pin_Location],Pin_Index);
    }

    //define direction of Pin
    ASSIGN_BIT(*GPIO_DIR_REGs[Pin_Location],Pin_Index,Val);
}


void GPIO_WritePinVal(uint8_t PIN_NUM,uint8_t Val){
    //calculate pin port and its offset
    uint8_t Pin_Location=PIN_NUM/8;
    uint8_t Pin_Index=PIN_NUM%8;

    //write pin value
    ASSIGN_BIT(*GPIO_DATA_REGs[Pin_Location],Pin_Index,Val);
}


void GPIO_ReadPinVal(uint8_t PIN_NUM,uint8_t *Val){
    //calculate pin port and its offset
    uint8_t Pin_Location=PIN_NUM/8;
    uint8_t Pin_Index=PIN_NUM%8;

    //get pin value
    *Val=GET_BIT(*GPIO_DATA_REGs[Pin_Location],Pin_Index);

}


void GPIO_TogglePinVal(uint8_t PIN_NUM){
    //calculate pin port and its offset
    uint8_t Pin_Location=PIN_NUM/8;
    uint8_t Pin_Index=PIN_NUM%8;

    //get pin value
    TOGGLE_BIT(*GPIO_DATA_REGs[Pin_Location],Pin_Index);
}
