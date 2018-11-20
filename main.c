/********************************************************************************
***** Includes                                                                                                                              *****
********************************************************************************/
#include "SysTick.h"
#include "utilites.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "PLL.h"
#include "Common_Func.h"
#include "UART_CFG.h"
#include "UART_Interface.h"
#include "GPIO_CFG.h"
#include "GPIO_Interface.h"

/********************************************************************************
***** MAIN FUNCTION                                                                                                                 *****
********************************************************************************/

int main(){

    PLL_Enable();
    SysTick_Init();

    UART_Init(Uart5, BR_9600);
    GPIO_WritePinDir(PF1,STD_HIGH);
    EnableInterrupts();

    uint8 x;
    while(1){
        UART_Transmit(Uart5, 1);
        x=UART_Recieve(Uart5);
        if(x==1){
            GPIO_TogglePinVal(PF1);
            SysTick_Delay_ms(1000);
        }
    }

}
