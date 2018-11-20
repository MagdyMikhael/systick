


/*============================================================*/
/*==========               includes                 ==========*/
/*============================================================*/
#include "SysTick.h"
#include "utilites.h"
#include "tm4c123gh6pm.h"


/*============================================================*/
/*==========             Functions Bodies           ==========*/
/*============================================================*/


void SysTick_Init()
{

    // disable SysTick during setup
    NVIC_ST_CTRL_R = FALSE;
    // enable SysTick with core clock 0x00000005;
    SET_TWO_BITS(NVIC_ST_CTRL_R,Enable,CLK_SRC);
	
}


static void SysTick_Wait(uint32 delay)
{
    NVIC_ST_RELOAD_R = delay-1;                  // number of counts to wait
    NVIC_ST_CURRENT_R = FALSE;                   // any value written to CURRENT clears
    while(GET_BIT(NVIC_ST_CTRL_R,Count)==0){     // wait for count flag
      }
}

void SysTick_Delay_ms(uint16 time){
	uint32 i;
	for(i=0;i<time;i++){
		//while(GET_BIT(NVIC_ST_RELOAD_R ,Count)==0);
	    SysTick_Wait(LOAD_REG_VALUE);
			
	}
	
}
