/*
 * File
 */

#include "main.h"

int main(void)
	{	
	//uint8_t blink=1;
	//initialize system
	SystemInit();
	//initialize UART5 with 8-N-1 settings, 57600 baudrate
	init_uart(UART5_BASE_PTR,periph_clk_khz,57600);

	//clear all interrupts and enable interrupts
	nvic->ICPR[2] |= 1 << (87 & 0x1F); //Clear Pending Interrupts
	nvic->ISER[2] |= 1 << (87 & 0x1F); //Enable Interrupts
	
	//initialize GPIO ports
	gpio_init();

	//Loop forever
	while(1)
	{
		//use polling method to echo back data when available
		if(data_available())
		{ 
			byte = uart_read();
			if(byte==0xD)
			{ 
				puts((uint8_t *)"\r\n"); //send new line character
			//0 to 9 ascii code in hexadecimal 
			}
			else if ((byte >= 0x30) && (byte <= 0x39)) 
			{
				byte = byte - 0x30; display(byte);
			
			//small case letters a to f ascii code in hexadecimal
			}
			else if ((byte >= 0x61) && (byte <= 0x66))
			{
				byte = byte - 0x57; display(byte);
			}
			else if((byte >= 0x41) && (byte <= 0x46))
			{
				byte = byte - 0x37; display(byte);
				}
				else
				{
					display(byte);
				}
		}
	}
}


*/
void delay(void)
{
  volatile unsigned int x,y;

  for(x=0; x<1000; x++)
  {
	for(y=0; y<300; y++)
      __asm__("nop");
  }
}

