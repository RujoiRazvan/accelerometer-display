#include "hex_displays.h"
#include <system.h>
#include <altera_avalon_pio_regs.h>

#define UP_LEDS 1
#define DOWN_LEDS 0

#define TURN_OFF 0xFFFF
#define TURN_ON ~TURN_OFF

int main()
{
	printf("Program start\r\n");
	hex_init(TURN_OFF);
	while(1)
	{
	}

    return 0;
}
