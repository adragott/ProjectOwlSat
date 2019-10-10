/**
 * \file
 *
 * \brief SD/MMC stack configuration file.
 *
 * Copyright (c) 2014-2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef CONF_SD_MMC_H_INCLUDED
#define CONF_SD_MMC_H_INCLUDED

/* Define to enable the SPI mode instead of Multimedia Card interface mode */
#define SD_MMC_SPI_MODE

/* Define to enable the SDIO support */
//#define SDIO_SUPPORT_ENABLE

/* Define to enable the debug trace to the current standard output (stdio) */
//#define SD_MMC_DEBUG

/* Define to memory count */
#define SD_MMC_SPI_MEM_CNT          1

///* Select the SPI module SD/MMC is connected to */
//#ifdef EXT1_SPI_MODULE /* Default configuration for Xplained Pro kit */
//#  define SD_MMC_SPI                 SERCOM0
//#  define SD_MMC_SPI_PINMUX_SETTING  SPI_SIGNAL_MUX_SETTING_E
//#  define SD_MMC_SPI_PINMUX_PAD0     PINMUX_PA04D_SERCOM0_PAD0
//#  define SD_MMC_SPI_PINMUX_PAD1     PINMUX_PA05D_SERCOM0_PAD1
//#  define SD_MMC_SPI_PINMUX_PAD2     PINMUX_PA06D_SERCOM0_PAD2
//#  define SD_MMC_SPI_PINMUX_PAD3     PINMUX_PA07D_SERCOM0_PAD3
//
//#  define SD_MMC_CS                  EXT1_PIN_15
//
//#  define SD_MMC_0_CD_GPIO           (EXT1_PIN_10)
//#  define SD_MMC_0_CD_DETECT_VALUE   0
//#else /* Dummy configuration */
//#  define SD_MMC_SPI                 0
//#  define SD_MMC_SPI_PINMUX_SETTING  0
//#  define SD_MMC_SPI_PINMUX_PAD0     0
//#  define SD_MMC_SPI_PINMUX_PAD1     0
//#  define SD_MMC_SPI_PINMUX_PAD2     0
//#  define SD_MMC_SPI_PINMUX_PAD3     0
//
//#  define SD_MMC_CS                  0
//
//#  define SD_MMC_0_CD_GPIO           0
//#  define SD_MMC_0_CD_DETECT_VALUE   0
//#endif

#define SD_MMC_SPI                 SD_CARD_SPI
#define SD_MMC_SPI_PINMUX_SETTING  SD_CARD_SPI_PINMUX_SETTING
#define SD_MMC_SPI_PINMUX_PAD0     SD_CARD_SPI_PINMUX_PAD0
#define SD_MMC_SPI_PINMUX_PAD1     SD_CARD_SPI_PINMUX_PAD1
#define SD_MMC_SPI_PINMUX_PAD2     SD_CARD_SPI_PINMUX_PAD2
#define SD_MMC_SPI_PINMUX_PAD3     SD_CARD_SPI_PINMUX_PAD3

#define SD_MMC_CS                  SD_CARD_CS

#define SD_MMC_0_CD_GPIO           SD_CARD_CD
#define SD_MMC_0_CD_DETECT_VALUE   SD_CARD_CD_DETECT_VALUE
/* Define the SPI clock source */
#define SD_MMC_SPI_SOURCE_CLOCK    GCLK_GENERATOR_0

/* Define the SPI max clock */
#define SD_MMC_SPI_MAX_CLOCK       SD_CARD_CLOCK_SPEED

#endif /* CONF_SD_MMC_H_INCLUDED */

