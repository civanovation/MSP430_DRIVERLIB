/**
 * @file spi.h
 * @author Naim MASRI (naimmas@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include "gpio.h"
#include "../common.h"
#include "msp430.h"


typedef enum{
    LSB_FIRST = 0, 
    MSB_FIRST = UCMSB
}SpiTxBit_t;

typedef enum{
    DATA_8_BIT = 0,
    DATA_7_BIT = UC7BIT
}SpiCharLength_t;

typedef enum{
    AUX_CLK = UCSSEL_1, 
    SM_CLK = UCSSEL_2
}SpiClkSource_t;

typedef enum{
    NO_INTERRUPT = 0,
    RX_INTERRUPT = UCB0RXIE,
    TX_INTERRUPT = UCB0TXIE,
    RXTX_INTERRUPT = UCB0RXIE | UCB0TXIE
}SpiInterruptMode_t;

typedef struct chipSelect_t
{
    uint8_t pin;
    uint8_t port;
}chipSelect_t;

void initSPI(chipSelect_t *cs_pin, SpiTxBit_t tx_bit, SpiClkSource_t clk_src, uint16_t clk_prescaler, SpiCharLength_t ch_len);
void SPI_EnableInterrupt(SpiInterruptMode_t ie_mode);
void SPI_Enable(bool state);
uint8_t SPI_WriteByte(uint8_t data);
uint8_t SPI_ReadByte(uint8_t dummy_char);
void SPI_WriteBuffer(uint8_t* buf, uint16_t size);
void SPI_ReadBuffer(uint8_t* buf, uint16_t size, uint8_t dummy_char);