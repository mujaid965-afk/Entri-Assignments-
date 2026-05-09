/*
 * stm32f401xx_gpio_driver.h
 *
 *  Created on: Apr 2, 2026
 *      Author: Mujaid
 */

#ifndef INC_STM32F401XX_GPIO_DRIVER_H_
#define INC_STM32F401XX_GPIO_DRIVER_H_
#include "stm32f401xx.h"

//GPIO Pin Configuration Structure
typedef struct{
	uint8_t GPIO_PinNumber;				// 0–15
	uint8_t GPIO_PinMode;				// input/output/alt/analog
	uint8_t GPIO_PinSpeed;				// low/medium/fast/high
	uint8_t GPIO_PinPuPdControl;		// no pull-up/down
	uint8_t GPIO_PinOPType;				// push-pull/open-drain
	uint8_t GPIO_PinAltFunMode;			// alternate function
}GPIO_PinConfig_t;


//GPIO Handle Structure
typedef struct
{
	GPIO_RegDef_t *pGPIOx;				// GPIO base address
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;

//API

//peripheral Clock
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi);

//Init & DeInit
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data Read and Write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0      0
#define GPIO_PIN_NO_1      1
#define GPIO_PIN_NO_2      2
#define GPIO_PIN_NO_3      3
#define GPIO_PIN_NO_4      4
#define GPIO_PIN_NO_5      5
#define GPIO_PIN_NO_6      6
#define GPIO_PIN_NO_7      7
#define GPIO_PIN_NO_8      8
#define GPIO_PIN_NO_9      9
#define GPIO_PIN_NO_10     10
#define GPIO_PIN_NO_11     11
#define GPIO_PIN_NO_12     12
#define GPIO_PIN_NO_13     13
#define GPIO_PIN_NO_14     14
#define GPIO_PIN_NO_15     15

#define GPIO_MODE_IN        0
#define GPIO_MODE_OUT       1

#define GPIO_SPEED_FAST     2

#define GPIO_OP_TYPE_PP     0

#define GPIO_NO_PUPD        0

#define ENABLE              1
#define DISABLE             0

#endif /* INC_STM32F401XX_GPIO_DRIVER_H_ */
