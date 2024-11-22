#include "hex_displays.h"
#include "accelerometer.h"
#include "global.h"
#include <unistd.h>
#include <altera_avalon_pio_regs.h>
#include <altera_up_avalon_accelerometer_spi.h>

alt_up_accelerometer_spi_dev* accelerometer_device = NULL;

int main()
{
	printf("Program start\r\n");
	hex_init(TURN_OFF);

	accelerometer_device = alt_up_accelerometer_spi_open_dev("/dev/accelerometer_spi_0");
	read_ADXL345_deviceID(accelerometer_device);

	alt_32 y;
	alt_32 y_inclination = 150;
	while(1)
	{
		alt_up_accelerometer_spi_read_y_axis(accelerometer_device, &y);
		if(y > y_inclination)
		{
			set_hex_circle(DOWN_LEDS, 0);
		}
		else if (y < (-y_inclination))
		{
			set_hex_circle(UP_LEDS, 0);
		}
		else
		{
			set_hex_state(1, 0);
		}
		usleep(10000);
	}

    return 0;
}
