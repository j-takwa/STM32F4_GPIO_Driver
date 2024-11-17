/**
  ******************************************************************************
  * @file    Lab-Libraries/gpio.h 
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    19-06-2019
  *****************************************************************************

/* Includes ------------------------------------------------------------------*/
/** 
  * @brief General Purpose I/O
  */
  /* using enum to make the code more readable and self-explanatory => 
maintainability */

typedef enum
{

  Bit_RESET = 0, // Clear the port pin
  
  Bit_SET   = 1  // Set the port pin
}BitAction; 
// The starting memory addresses of each GPIO Port
// base address 

#define GPIO_A (unsigned int*)(0x40020000)
#define GPIO_B (unsigned int*)(0x40020400)
#define GPIO_C (unsigned int*)(0x40020800)
#define GPIO_D (unsigned int*)(0x40020C00)
#define GPIO_E (unsigned int*)(0x40021000)
#define GPIO_F (unsigned int*)(0x40021400)
#define GPIO_G (unsigned int*)(0x40021800)
#define GPIO_H (unsigned int*)(0x40021C00)
#define GPIO_I (unsigned int*)(0x40022000)

// base address of RCC
#define RCC    (unsigned int*)(0x40023800)
// address offset of RCC registers
#define AHB1ENR_OFFSET  0x30
#define AHB1RSTR_OFFSET  0x10
 
// GPIO_register_OFFSETs

#define MODER   0x00
#define OTYPER  0x04
#define OSPEEDR 0x08
#define PUPDR   0x0C
#define IDR     0x10
#define ODR     0x14
#define BSRR    0x18
#define LCKR    0x1C
#define AFRL    0x20
#define AFRH    0x24


// Port_mode 
#define INPUT  0x00
#define OUTPUT 0X01
#define AF     0X02
#define AN     0X03

// Port_output_type 
#define PP     0x00
#define OD     0x01 


// GPIO_pins_define 
#define GPIO_Pin_0 ((unsigned short)0x0001)  /* Pin 0 selected */
#define GPIO_Pin_1 ((unsigned  ) 0x0002)
#define GPIO_Pin_2 ((unsigned ) 0x0004)
#define GPIO_Pin_3 ((unsigned ) 0x0008)
#define GPIO_Pin_4 ((unsigned ) 0x0010)
#define GPIO_Pin_5 ((unsigned  ) 0x0020)
#define GPIO_Pin_6 ((unsigned  ) 0x0040)
#define GPIO_Pin_7 ((unsigned  ) 0x0080)
#define GPIO_Pin_8 ((unsigned  ) 0x0100)
#define GPIO_Pin_9 ((unsigned  ) 0x0200)
#define GPIO_Pin_10 ((unsigned  ) 0x0400)
#define GPIO_Pin_11 ((unsigned  ) 0x0800)
#define GPIO_Pin_12 ((unsigned  ) 0x1000)
#define GPIO_Pin_13 ((unsigned  ) 0x2000)
#define GPIO_Pin_14 ((unsigned  ) 0x4000)
#define GPIO_Pin_15 ((unsigned  ) 0x8000)


/* -----------------les protopyes des fonctions----------------------*/

//GPIO clock enable function 
void GPIO_ClockEnable (unsigned int * gpio_x);
// Reset all registers to their default value 
void GPIO_DeInit(unsigned int * gpio_x);
void GPIO_Init(unsigned int * gpio_x, char mode, char outputType, short int pin);
// Read functions
unsigned char GPIO_ReadInputDataBit(unsigned int * gpio_x, unsigned short int GPIO_Pin);
unsigned short int GPIO_ReadInputData(unsigned int * gpio_x);
// Write functions
void GPIO_WriteBit(unsigned int * gpio_x, unsigned short int GPIO_Pin, char BitVal);
void GPIO_Write(unsigned int * gpio_x, unsigned short int PortVal);



/******************* (C) COPYRIGHT 2019 CSF *****END OF FILE*******************/