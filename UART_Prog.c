/*
 * UART_Prog.c
 *
 *  Created on: Nov 17, 2018
 *      Author: eng-magdy
 */

/*============================================================*/
/*==========               includes                 ==========*/
/*============================================================*/
#include <stdint.h>
#include "STD_Types.h"
#include "Common_Func.h"
#include "GPIO_Private.h"
#include "utilites.h"
#include "UART_Private.h"
#include "UART_CFG.h"
#include "UART_Interface.h"
#include "tm4c123gh6pm.h"



/*============================================================*/
/*==========              ProtoTypes                ==========*/
/*============================================================*/
void UART0_ISR(void);
void UART1_ISR(void);
void UART2_ISR(void);
void UART3_ISR(void);
void UART4_ISR(void);
void UART5_ISR(void);
void UART6_ISR(void);
void UART7_ISR(void);
/*============================================================*/
/*==========              GlobalVars                ==========*/
/*============================================================*/
const static uint8 Uart_IRQ_list[8]={UART0_IRQn,
                                     UART1_IRQn,
                                     UART2_IRQn,
                                     UART3_IRQn,
                                     UART4_IRQn,
                                     UART5_IRQn,
                                     UART6_IRQn,
                                     UART7_IRQn
};


UART_STRUCT UART[8]={{Uart0,PORTA,PIN0,PIN1,PCLR_NUM0,PCLR_NUM1},{99,99,99,99,99,99},
{Uart2,PORTD,PIN6,PIN7,PCLR_NUM6,PCLR_NUM7},{Uart3,PORTC,PIN6,PIN7,PCLR_NUM6,PCLR_NUM7},
{Uart4,PORTC,PIN4,PIN5,PCLR_NUM4,PCLR_NUM5},{Uart5,PORTE,PIN4,PIN5,PCLR_NUM4,PCLR_NUM5},
{Uart6,PORTD,PIN4,PIN5,PCLR_NUM4,PCLR_NUM5},{Uart7,PORTE,PIN0,PIN1,PCLR_NUM0,PCLR_NUM1}};


volatile uint8_t ReceiveComplete0 =0;
volatile uint8_t i0=0;
volatile uint8_t ReceiveComplete1 =0;
volatile uint8_t i1=0;
volatile uint8_t ReceiveComplete2 =0;
volatile uint8_t i2=0;
volatile uint8_t ReceiveComplete3 =0;
volatile uint8_t i3=0;
volatile uint8_t ReceiveComplete4 =0;
volatile uint8_t i4=0;
volatile uint8_t ReceiveComplete5 =0;
volatile uint8_t i5=0;
volatile uint8_t ReceiveComplete6 =0;
volatile uint8_t i6=0;
volatile uint8_t ReceiveComplete7 =0;
volatile uint8_t i7=0;

volatile uint8_t Uart0_Receive[Uart0_Buffer_Length];
volatile uint8_t Uart1_Receive[Uart1_Buffer_Length];
volatile uint8_t Uart2_Receive[Uart2_Buffer_Length];
volatile uint8_t Uart3_Receive[Uart3_Buffer_Length];
volatile uint8_t Uart4_Receive[Uart4_Buffer_Length];
volatile uint8_t Uart5_Receive[Uart5_Buffer_Length];
volatile uint8_t Uart6_Receive[Uart6_Buffer_Length];
volatile uint8_t Uart7_Receive[Uart7_Buffer_Length];

uint8_t arrBack[500];
/*============================================================*/
/*==========            Static Functions            ==========*/
/*============================================================*/


/*============================================================*/
/*==========             Functions Bodies           ==========*/
/*============================================================*/

