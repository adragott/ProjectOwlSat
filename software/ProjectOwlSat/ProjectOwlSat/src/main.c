#include "project_owlsat.h"
#include "main21.h"
#include "os_usart.h"
#include "os_i2c.h"

int main(void)
{
	irq_initialize_vectors();
	cpu_irq_enable();

	// Initialize the sleep manager
	sleepmgr_init();
	system_init();
	system_interrupt_enable_global();
	//os_usart_init();
	//os_usart_service_start();
	//PDEBUG("hi\r\n");
	ui_init();
	ui_powerdown();


	// Start USB stack to authorize VBus monitoring
	udc_start();
	// The main loop manages only the power mode
	// because the USB management is done by interrupt
	for(;;)
	{
		sleepmgr_enter_sleep();
	}
	
	return 0;
}