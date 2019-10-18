#include <asf.h>
#include "main21.h"
#include "os_usart.h"
int main (void)
{
	system_init();
	owlsat_init();
	
	DEBUG("Hello World\n");
	for(;;)
	{
		
	}
}

void owlsat_init(void)
{
	os_usart_init();
}
