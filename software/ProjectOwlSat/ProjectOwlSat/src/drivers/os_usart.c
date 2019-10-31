/*
 * os_usart.c
 *
 * Created: 10/10/2019 3:24:50 AM
 *  Author: penguin
 */ 
#include "os_usart.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct usart_config debug_conf;
/* Data for EDBG communication */
static uint8_t tx_data;
static uint8_t rx_data;

#define OS_PRINT_MAX_SIZE			(256)

volatile char debug_rx_val = '\0';

static void debug_rx_cb(struct usart_module* const mod);
static void debug_tx_cb(struct usart_module* const mod);

static void gps_rx_cb(struct usart_module* const mod);

static void os_debug_init(void);
static void os_gps_init(void);

void os_usart_init(void)
{
	#if ENABLE_DEBUG
	os_debug_init();
	#endif
	
	#if ENABLE_GPS
	os_gps_init();
	#endif
}

static void os_debug_init(void)
{
	//struct usart_config debug_conf;
	//usart_get_config_defaults(&debug_conf);
	//debug_conf.baudrate =		DEBUG_USART_BAUDRATE;
	//debug_conf.character_size = USART_CHARACTER_SIZE_8BIT;
	//debug_conf.parity =			USART_PARITY_NONE;
	//debug_conf.stopbits =		USART_STOPBITS_1;
	//debug_conf.pinmux_pad0 =	DEBUG_USART_PINMUX_PAD0;
	//debug_conf.pinmux_pad1 =	DEBUG_USART_PINMUX_PAD1;
	//debug_conf.pinmux_pad2 =	DEBUG_USART_PINMUX_PAD2;
	//debug_conf.pinmux_pad3 =	DEBUG_USART_PINMUX_PAD3;
	//debug_conf.mux_setting =	DEBUG_USART_MUX_SETTING;
	//
	//usart_init(&debug_mod, DEBUG_USART_MODULE, &debug_conf);
	//usart_enable(&debug_mod);
	//
	//usart_register_callback(&debug_mod, debug_rx_cb, USART_CALLBACK_BUFFER_RECEIVED);
	//usart_enable_callback(&debug_mod, USART_CALLBACK_BUFFER_RECEIVED);
}
static void os_gps_init(void)
{
	struct usart_config gps_conf;
	usart_get_config_defaults(&gps_conf);
	gps_conf.baudrate =			GPS_USART_MODULE;
	gps_conf.character_size =	USART_CHARACTER_SIZE_8BIT;
	gps_conf.parity =			USART_PARITY_NONE;
	gps_conf.stopbits =			USART_STOPBITS_1;
	gps_conf.pinmux_pad0 =		GPS_USART_PINMUX_PAD0;
	gps_conf.pinmux_pad1 =		GPS_USART_PINMUX_PAD0;
	gps_conf.pinmux_pad2 =		GPS_USART_PINMUX_PAD0;
	gps_conf.pinmux_pad3 =		GPS_USART_PINMUX_PAD0;
	gps_conf.mux_setting =		GPS_USART_MUX_SETTING;
	
	usart_init(&gps_mod, GPS_USART_MODULE, &gps_conf);
	usart_enable(&gps_mod);
	
	usart_register_callback(&gps_mod, gps_rx_cb, USART_CALLBACK_BUFFER_RECEIVED);
	usart_enable_callback(&gps_mod, USART_CALLBACK_BUFFER_RECEIVED);
	
}
void os_print(struct usart_module* mod, const char* str, ...)
{
	volatile uint8_t pprint_buffer[OS_PRINT_MAX_SIZE + 1];
	memset(pprint_buffer, '\0', OS_PRINT_MAX_SIZE + 1);
	va_list args;
	va_start(args, str);
	vsprintf(pprint_buffer, str, args);
	va_end(args);
	uint16_t strsize = (uint16_t)strlen(pprint_buffer);
	if(strsize > OS_PRINT_MAX_SIZE)
	{
		// return error
		return;
	}
	usart_write_buffer_wait(&debug_mod, pprint_buffer, strsize);
}

void os_usart_service_start(void)
{
	usart_read_job(&debug_mod, &debug_rx_val);
}

void debug_rx_cb(struct usart_module* const mod)
{
	/* Data received */
	ui_com_tx_start();

	/* Transfer UART RX fifo to CDC TX */
	if (!udi_cdc_is_tx_ready()) {
		/* Fifo full */
		udi_cdc_signal_overrun();
		ui_com_overflow();
		} else {
		udi_cdc_putc(rx_data);
	}

	ui_com_tx_stop();

	usart_read_buffer_job(&debug_mod, &rx_data, 1);

	return;
}