void UART_Init(uint8 U_NUM,uint32 baudRate){

    //Calculate Baudrate
    float BRDI_float=UARTSysClk/(ClkDiv * baudRate);
    uint16 BAUD_RATE=(uint16)BRDI_float;
    BRDI_float = BRDI_float - (long)BRDI_float;
    uint8 FRACTION_PART=(uint8)(BRDI_float * 64 + 0.5);

    // provide clock to UART
    SET_BIT(SYSCTL_RCGCUART_R,UART[U_NUM].UART_NUM);

    //enable clock to PORT
    SET_BIT(SYSCTL_RCGCGPIO_R,UART[U_NUM].PORT_NUM);

    //USE ALTERNATIVE FUNCTIONS
    SET_TWO_BITS(*GPIO_AFSEL_REGs[UART[U_NUM].PORT_NUM],UART[U_NUM].URx,UART[U_NUM].UTx);

    //ENABLE DIGITAL
    SET_TWO_BITS(*GPIO_DEN_REGs[UART[U_NUM].PORT_NUM],UART[U_NUM].URx,UART[U_NUM].UTx);

    //USE PINS AS UART
    SET_TWO_BITS(*GPIO_PTCL_REGs[UART[U_NUM].PORT_NUM],UART[U_NUM].PCLR_Rx,UART[U_NUM].PCLR_Tx);

    //Enable interrupt Function
    NVIC_EnableIRQ(Uart_IRQ_list[UART[U_NUM].UART_NUM]);

    //disable UART
    CLR_BIT(*UART_CTL_REGs[UART[U_NUM].UART_NUM],UARTEN);

    //Set intger baud rate
    *UART_IBRD_REGs[UART[U_NUM].UART_NUM]=BAUD_RATE;

    //Set fraction part of baud rate
    *UART_FBRD_REGs[UART[U_NUM].UART_NUM]=FRACTION_PART;

    //8-bit, no parity, 1-stop bit, no FIFO
    *UART_LCRH_REGs[UART[U_NUM].UART_NUM]|=(WLEN <<WLEN_SHIFT);
    SET_BIT(*UART_LCRH_REGs[UART[U_NUM].UART_NUM],FEN);

    //use system clock
    *UART_CC_REGs[UART[U_NUM].UART_NUM]=SYS_CLOCK;

    //enable UART, TXE, RXE
    SET_THREE_BITS(*UART_CTL_REGs[UART[U_NUM].UART_NUM],UARTEN,TXE,RXE);

    //ENABLE INTERRUPT
    SET_BIT(*UART_IM_REGs[UART[U_NUM].UART_NUM],RXIM);



}


void UART_Transmit(uint8 U_NUM,uint8 DATA){
    //wait until Tx buffer not full before giving it another byte
    while(GET_BIT(*UART_FR_REGs[UART[U_NUM].UART_NUM],TXFF)!=FALSE);

    //transmit data
    *UART_DR_REGs[UART[U_NUM].UART_NUM]=DATA;

}


uint8 UART_Recieve(uint8 U_NUM){

    switch(UART[U_NUM].UART_NUM){
        case 0:
                  //while(Get_Bit(UART0_FR_R,RXFE)!=0);                               //wait until the buffer is not empty
                  return Uart0_Receive[0];                                               //read the received data

          break;
        case 1:
                  //while(Get_Bit(UART1_FR_R,RXFE)!=0);
                  return Uart1_Receive[0];
          break;
        case 2:
                  //while(Get_Bit(UART2_FR_R,RXFE)!=0);
                  return Uart2_Receive[0];
          break;
        case 3:
                  //while(Get_Bit(UART3_FR_R,RXFE)!=0);
                  return Uart3_Receive[0];
          break;
        case 4:
                  //while(Get_Bit(UART4_FR_R,RXFE)!=0);
                  return Uart4_Receive[0];
          break;
        case 5:
                  //while(Get_Bit(UART5_FR_R,RXFE)!=0);
                  return Uart5_Receive[0];
          break;
        case 6:
                  //while(Get_Bit(UART6_FR_R,RXFE)!=0);
                  return Uart6_Receive[0];
          break;
        case 7:
                  //while(Get_Bit(UART7_FR_R,RXFE)!=0);
                  return Uart7_Receive[0];
          break;
        default:
          break;

    }
}


void UART_Write_String(uint8 U_NUM,uint8 const * string){
    while(*string != '\0')
      {
        UART_Transmit(U_NUM,* string );
        string++;
    }
}


uint8 * UART_Read_String(uint8 U_NUM ){
    switch(U_NUM){
      case 0:strcpy(arrBack,Uart0_Receive);
      break;
      case 1:strcpy(arrBack,Uart1_Receive);
      break;
      case 2:strcpy(arrBack,Uart2_Receive);
      break;
      case 3:strcpy(arrBack,Uart3_Receive);
      break;
      case 4:strcpy(arrBack,Uart4_Receive);
      break;
      case 5:strcpy(arrBack,Uart5_Receive);
      break;
      case 6:strcpy(arrBack,Uart6_Receive);
      break;
      case 7:strcpy(arrBack,Uart7_Receive);
      break;
      default:
        break;

      }
    return arrBack;
}


