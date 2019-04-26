/*
 * as5048a.h
 *
 *  Created on: 18 Nis 2019
 *      Author: fatih.akgul
 */

#ifndef AS5048A_H_
#define AS5048A_H_

#include "stm32f4_discovery.h"
#include "stm32f4xx_conf.h"
#include "stm32f4xx.h"

#define CMD_ANGLE            0xffff
#define CMD_AGC              0x7ffd
#define CMD_MAG              0x7ffe
#define CMD_CLEAR            0x4001
#define CMD_NOP              0xc000

struct as5048_data
{
    uint8_t iserror;
    uint16_t value;
    uint16_t mag;
    uint8_t agc;
    double angle;
};

uint16_t SPI2_Read5048Data(uint16_t TxData);
u16 ClearAndNop(void);
struct as5048_data CollectData(void);

//#define SPI1_OPEN
#define SPI2_OPEN
//#define SPI3_OPEN

#ifdef              SPI1_OPEN
    #define Open_SPIx_NSS_PIN                   GPIO_Pin_0
    #define Open_SPIx_NSS_PORT                  GPIOA
    #define Open_SPIx_NSS_GPIO_CLK              RCC_AHB1Periph_GPIOA

    //#define Open_RCC_APB2Periph_SPIx              RCC_APB2Periph_SPI1

    #define Open_SPIx                           SPI1
    #define Open_SPIx_CLK                       RCC_APB2Periph_SPI1
    #define Open_SPIx_CLK_INIT                  RCC_APB2PeriphClockCmd
    #define Open_SPIx_IRQn                      SPI1_IRQn
    #define Open_SPIx_IRQHANDLER                SPI1_IRQHandler

    #define Open_SPIx_SCK_PIN                   GPIO_Pin_3
    #define Open_SPIx_SCK_GPIO_PORT             GPIOB
    #define Open_SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOB
    #define Open_SPIx_SCK_SOURCE                GPIO_PinSource3
    #define Open_SPIx_SCK_AF                    GPIO_AF_SPI1

    #define Open_SPIx_MISO_PIN                  GPIO_Pin_4
    #define Open_SPIx_MISO_GPIO_PORT            GPIOB
    #define Open_SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOB
    #define Open_SPIx_MISO_SOURCE               GPIO_PinSource4
    #define Open_SPIx_MISO_AF                   GPIO_AF_SPI1

    #define Open_SPIx_MOSI_PIN                  GPIO_Pin_5
    #define Open_SPIx_MOSI_GPIO_PORT            GPIOB
    #define Open_SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOB
    #define Open_SPIx_MOSI_SOURCE               GPIO_PinSource5
    #define Open_SPIx_MOSI_AF                   GPIO_AF_SPI1

#elif defined       SPI2_OPEN
    #define Open_SPIx_NSS_PIN                   GPIO_Pin_0
    #define Open_SPIx_NSS_PORT                  GPIOA
    #define Open_SPIx_NSS_GPIO_CLK              RCC_AHB1Periph_GPIOA
    //#define Open_SPIx_NSS_SOURCE                GPIO_PinSource10

    #define Open_SPIx                           SPI2
    #define Open_SPIx_CLK                       RCC_APB1Periph_SPI2
    #define Open_SPIx_CLK_INIT                  RCC_APB1PeriphClockCmd
    #define Open_SPIx_IRQn                      SPI2_IRQn
    #define Open_SPIx_IRQHANDLER                SPI2_IRQHandler

    #define Open_SPIx_SCK_PIN                   GPIO_Pin_13
    #define Open_SPIx_SCK_GPIO_PORT             GPIOB
    #define Open_SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOB
    #define Open_SPIx_SCK_SOURCE                GPIO_PinSource13
    #define Open_SPIx_SCK_AF                    GPIO_AF_SPI2

    #define Open_SPIx_MISO_PIN                  GPIO_Pin_14
    #define Open_SPIx_MISO_GPIO_PORT            GPIOB
    #define Open_SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOB
    #define Open_SPIx_MISO_SOURCE               GPIO_PinSource14
    #define Open_SPIx_MISO_AF                   GPIO_AF_SPI2

    #define Open_SPIx_MOSI_PIN                  GPIO_Pin_15
    #define Open_SPIx_MOSI_GPIO_PORT            GPIOB
    #define Open_SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOB
    #define Open_SPIx_MOSI_SOURCE               GPIO_PinSource15
    #define Open_SPIx_MOSI_AF                   GPIO_AF_SPI2

#elif defined       SPI3_OPEN
    #define Open_SPIx_NSS_PIN                   GPIO_Pin_0
    #define Open_SPIx_NSS_PORT                  GPIOA
    #define Open_SPIx_NSS_GPIO_CLK              RCC_AHB1Periph_GPIOA

    #define Open_SPIx                           SPI3
    #define Open_SPIx_CLK                       RCC_APB1Periph_SPI3
    #define Open_SPIx_CLK_INIT                  RCC_APB1PeriphClockCmd
    #define Open_SPIx_IRQn                      SPI3_IRQn
    #define Open_SPIx_IRQHANDLER                SPI3_IRQHandler

    #define Open_SPIx_SCK_PIN                   GPIO_Pin_10
    #define Open_SPIx_SCK_GPIO_PORT             GPIOC
    #define Open_SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOC
    #define Open_SPIx_SCK_SOURCE                GPIO_PinSource10
    #define Open_SPIx_SCK_AF                    GPIO_AF_SPI3

    #define Open_SPIx_MISO_PIN                  GPIO_Pin_11
    #define Open_SPIx_MISO_GPIO_PORT            GPIOC
    #define Open_SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOC
    #define Open_SPIx_MISO_SOURCE               GPIO_PinSource11
    #define Open_SPIx_MISO_AF                   GPIO_AF_SPI3

    #define Open_SPIx_MOSI_PIN                  GPIO_Pin_12
    #define Open_SPIx_MOSI_GPIO_PORT            GPIOC
    #define Open_SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOC
    #define Open_SPIx_MOSI_SOURCE               GPIO_PinSource12
    #define Open_SPIx_MOSI_AF                   GPIO_AF_SPI3

#else
    #error "Please select The COM to be used (in spi.h)"
#endif

#ifdef __cplusplus
}
#endif

#endif /* AS5048A_H_ */
