#include "global.h"
#include <alt_types.h>
#include <altera_avalon_pio_regs.h>

void hex_init (uint32_t hexState);

void set_hex_value (alt_u8 value, alt_u8 hex_index);

void set_hex_state (alt_u8 state, alt_u8 hex_index);
