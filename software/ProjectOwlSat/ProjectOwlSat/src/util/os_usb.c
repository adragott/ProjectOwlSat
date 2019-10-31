/*
 * os_usb.c
 *
 * Created: 10/31/2019 5:16:19 PM
 *  Author: penguin
 */ 

#include "os_usb.h"

static volatile bool main_b_msc_enable = false;
static volatile bool main_b_cdc_enable = false;

void main_suspend_action(void)
{
	ui_powerdown();
}

void main_resume_action(void)
{
	ui_wakeup();
}

void main_sof_action(void)
{
	if ((!main_b_msc_enable) ||
		(!main_b_cdc_enable))
		return;
	ui_process(udd_get_frame_number());
}

/*! \brief Example of extra USB string management
 * This feature is available for single or composite device
 * which want implement additional USB string than
 * Manufacture, Product and serial number ID.
 *
 * return true, if the string ID requested is know and managed by this functions
 */
bool main_extra_string(void)
{
	static uint8_t udi_cdc_name[] = "CDC interface";
	static uint8_t udi_msc_name[] = "MSC interface";

	struct extra_strings_desc_t{
		usb_str_desc_t header;
		le16_t string[Max(sizeof(udi_cdc_name)-1, sizeof(udi_msc_name)-1)];
	};
	static UDC_DESC_STORAGE struct extra_strings_desc_t extra_strings_desc = {
		.header.bDescriptorType = USB_DT_STRING
	};

	uint8_t i;
	uint8_t *str;
	uint8_t str_lgt=0;

	// Link payload pointer to the string corresponding at request
	switch (udd_g_ctrlreq.req.wValue & 0xff) {
	case UDI_CDC_IAD_STRING_ID:
		str_lgt = sizeof(udi_cdc_name)-1;
		str = udi_cdc_name;
		break;
	default:
		return false;
	}

	if (str_lgt!=0) {
		for( i=0; i<str_lgt; i++) {
			extra_strings_desc.string[i] = cpu_to_le16((le16_t)str[i]);
		}
		extra_strings_desc.header.bLength = 2+ (str_lgt)*2;
		udd_g_ctrlreq.payload_size = extra_strings_desc.header.bLength;
		udd_g_ctrlreq.payload = (uint8_t *) &extra_strings_desc;
	}

	// if the string is larger than request length, then cut it
	if (udd_g_ctrlreq.payload_size > udd_g_ctrlreq.req.wLength) {
		udd_g_ctrlreq.payload_size = udd_g_ctrlreq.req.wLength;
	}
	return true;
}

bool main_msc_enable(void)
{
	main_b_msc_enable = true;
	return true;
}

void main_msc_disable(void)
{
	main_b_msc_enable = false;
}

bool main_cdc_enable(uint8_t port)
{
	main_b_cdc_enable = true;
	// Open communication
	debug_open(port);
	return true;
}

void main_cdc_disable(uint8_t port)
{
	main_b_cdc_enable = false;
	// Close communication
	debug_close(port);
}

void main_cdc_set_dtr(uint8_t port, bool b_enable)
{
	if (b_enable) {
		// Host terminal has open COM
		ui_com_open(port);
	}else{
		// Host terminal has close COM
		ui_com_close(port);
	}
}

void ui_init(void)
{
	/* Initialize LEDs */
	LED_On(LED_0_PIN);
}

void ui_powerdown(void)
{
	LED_Off(LED_0_PIN);
}

void ui_wakeup(void)
{
	LED_On(LED_0_PIN);
}


void ui_com_open(uint8_t port)
{
	UNUSED(port);
}


void ui_com_close(uint8_t port)
{
	UNUSED(port);
}


void ui_com_rx_start(void)
{

}


void ui_com_rx_stop(void)
{

}


void ui_com_tx_start(void)
{

}


void ui_com_tx_stop(void)
{

}


void ui_com_error(void)
{

}


void ui_com_overflow(void)
{

}

void ui_start_read(void)
{
}

void ui_stop_read(void)
{
}

void ui_start_write(void)
{
}

void ui_stop_write(void)
{
	
}

void ui_process(uint16_t framenumber)
{
	if ((framenumber % 1000) == 0) {
		LED_On(LED_0_PIN);
	}
	if ((framenumber % 1000) == 500) {
		LED_Off(LED_0_PIN);
	}
}
