/*
 * as5048a.c
 *
 *  Created on: 18 Nis 2019
 *      Author: fatih.akgul
 */

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "stm32f4xx_conf.h"
#include "stm32f4xx_spi.h"
#include "as5048a.h"

u16 SPI_ReadWriteData(u16 data)
{
    while(SPI_I2S_GetFlagStatus(Open_SPIx, SPI_I2S_FLAG_TXE)==RESET);
    SPI_I2S_SendData(Open_SPIx,data);

    while(SPI_I2S_GetFlagStatus(Open_SPIx, SPI_I2S_FLAG_RXNE)==RESET);
    return SPI_I2S_ReceiveData(Open_SPIx);
}

uint16_t SPI2_Read5048Data(uint16_t TxData)
{
    uint16_t data;
    GPIO_ResetBits(Open_SPIx_NSS_PORT, Open_SPIx_NSS_PIN);
    data = SPI_ReadWriteData(TxData);
   // GPIO_SetBits(Open_SPIx_NSS_PORT, Open_SPIx_NSS_PIN);
   // delay_ms(1);
    //GPIO_ResetBits(Open_SPIx_NSS_PORT, Open_SPIx_NSS_PIN);
    //data=SPI_ReadWriteData(CMD_NOP);
    GPIO_SetBits(Open_SPIx_NSS_PORT, Open_SPIx_NSS_PIN);
    //delay_ms(1);
    //data = data & 0x3FFF;
    return data;
}

struct as5048_data CollectData()
{
    uint16_t anglereg = 0, magreg = 0, agcreg = 0;
    uint16_t mag = 0, value = 0;
    double angle = 0.0;
    uint8_t agc = 0;
    struct as5048_data Temp = {1,0,0,0,0.0};

    SPI2_Read5048Data(CMD_ANGLE);
    SPI2_Read5048Data(CMD_ANGLE);
    anglereg = SPI2_Read5048Data(CMD_MAG); value = anglereg & 0x3fff;
    magreg = SPI2_Read5048Data(CMD_AGC);   mag = magreg & 0x3fff;
    agcreg = SPI2_Read5048Data(CMD_NOP);   agc = (uint8_t)agcreg & 0x00ff;
    angle = (value * 360.0)/16384.0;
   // angle = value * 0.0219;



    /*printf("%d\n anglereg = ",anglereg);
    delay_ms(1500);
    printf("%d\n magreg = ",magreg);
    delay_ms(1500);
    printf("%d\n agcreg = ",agcreg);
    delay_ms(1500);
    printf("%d\n value = ",value);
    delay_ms(1500);*/
     printf("angle = %d\n",angle);

 /*   if(angle = 0)
    {
    	ClearAndNop();
    }
*/
    if ((anglereg & 0x4000) | (magreg & 0x4000) | (agcreg & 0x4000))
    {
        ClearAndNop();
        printf("There is and error!\n");
        Temp.iserror = 1;
    }
    else
    {
        Temp.iserror = 0;
        Temp.angle = angle;
        Temp.mag = mag;
        Temp.agc = agc;
        Temp.value = value;
    }
    return Temp;
 }
// as5048 net hata bayraðý
u16 ClearAndNop(void)
{
    GPIO_ResetBits(Open_SPIx_NSS_PORT, Open_SPIx_NSS_PIN);
    SPI2_Read5048Data(0x4001);              //Ek eþlik hatasý bayraðý Temizle komutu
    GPIO_SetBits(Open_SPIx_NSS_PORT, Open_SPIx_NSS_PIN);
    delay_us(1000);              //Datasheette komutlar arasýnda 350ns aralýðý vardýr
    GPIO_ResetBits(Open_SPIx_NSS_PORT, Open_SPIx_NSS_PIN);
    SPI2_Read5048Data(0xc000);               // Ek eþlik hatasý bayraðý Temizle komutu
    GPIO_SetBits(Open_SPIx_NSS_PORT, Open_SPIx_NSS_PIN);
}
