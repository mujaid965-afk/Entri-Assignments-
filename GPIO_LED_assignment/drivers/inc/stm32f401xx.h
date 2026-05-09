#ifndef STM32F401XX_H_
#define STM32F401XX_H_


#include<stddef.h>
#include<stdint.h>
#define __vo volatile



/*
 * basse address of memory definition
 */

#define FLASH_BASEADDR		0x08000000U
#define ROM_BASEADDR		0x1FFF0000U
#define SRAM_BASEADDR		0x20000000U

/*
 * peripheral bus base address
 */
#define PERIPH_BASEADDR		0x4000 0000U
#define APB1PERIPH_BASEADDR	PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR 0x40010000U
#define AHB1PERIPH_BASEADDR 0x40020000U
#define AHB2PERIPH_BASEADDR 0x50000000U

/*
 * Base address oof peripherals hanging in AHB1
 */

#define GPIOA_BASEADDR		(AHB1PERIPH_BASEADDR + 0x0000U)
#define GPIOB_BASEADDR		(AHB1PERIPH_BASEADDR + 0x0400U)
#define GPIOC_BASEADDR		(AHB1PERIPH_BASEADDR + 0x0800U)
#define GPIOD_BASEADDR		(AHB1PERIPH_BASEADDR + 0x0C00U)
#define GPIOE_BASEADDR		(AHB1PERIPH_BASEADDR + 0X1000U)
#define GPIOH_BASEADDR		(AHB1PERIPH_BASEADDR + 0x1C00U)
#define RCC_BASEADDR 		(AHB1PERIPH_BASEADDR + 0x3800U)

/*
 * Base address of peripherals hanging in AHB2
 */

#define USBOTG_BASEADDR		AHB2PERIPH_BASEADDR

/*
 * base addressof peripherals hanging in APB1
 */

#define TIM2_BASEADDR		(APB1PERIPH_BASEADDR + 0x0000U)
#define TIM3_BASEADDR		(APB1PERIPH_BASEADDR + 0x0400U)
#define TIM4_BASEADDR		(APB1PERIPH_BASEADDR + 0x0800U)
#define TIM5_BASEADDR		(APB1PERIPH_BASEADDR + 0x0C00U)

#define RTC_BASEADDR		(APB1PERIPH_BASEADDR + 0x2800U)
#define WWDG_BASEADDR		(APB1PERIPH_BASEADDR + 0x2C00U)
#define IWDG_BASEADDR		(APB1PERIPH_BASEADDR + 0x3000U)
#define I2S2EXT_BASEADDR	(APB1PERIPH_BASEADDR + 0x3400U)

#define SPI2_BASEADDR		(APB1PERIPH_BASEADDR + 0x3800U)
#define SPI3_BASEADDR		(APB1PERIPH_BASEADDR + 0x3C00U)

#define I2S3EXT_BASEADDR	(APB1PERIPH_BASEADDR + 0x4000U)
#define USART2_BASEADDR		(APB1PERIPH_BASEADDR + 0x4400U)

#define I2C1_BASEADDR		(APB1PERIPH_BASEADDR + 0x5400U)
#define I2C2_BASEADDR		(APB1PERIPH_BASEADDR + 0x5800U)
#define I2C3_BASEADDR		(APB1PERIPH_BASEADDR + 0x5C00U)

#define PWR_BASEADDR		(APB1PERIPH_BASEADDR + 0x7000U)

/*
 * base addressof peripherals hanging in APB1
 */

#define TIM1_BASEADDR		(APB2PERIPH_BASEADDR + 0x0000U)
#define TIM8_BASEADDR		(APB2PERIPH_BASEADDR + 0x0400U)

#define USART1_BASEADDR		(APB2PERIPH_BASEADDR + 0x1000U)
#define USART6_BASEADDR		(APB2PERIPH_BASEADDR + 0x1400U)

#define ADC1_BASEADDR		(APB2PERIPH_BASEADDR + 0x2000U)
#define SDIO_BASEADDR		(APB2PERIPH_BASEADDR + 0x2C00U)

#define SPI1_BASEADDR		(APB2PERIPH_BASEADDR + 0x3000U)
#define SPI4_BASEADDR		(APB2PERIPH_BASEADDR + 0x3400U)
#define SYSCFG_BASEADDR		(APB2PERIPH_BASEADDR + 0x3800U)

#define EXT1_BASEADDR		(APB2PERIPH_BASEADDR + 0x3C00U)

#define TIM9_BASEADDR		(APB2PERIPH_BASEADDR + 0x4000U)
#define TIM10_BASEADDR		(APB2PERIPH_BASEADDR + 0x4400U)
#define TIM11_BASEADDR		(APB2PERIPH_BASEADDR + 0x4800U)

/*
 * GPIO register structure definition
 */

typedef struct{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];

} GPIO_RegDef_t;


/*
 * peripheral definitions (periphera base addresses typecasted to xxx_RegDef_t)
 */

#define GPIOA				((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB				((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC				((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD				((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE				((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOH				((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC					((RCC_RegDef_t*)RCC_BASEADDR)