void debug_tx_cb(struct usart_module* const mod)
{
	/* Data ready to be sent */
	if (udi_cdc_is_rx_ready()) {
		/* Transmit next data */
		ui_com_rx_start();
		tx_data = udi_cdc_getc();
		usart_write_buffer_job(&debug_mod, &tx_data, 1);
		} else {
		/* Fifo empty then Stop UART transmission */
		usart_disable_callback(&debug_mod, USART_CALLBACK_BUFFER_TRANSMITTED);
		ui_com_rx_stop();
	}
}


void debug_rx_notify(uint8_t port)
{
	UNUSED(port);
	/* Transmit first data */
	ui_com_rx_start();
	usart_enable_callback(&debug_mod, USART_CALLBACK_BUFFER_TRANSMITTED);
	tx_data = udi_cdc_getc();
	usart_write_buffer_job(&debug_mod, &tx_data, 1);
}

void debug_config(uint8_t port,usb_cdc_line_coding_t *cfg)
{
	UNUSED(port);
	/* Configure USART for unit test output */
	usart_get_config_defaults(&debug_conf);
	debug_conf.generator_source = GCLK_GENERATOR_3;

	switch (cfg->bCharFormat) {
	case CDC_STOP_BITS_2:
		debug_conf.stopbits = USART_STOPBITS_2;
		break;

	case CDC_STOP_BITS_1_5:
		debug_conf.stopbits = USART_STOPBITS_1;
		break;

	case CDC_STOP_BITS_1:
	default:
		/* Default stop bit = 1 stop bit */
		debug_conf.stopbits = USART_STOPBITS_1;
		break;
	}

	switch (cfg->bParityType) {
	case CDC_PAR_EVEN:
		debug_conf.parity = USART_PARITY_EVEN;
		break;

	case CDC_PAR_ODD:
		debug_conf.parity = USART_PARITY_ODD;
		break;

	case CDC_PAR_MARK:
		debug_conf.parity = USART_PARITY_NONE;
		break;

	case CDC_PAR_SPACE:
		debug_conf.parity = USART_PARITY_NONE;
		break;

	case CDC_PAR_NONE:
	default:
		debug_conf.parity = USART_PARITY_NONE;
		break;
	}

	switch(cfg->bDataBits) {
	case 5:
		debug_conf.character_size = USART_CHARACTER_SIZE_5BIT;
		break;
	case 6:
		debug_conf.character_size = USART_CHARACTER_SIZE_6BIT;
		break;
	case 7:
		debug_conf.character_size = USART_CHARACTER_SIZE_7BIT;
		break;
	case 8:
	default:
		debug_conf.character_size = USART_CHARACTER_SIZE_8BIT;
		break;
	}

	/* Options for USART. */
	debug_conf.baudrate = LE32_TO_CPU(cfg->dwDTERate);
	debug_conf.mux_setting = DEBUG_USART_MUX_SETTING;
	debug_conf.pinmux_pad0 = DEBUG_USART_PINMUX_PAD0;
	debug_conf.pinmux_pad1 = DEBUG_USART_PINMUX_PAD1;
	debug_conf.pinmux_pad2 = DEBUG_USART_PINMUX_PAD2;
	debug_conf.pinmux_pad3 = DEBUG_USART_PINMUX_PAD3;
	usart_disable(&debug_mod);
	usart_init(&debug_mod, DEBUG_USART_MODULE, &debug_conf);
	usart_enable(&debug_mod);

	/* Enable interrupts */
	usart_register_callback(&debug_mod, debug_tx_cb,
			USART_CALLBACK_BUFFER_TRANSMITTED);
	usart_enable_callback(&debug_mod, USART_CALLBACK_BUFFER_TRANSMITTED);
	usart_register_callback(&debug_mod, debug_rx_cb,
			USART_CALLBACK_BUFFER_RECEIVED);
	usart_enable_callback(&debug_mod, USART_CALLBACK_BUFFER_RECEIVED);
	usart_read_buffer_job(&debug_mod, &rx_data, 1);
}

void debug_open(uint8_t port)
{
	UNUSED(port);

	usart_enable(&debug_mod);
}

void debug_close(uint8_t port)
{
	UNUSED(port);
	/* Close RS232 communication */
	usart_disable(&debug_mod);
}


void gps_rx_cb(struct usart_module* const mod)
{
	
}

