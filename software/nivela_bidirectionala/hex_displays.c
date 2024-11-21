#include "hex_displays.h"
#include <string.h>
#include <system.h>

#define HEX_BASE_ADDR  HEX_0_BASE
#define HEX_OFFSET     0x10

#define TURN_ON_UP_LEDS ~0x63
#define TURN_ON_DOWN_LEDS ~0x5C

volatile uint32_t* get_hex_address(int hex_index)
{
    return (volatile uint32_t*)(HEX_BASE_ADDR + hex_index * HEX_OFFSET);
}

void hex_init (uint32_t hexState)
{
	for(int i = 0; i < 6; i++)
	{
		IOWR_ALTERA_AVALON_PIO_DATA(get_hex_address(i), hexState);
	}
}

void set_hex_circle (alt_u8 position, alt_u8 hex_index) {
	if (position)
		IOWR_ALTERA_AVALON_PIO_DATA(get_hex_address(hex_index), TURN_ON_UP_LEDS);
	else
		IOWR_ALTERA_AVALON_PIO_DATA(get_hex_address(hex_index), TURN_ON_DOWN_LEDS);
}
