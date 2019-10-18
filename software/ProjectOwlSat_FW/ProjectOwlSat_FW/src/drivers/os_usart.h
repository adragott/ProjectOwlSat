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

#define DEBUG(str, ...) os_print(&debug_mod, (str), ##__VA_ARGS__)
#endif