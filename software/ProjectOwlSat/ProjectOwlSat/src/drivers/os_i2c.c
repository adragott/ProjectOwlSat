/*
 * os_i2c.c
 *
 * Created: 10/16/2019 9:28:20 AM
 *  Author: Penguin
 */ 

#include "os_i2c.h"
#include <string.h>
#define OS_I2C_BUFFER_SIZE 256

struct i2c_master_module os_i2c_mod;
struct i2c_master_packet os_i2c_pkt;

volatile uint8_t i2c_master_buff[OS_I2C_BUFFER_SIZE];

int ctr = 0;

void os_i2c_write_byte(i2c_device* dev, uint8_t byte, _Bool bShouldStop)
{
	os_i2c_pkt.data[0] = 0x0;
	os_i2c_pkt.data[0] = byte;
	os_i2c_pkt.address = dev->addr;
	os_i2c_pkt.data_length = 1;
	if(bShouldStop)
	{
		#warning timeout handling
		while(i2c_master_write_packet_wait(&os_i2c_mod, &os_i2c_pkt) != STATUS_OK)
		{
			
		}

	}
	else
	{
		#warning add timeout handling
		while(i2c_master_write_packet_wait_no_stop(&os_i2c_mod, &os_i2c_pkt) != STATUS_OK)
		{
			
		}
	}
}

void os_i2c_write_bytes(i2c_device* dev, uint16_t numBytes, _Bool bShouldStop)
{
	#warning need to optimize this
	memset(os_i2c_pkt.data, '\0', numBytes);
	for(int x = 0; x < numBytes; x++)
	{
		os_i2c_pkt.data[x] = dev->buffer[x];
		//for debugging
	}
	#warning add timeout
	os_i2c_pkt.address = dev->addr;
	os_i2c_pkt.data_length = numBytes;
	enum status_code ret = STATUS_OK;
	if(bShouldStop)
	{
		while((ret = i2c_master_write_packet_wait(&os_i2c_mod, &os_i2c_pkt)) != STATUS_OK)
		{

			if(ctr++ >= 2000)
			{
				
				break;
			}
		}
		ctr = 0;
	}
	else
	{
		while(i2c_master_write_packet_wait_no_stop(&os_i2c_mod, &os_i2c_pkt) != STATUS_OK)
		{
			if(ctr++ >= 1000)
			{
				
				break;
			}
		}
		ctr = 0;
	}
}

void os_i2c_read(i2c_device* dev, uint16_t numBytes, _Bool bShouldStop)
{
	#warning add timeout
	//clear buffer just in case
	//weird things happen every now and then if I don't clear the buffer
	os_i2c_pkt.data = i2c_master_buff;
	memset(os_i2c_pkt.data, '\0', numBytes);
	os_i2c_pkt.address = dev->addr;
	os_i2c_pkt.data_length = numBytes;
	if(bShouldStop)
	{
		#warning add timeout handling
		while(i2c_master_read_packet_wait(&os_i2c_mod, &os_i2c_pkt) != STATUS_OK);
	}
	else
	{
		#warning add timeout handling
		while(i2c_master_read_packet_wait_no_stop(&os_i2c_mod, &os_i2c_pkt) != STATUS_OK);
	}
	
	//deliver the goods
	memcpy(dev->buffer, i2c_master_buff, numBytes);

}

void os_i2c_master_bus_init(void)
{
	struct i2c_master_config i2c_conf;
	i2c_master_get_config_defaults(&i2c_conf);
	i2c_conf.pinmux_pad0 = OS_I2C_PINMUX_PAD0;
	i2c_conf.pinmux_pad1 = OS_I2C_PINMUX_PAD1;
	i2c_conf.baud_rate = OS_I2C_CLOCK_SPEED;
	i2c_conf.baud_rate_high_speed = false;
	i2c_conf.run_in_standby = false;
	i2c_conf.generator_source = GCLK_GENERATOR_0;
	
	// packet init
	os_i2c_pkt.data = i2c_master_buff;
	os_i2c_pkt.data_length = 1;
	os_i2c_pkt.ten_bit_address = false;
	while(i2c_master_init(&os_i2c_mod, OS_I2C_SERCOM, &i2c_conf) != STATUS_OK);
	i2c_master_enable(&os_i2c_mod);
}

void os_i2c_write_bytes_no_ack(i2c_device* dev, uint8_t numBytes, uint16_t max_timeout)
{
	#warning need to optimize this
	memset(os_i2c_pkt.data, '\0', numBytes);
	memcpy(os_i2c_pkt.data, dev->buffer, numBytes);
	#warning add timeout
	os_i2c_pkt.address = dev->addr;
	os_i2c_pkt.address = numBytes;
	uint16_t timectr = 0;
	while(i2c_master_write_packet_wait_no_stop(&os_i2c_mod, &os_i2c_pkt) != STATUS_OK)
	{
		if(timectr++ >= max_timeout)
		{
			
			break;
		}
		ctr = 0;
	}
}