void Clear_Buffer(uint8 U_NUM){
    switch(U_NUM){
      case 0:memset(Uart0_Receive,'0',Uart0_Buffer_Length);
      break;
      case 1:memset(Uart1_Receive,'0',Uart1_Buffer_Length);
      break;
      case 2:memset(Uart2_Receive,'0',Uart2_Buffer_Length);
      break;
      case 3:memset(Uart3_Receive,'0',Uart3_Buffer_Length);
      break;
      case 4:memset(Uart4_Receive,'0',Uart4_Buffer_Length);
      break;
      case 5:memset(Uart5_Receive,'0',Uart5_Buffer_Length);
      break;
      case 6:memset(Uart6_Receive,'0',Uart6_Buffer_Length);
      break;
      case 7:memset(Uart7_Receive,'0',Uart7_Buffer_Length);
      break;
      default:
        break;
    }
}


void UART0_ISR(void){
    Uart0_Receive[i0]=*UART_DR_REGs[Uart0];

    if(i0==Uart0_Buffer_Length){
        ReceiveComplete0 =1;
        i0=0;}
    i0++;
    if(ReceiveComplete0==1){
        CLR_BIT(*UART_ICR_REGs[Uart0],RXIC);
        i0=0;
    }
}


void UART1_ISR(void){
    Uart1_Receive[i1]=*UART_DR_REGs[Uart1];

    if(i0==Uart1_Buffer_Length){
        ReceiveComplete1 =1;
        i1=0;}
    i1++;
    if(ReceiveComplete1==1){
        CLR_BIT(*UART_ICR_REGs[Uart1],RXIC);
        i1=0;
    }
}


void UART2_ISR(void){
    Uart2_Receive[i2]=*UART_DR_REGs[Uart2];

    if(i2==Uart2_Buffer_Length){
        ReceiveComplete2 =1;
        i2=0;}
    i2++;
    if(ReceiveComplete2==1){
        CLR_BIT(*UART_ICR_REGs[Uart2],RXIC);
        i2=0;
    }
}


void UART3_ISR(void){
    Uart3_Receive[i3]=*UART_DR_REGs[Uart3];

    if(i3==Uart3_Buffer_Length){
        ReceiveComplete3 =1;
        i3=0;}
    i3++;
    if(ReceiveComplete3==1){
        CLR_BIT(*UART_ICR_REGs[Uart3],RXIC);
        i3=0;
    }
}


void UART4_ISR(void){
    Uart4_Receive[i4]=*UART_DR_REGs[Uart4];

    if(i4==Uart4_Buffer_Length){
        ReceiveComplete4 =1;
        i4=0;}
    i4++;
    if(ReceiveComplete4==1){
        CLR_BIT(*UART_ICR_REGs[Uart4],RXIC);
        i4=0;
    }
}


void UART5_ISR(void){
    Uart5_Receive[i5]=*UART_DR_REGs[Uart5];

    if(i5==Uart5_Buffer_Length){
        ReceiveComplete5 =1;
        i5=0;}
    i5++;
    if(ReceiveComplete5==1){
        CLR_BIT(*UART_ICR_REGs[Uart5],RXIC);
        i5=0;
    }
}


void UART6_ISR(void){
    Uart6_Receive[i6]=*UART_DR_REGs[Uart6];

    if(i6==Uart6_Buffer_Length){
        ReceiveComplete6 =1;
        i6=0;}
    i6++;
    if(ReceiveComplete6==1){
        CLR_BIT(*UART_ICR_REGs[Uart6],RXIC);
        i6=0;
    }
}


void UART7_ISR(void){
    Uart7_Receive[i7]=*UART_DR_REGs[Uart7];

    if(i7==Uart7_Buffer_Length){
        ReceiveComplete7 =1;
        i7=0;}
    i7++;
    if(ReceiveComplete7==1){
        CLR_BIT(*UART_ICR_REGs[Uart7],RXIC);
        i7=0;
    }
}

