/*
 * GPIO_Private.c
 *
 *  Created on: Nov 18, 2018
 *      Author: eng-magdy
 */

#include "GPIO_Private.h"

/*============================================================*/
/*==========        Registers Definitions           ==========*/
/*============================================================*/

//Array of GPIO AFSEL REGs
volatile uint32_t * GPIO_AFSEL_REGs[6]={0x40004420,
                                        0x40005420,
                                        0x40006420,
                                        0x40007420,
                                        0x40024420,
                                        0x40025420
};

//Array of GPIO DEN REGs
volatile uint32_t * GPIO_DEN_REGs[6]={0x4000451C,
                                      0x4000551C,
                                      0x4000651C,
                                      0x4000751C,
                                      0x4002451C,
                                      0x4002551C

};

//Array of GPIO PTCL REGs
volatile uint32_t * GPIO_PTCL_REGs[6]={0x4000452C,
                                       0x4000552C,
                                       0x4000652C,
                                       0x4000752C,
                                       0x4002452C,
                                       0x4002552C

};

//Array of GPIO LOCK REGs
volatile uint32_t * GPIO_LOCK_REGs[6]={0x40004520,
                                       0x40005520,
                                       0x40006520,
                                       0x40007520,
                                       0x40024520,
                                       0x40025520

};


//Array of GPIO CR REGs
volatile uint32_t * GPIO_CR_REGs[6]={0x40004524,
                                     0x40005524,
                                     0x40006524,
                                     0x40007524,
                                     0x40024524,
                                     0x40025524

};

//Array of GPIO PUR REGs
volatile uint32_t * GPIO_PUR_REGs[6]={0x40004510,
                                      0x40005510,
                                      0x40006510,
                                      0x40007510,
                                      0x40024510,
                                      0x40025510

};

//Array of GPIO DIR REGs
volatile uint32_t * GPIO_DIR_REGs[6]={0x40004400,
                                      0x40005400,
                                      0x40006400,
                                      0x40007400,
                                      0x40024400,
                                      0x40025400

};

//Array of GPIO DATA REGs
volatile uint32_t * GPIO_DATA_REGs[6]={0x400043FC,
                                       0x400053FC,
                                       0x400063FC,
                                       0x400073FC,
                                       0x400243FC,
                                       0x400253FC

};
