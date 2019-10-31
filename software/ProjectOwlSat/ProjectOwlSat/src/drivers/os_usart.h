/*
 * os_usart.h
 *
 * Created: 10/10/2019 3:24:42 AM
 *  Author: penguin
 */ 
#ifndef _OS_USART_H_
#define _OS_USART_H_

#include "project_owlsat.h"
void os_usart_init(void);
void os_print(struct usart_module* mod, const char* str, ...);
void os_usart_service_start(void);
void os_gps_service_start(void);
// USART Debugging Module
struct usart_module debug_mod;
// USART GPS Module
struct usart_module gps_mod;

#define PDEBUG(str, ...) os_print(&debug_mod, (str), ##__VA_ARGS__)

/*! \brief Called by CDC interface
 * Callback running when CDC device have received data
 */
void debug_rx_notify(uint8_t port);

/*! \brief Configures communication line
 *
 * \param cfg      line configuration
 */
void debug_config(uint8_t port, usb_cdc_line_coding_t * cfg);

/*! \brief Opens communication line
 */
void debug_open(uint8_t port);

/*! \brief Closes communication line
 */
void debug_close(uint8_t port);

#endif