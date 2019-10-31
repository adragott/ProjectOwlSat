/*
 * os_i2c.h
 *
 * Created: 10/16/2019 9:26:40 AM
 *  Author: Penguin
 */ 
#ifndef _OS_I2C_H_
#define _OS_I2C_H_

#include "project_owlsat.h"

typedef struct i2c_device
{
	uint8_t addr;
	uint8_t* buffer;
	uint16_t buffer_size;
}i2c_device;

void os_i2c_write_bytes(i2c_device* dev, uint16_t numBytes, _Bool bShouldStop);
void os_i2c_write_byte(i2c_device* dev, uint8_t byte, _Bool bShouldStop);
void os_i2c_read(i2c_device* dev, uint16_t bytes_length, _Bool bShouldStop);
void os_i2c_master_bus_init(void);

//special i2c write used when you're not expecting an ack bit back -- useful for reset calls where slaves don't return ack bits before resarting
void os_i2c_write_bytes_no_ack(i2c_device* dev, uint8_t numBytes, uint16_t max_timeout);


#endif