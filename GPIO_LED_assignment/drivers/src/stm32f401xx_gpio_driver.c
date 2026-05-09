/*
 * stm32f401xx_gpio_driver.c
 *
 *  Created on: Apr 2, 2026
 *      Author: Mujaid
 */


#include "stm32f401xx.h"
#include "stm32f401xx_gpio_driver.h"

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
	}else
	{

	}
}

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp;

	//Configure Mode
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->MODER &= ~(3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->MODER |= temp;

	//Configure Speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	// 4. Configure Output Type
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;

    // 5. Alternate Function
	uint8_t temp1, temp2;
    temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
    temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;

    pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2));
    pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
	}


uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
    uint8_t value;
    value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x1);
    return value;
}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value)
{
    if(value == 1)
    {
        pGPIOx->ODR |= (1 << PinNumber);
    }
    else
    {
        pGPIOx->ODR &= ~(1 << PinNumber);
    }
}







