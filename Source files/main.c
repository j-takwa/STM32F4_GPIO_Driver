/**
  ******************************************************************************
  * @file    Lab-Libraries/main.c 
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    19-06-2019
  *****************************************************************************/
#include "gpio.h"

/* Private define ------------------------------------------------------------*/
#define NOMBRE_BOUCLES 100
                                                       
/* Private function prototypes -----------------------------------------------*/
void Delay(volatile unsigned  int  nCount);


/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  unsigned  int counter = 0x00;  

  /* Enable the clock for port D */
  GPIO_ClockEnable(GPIO_D);

  /* Deinitialize the registers of port D */
  GPIO_DeInit(GPIO_D);
  
/* --- Configure PD12 et PD13 en mode Output Push pull avec un speed de 2MHz ---*/  

  GPIO_Init(GPIO_D, OUTPUT,  PP, 12);
  GPIO_Init(GPIO_D, OUTPUT,  PP, 13);

  for(counter=0; counter<NOMBRE_BOUCLES ; counter++)
  {
   /* Turn On LD3 and LD4 */
   GPIO_WriteBit(GPIO_D, GPIO_Pin_12, 0x01)  ;
   GPIO_WriteBit(GPIO_D, GPIO_Pin_13, 0x01)  ;
    
    Delay(0x3FFFFF) ;
    
    /* Turn off LD3 and LD4 */
   GPIO_WriteBit(GPIO_D, GPIO_Pin_12, 0x00)  ;
   GPIO_WriteBit(GPIO_D, GPIO_Pin_13, 0x00)  ;
   
    Delay(0x3FFFFF) ;
           
  }
  while(1);
}
/**
  * @brief  Inserts a delay time.
  * @param  nCount: specifies the delay time length.
  * @retval None
  */
void Delay(volatile unsigned  int  nCount)
{
  for(; nCount != 0; nCount--);
}

/******************* (C) COPYRIGHT 2019 CSF *****END OF FILE*******************/
