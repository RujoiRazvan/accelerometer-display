#include "hex_displays.h"

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
	{
		IOWR_ALTERA_AVALON_PIO_DATA(get_hex_address(hex_index), TURN_ON_UP_LEDS);
	}
	else
	{
		IOWR_ALTERA_AVALON_PIO_DATA(get_hex_address(hex_index), TURN_ON_DOWN_LEDS);
	}
}

void set_hex_state (alt_u8 state, alt_u8 hex_index)
{
	if(state)
		IOWR_ALTERA_AVALON_PIO_DATA(get_hex_address(hex_index), TURN_ON);	// Turn on 7Segment Display
	else
		IOWR_ALTERA_AVALON_PIO_DATA(get_hex_address(hex_index), TURN_OFF);	// Turn off 7Segment Display
}