/*
 * Peripheral register definition structure for SPI
 */

typedef struct{
	__vo uint32_t CR1;			/*!< Control register 1,      Offset: 0x00 */
	__vo uint32_t SR;			/*!< Status register,         Offset: 0x08 */
	__vo uint32_t DR;			/*!< Data register,           Offset: 0x0C */
	__vo uint32_t CRCPR;		/*!< CRC polynomial register, Offset: 0x10 */
	__vo uint32_t RXCRCR;		/*!< RX CRC register,         Offset: 0x14 */
	__vo uint32_t TXCRCR;		/*!< TX CRC register,         Offset: 0x18 */
	__vo uint32_t I2SCFGR;		/*!< I2S configuration,       Offset: 0x1C */
	__vo uint32_t I2SPR;		/*!< I2S prescaler,           Offset: 0x20 */
}SPI_RegDef_t;

#define SPI1  				((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2  				((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3  				((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4 				((SPI_RegDef_t*)SPI4_BASEADDR)

/*
 * Peripheral register definition structure for RCC
 */
typedef struct{
	    __vo uint32_t CR;           /*!< Clock control register,         							  Offset: 0x00 */
	    __vo uint32_t PLLCFGR;      /*!< PLL configuration register,     							  Offset: 0x04 */
	    __vo uint32_t CFGR;         /*!< Clock configuration register,   							  Offset: 0x08 */
	    __vo uint32_t CIR;          /*!< Clock interrupt register,        							  Offset: 0x0C */
	    __vo uint32_t AHB1RSTR;     /*!< AHB1 peripheral reset register, 							  Offset: 0x10 */
	    __vo uint32_t AHB2RSTR;     /*!< AHB2 peripheral reset register,  							  Offset: 0x14 */
	    uint32_t      RESERVED0[2]; /*!< Reserved,                      							  Offset: 0x18 */
	    __vo uint32_t APB1RSTR;     /*!< APB1 peripheral reset register,   							  Offset: 0x20 */
	    __vo uint32_t APB2RSTR;     /*!< APB2 peripheral reset register,  							  Offset: 0x24 */
	    uint32_t      RESERVED1[2]; /*!< Reserved,                        							  Offset: 0x28-0x2C */
	    __vo uint32_t AHB1ENR;      /*!< AHB1 clock enable register,      							  Offset: 0x30 */
	    __vo uint32_t AHB2ENR;      /*!< AHB2 clock enable register,      							  Offset: 0x34 */
	    uint32_t      RESERVED2[2]; /*!< Reserved,                      						      Offset: 0x38-0x3C */
	    __vo uint32_t APB1ENR;      /*!< APB1 clock enable register,      							  Offset: 0x40 */
	    __vo uint32_t APB2ENR;      /*!< APB2 clock enable register,     							  Offset: 0x44 */
	    uint32_t      RESERVED3[2]; /*!< Reserved,                        							  Offset: 0x48-0x4C */
	    __vo uint32_t AHB1LPENR;    /*!< C AHB1 peripheral clock enable in low power mode register,   Offset: 0x50 */
	    __vo uint32_t AHB2LPENR;    /*!<  AHB2 peripheral clock enable in low power mode register,    Offset: 0x54 */
	    uint32_t      RESERVED4[2]; /*!< Reserved,                       							  Offset: 0x58-0x5C */
	    __vo uint32_t APB1LPENR;    /*!<  APB1 peripheral clock enable in low power mode register,    Offset: 0x60 */
	    __vo uint32_t APB2LPENR;    /*!<  APB2 peripheral clock enabled in low power mode register,   Offset: 0x64 */
	    uint32_t      RESERVED5[2]; /*!< Reserved,                        							  Offset: 0x68-0x6C */
	    __vo uint32_t BDCR;         /*!<  Backup domain control register,    						  Offset: 0x70 */
	    __vo uint32_t CSR;          /*!< clock control & status register,          					  Offset: 0x74 */
	    uint32_t      RESERVED6[2]; /*!< Reserved,                                                    Offset: 0x78-0x7C */
	    __vo uint32_t SSCGR;        /*!<  spread spectrum clock generation register,     			  Offset: 0x80 */
	    __vo uint32_t PLLI2SCFGR;   /*!<  PLLI2S configuration register,                              Offset: 0x84 */
	    __vo uint32_t DCKCFGR;      /*!<  Dedicated Clocks Configuration Register,      			  Offset: 0x8C */
}RCC_RegDef_t;


#define GPIOA_PCLK_EN()				(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()				(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()				(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()				(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()				(RCC->AHB1ENR |= (1 << 4))
#define GPIOH_PCLK_EN()				(RCC->AHB1ENR |= (1 << 7))


#define GPIOA_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOH_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 7))


#define SPI1_PCLK_EN()				(RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()				(RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()				(RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN()				(RCC->APB2ENR |= (1 << 13))


#define SPI1_PCLK_DI()				(RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()				(RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()				(RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI()				(RCC->APB2ENR &= ~(1 << 13))



#define ENABLE						1
#define DISABLE 					0


#endif

