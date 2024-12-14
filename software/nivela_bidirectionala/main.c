#include "global.h"
#include "hex_displays.h"
#include "accelerometer.h"
#include "adc.h"

alt_up_accelerometer_spi_dev* accelerometer_device = NULL;

alt_up_adc_dev* adc_device = NULL;

int main()
{
	printf("Program start\r\n");
	hex_init(TURN_OFF);
	accelerometer_device = alt_up_accelerometer_spi_open_dev(ACCELEROMETER_SPI_0_NAME);
	adc_device = alt_up_adc_open_dev(ADC_0_NAME);

	if (adc_device != NULL)
		printf("ADC Device is initialised \r\n");
	read_ADXL345_deviceID(accelerometer_device);

	alt_32 y = 0, x = 0;
	static int state_x = 0;
	static int state_y = 0;
	int filtered_x, filtered_y;
	int y_inclination;
	while(1)
	{
		alt_up_accelerometer_spi_read_x_axis(accelerometer_device, &x);
		filtered_x = applyHysteresis(x, state_x, HYSTERESIS_THRESHOLD);

		alt_up_accelerometer_spi_read_y_axis(accelerometer_device, &y);
		filtered_y = applyHysteresis(y, state_y, HYSTERESIS_THRESHOLD);

		x = (filtered_x + 255) / 86;
		x = (x < 0) ? 0 : (x >= 6) ? 5 : x;
		if(IORD_ALTERA_AVALON_PIO_DATA(SW_0_BASE))
			y_inclination = (getAdcValue(adc_device) >> 4);
		else
			y_inclination = Y_INCLINATION;
		//printf("adc value: %d \r\n", y_inclination);
		if (filtered_y > y_inclination)
		{
			set_hex_value(TURN_ON_DOWN_LEDS, x);
		} else if (filtered_y < -y_inclination)
		{
			set_hex_value(TURN_ON_UP_LEDS, x);
		} else
		{
			set_hex_value(TURN_ON_MIDDLE_LINE, x);
		}
		for (int i = 0; i < 6; i++) { if (i != x) { set_hex_value(0xFF, i); } };

		state_y = filtered_y;
		state_x = filtered_x;
		usleep(10000);
	}

	return 0;
}
