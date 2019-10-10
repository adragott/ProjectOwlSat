/**
 * \file
 *
 * \brief SAM D21 Xplained Pro board configuration.
 *
 * Copyright (c) 2013-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#ifndef CONF_BOARD_H_INCLUDED
#define CONF_BOARD_H_INCLUDED

// Debug Terminal Config
// GPS Config
#define DEBUG_USART_MODULE			SERCOM3
#define DEBUG_USART_PINMUX_PAD0		PINMUX_PA22C_SERCOM3_PAD0
#define DEBUG_USART_PINMUX_PAD1		PINMUX_PA23C_SERCOM3_PAD1
#define DEBUG_USART_PINMUX_PAD2		PINMUX_UNUSED
#define DEBUG_USART_PINMUX_PAD3		PINMUX_UNUSED
#define DEBUG_USART_BAUDRATE		115200
#define DEBUG_USART_MUX_SETTING		USART_RX_1_TX_0_XCK_1

// GPS Config
#define GPS_USART_MODULE			SERCOM4
#define GPS_USART_PINMUX_PAD0		PINMUX_UNUSED
#define GPS_USART_PINMUX_PAD1		PINMUX_UNUSED
#define GPS_USART_PINMUX_PAD2		PINMUX_PB10D_SERCOM4_PAD2
#define GPS_USART_PINMUX_PAD3		PINMUX_PB11D_SERCOM4_PAD3
#define GPS_USART_BAUDRATE			9600
// Mux Setting info found here: http://asf.atmel.com/docs/latest/samd21/html/asfdoc_sam0_sercom_usart_mux_settings.html
#define GPS_USART_MUX_SETTING		USART_RX_3_TX_2_XCK_3

// OwlSat System Memory Config
// SD Card and AT25x Flash both use this sercom so they will both use these settings
// This way I can move the memory modules around without changing much code
#define OS_SYS_MEM_SERCOM			SERCOM5
#define OS_SYS_MEM_PINMUX_SETTING	SPI_SIGNAL_MUX_SETTING_E
#define OS_SYS_MEM_PINMUX_PAD0		PINMUX_PB16C_SERCOM5_PAD0
#define OS_SYS_MEM_PINMUX_PAD1		PINMUX_UNUSED
#define OS_SYS_MEM_PINMUX_PAD2		PINMUX_PB22D_SERCOM5_PAD2
#define OS_SYS_MEM_PINMUX_PAD3		PINMUX_PB23D_SERCOM5_PAD3
#define OS_SYS_MEM_CLOCK_SPEED		(10000000)

// SD Card Config
#define SD_CARD_SPI					OS_SYS_MEM_SERCOM
#define SD_CARD_SPI_PINMUX_SETTING	OS_SYS_MEM_PINMUX_SETTING
#define SD_CARD_SPI_PINMUX_PAD0		OS_SYS_MEM_PINMUX_PAD0
#define SD_CARD_SPI_PINMUX_PAD1		OS_SYS_MEM_PINMUX_PAD1
#define SD_CARD_SPI_PINMUX_PAD2		OS_SYS_MEM_PINMUX_PAD2
#define SD_CARD_SPI_PINMUX_PAD3		OS_SYS_MEM_PINMUX_PAD3
#define SD_CARD_CS					PIN_PA10
#define SD_CARD_CD					PIN_PA11
#define SD_CARD_CD_DETECT_VALUE		(1)
#define SD_CARD_CLOCK_SPEED			OS_SYS_MEM_CLOCK_SPEED

// AT25x (Flash Memory) Config
#define AT25DFX_SPI                 OS_SYS_MEM_SERCOM
/** AT25DFx device type */
#define AT25DFX_MEM_TYPE            AT25DFX_081A
#define AT25DFX_SPI_PINMUX_SETTING  OS_SYS_MEM_PINMUX_SETTING
#define AT25DFX_SPI_PINMUX_PAD0     OS_SYS_MEM_PINMUX_PAD0
#define AT25DFX_SPI_PINMUX_PAD1     OS_SYS_MEM_PINMUX_PAD1
#define AT25DFX_SPI_PINMUX_PAD2		OS_SYS_MEM_PINMUX_PAD2
#define AT25DFX_SPI_PINMUX_PAD3		OS_SYS_MEM_PINMUX_PAD3
#define AT25DFX_CS                  SERIALFLASH_SPI_CS
#define AT25DFX_CLOCK_SPEED         OS_SYS_MEM_CLOCK_SPEED


// OwlSat I2C Bus config (Sensor Bus)
// Sensors will use this bus
// Same principle as the system memory bus -- I can move the sensors to different sercoms if I need to easier this way
#define OS_I2C_SERCOM				SERCOM2
#define OS_I2C_PINMUX_PAD0			PINMUX_PA08D_SERCOM2_PAD0
#define OS_I2C_PINMUX_PAD1			PINMUX_PA09D_SERCOM2_PAD1
#define OS_I2C_PINMUX_PAD2			PINMUX_UNUSED
#define OS_I2C_PINMUX_PAD3			PINMUX_UNUSED
#define OS_I2C_CLOCK_SPEED			I2C_MASTER_BAUD_RATE_400KHZ


#endif /* CONF_BOARD_H_INCLUDED */
