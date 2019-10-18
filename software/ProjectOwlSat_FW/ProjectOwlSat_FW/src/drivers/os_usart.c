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

#define OS_PRINT_MAX_SIZE			(256)

volatile char debug_rx_val = '\0';

static void debug_rx_cb(struct usart_module* const mod);
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
	struct usart_config debug_conf;
	usart_get_config_defaults(&debug_conf);
	debug_conf.baudrate =		DEBUG_USART_MODULE;
	debug_conf.character_size = USART_CHARACTER_SIZE_8BIT;
	debug_conf.parity =			USART_PARITY_NONE;
	debug_conf.stopbits =		USART_STOPBITS_1;
	debug_conf.pinmux_pad0 =	DEBUG_USART_PINMUX_PAD0;
	debug_conf.pinmux_pad1 =	DEBUG_USART_PINMUX_PAD0;
	debug_conf.pinmux_pad2 =	DEBUG_USART_PINMUX_PAD0;
	debug_conf.pinmux_pad3 =	DEBUG_USART_PINMUX_PAD0;
	debug_conf.mux_setting =	DEBUG_USART_MUX_SETTING;
		
	usart_init(&debug_mod, DEBUG_USART_MODULE, &debug_conf);
	usart_enable(&debug_mod);
		
	usart_register_callback(&debug_mod, debug_rx_cb, USART_CALLBACK_BUFFER_RECEIVED);
	usart_enable_callback(&debug_mod, USART_CALLBACK_BUFFER_RECEIVED);
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
	os_print(&debug_mod, "%c", debug_rx_val);
	usart_read_job(&debug_mod, &debug_rx_val);
}

void gps_rx_cb(struct usart_module* const mod)
{
	
}