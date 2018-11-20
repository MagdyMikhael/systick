/*
 * Common_Func.c
 *
 *  Created on: Nov 17, 2018
 *      Author: eng-magdy
 */

/*============================================================*/
/*==========               includes                 ==========*/
/*============================================================*/
#include "Common_Func.h"
#include "utilites.h"


/*============================================================*/
/*==========        Registers Definitions           ==========*/
/*============================================================*/
//Array of Enable interrupt registers
volatile uint32_t * NVIC_Enable_Rs[4]={0xE000E100,
                                       0xE000E104,
                                       0xE000E108,
                                       0xE000E10C,
                                       0xE000E110
};

//Array of Disable interrupt registers
volatile uint32_t * NVIC_Disable_Rs[4]={0xE000E180,
                                        0xE000E184,
                                        0xE000E188,
                                        0xE000E18C,
                                        0xE000E190,

};


/*============================================================*/
/*==========             Functions Bodies           ==========*/
/*============================================================*/
void DisableInterrupts(void){__asm (" CPSID  I\n");}
void EnableInterrupts(void){__asm  (" CPSIE  I\n");}

void NVIC_EnableIRQ(uint16 IRQNum){
    uint8 Intr_Position=IRQNum/32;
    uint8 Intr_Index=IRQNum%32;
    SET_BIT(*NVIC_Enable_Rs[Intr_Position],Intr_Index);

}


void NVIC_DisableIRQ(uint16 IRQNum){
    uint8 Intr_Position=IRQNum/32;
    uint8 Intr_Index=IRQNum%32;
    SET_BIT(*NVIC_Disable_Rs[Intr_Position],Intr_Index);
}
