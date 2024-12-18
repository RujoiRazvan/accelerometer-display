#include "global.h"
#include "hex_displays.h"
#include "accelerometer.h"
#include "adc.h"
#include <math.h>

alt_up_accelerometer_spi_dev* accelerometer_device = NULL;

alt_up_adc_dev* adc_device = NULL;

// ADC MAX VALUE: ~3943
// ADC MIN VALUE: 2 / 3
int main()
{
	printf("Program start\r\n");
	hex_init(TURN_OFF);
	accelerometer_device = alt_up_accelerometer_spi_open_dev(ACCELEROMETER_SPI_0_NAME);
	adc_device = alt_up_adc_open_dev(ADC_0_NAME);

	if (adc_device != NULL)
		printf("ADC device is initialized \r\n");
	read_ADXL345_deviceID(accelerometer_device);

	alt_32 y = 0, x = 0;
	static int state_x = 0;
	static int state_y = 0;
	int filtered_x, filtered_y;
	int y_inclination, x_sensibility = 86;
	while(1)
	{
		alt_up_accelerometer_spi_read_x_axis(accelerometer_device, &x);
		filtered_x = applyHysteresis(x, state_x, HYSTERESIS_THRESHOLD);

		alt_up_accelerometer_spi_read_y_axis(accelerometer_device, &y);
		filtered_y = applyHysteresis(y, state_y, HYSTERESIS_THRESHOLD);
		//printf("x: %d  y: %d", filtered_x, filtered_y);
		x = (filtered_x * 6) / (2 * x_sensibility);
		x += 2;
		x = (x < 0) ? 0 : (x >= 6) ? 5 : x;
		if (IORD_ALTERA_AVALON_PIO_DATA(SW_0_BASE)) {
		        y_inclination = (getAdcValue(adc_device) >> 4);
		        if (IORD_ALTERA_AVALON_PIO_DATA(SW_1_BASE))
		        {
		            int raw_adc_value = getAdcValue(adc_device);
		            x_sensibility = 10 + DIV_3941((raw_adc_value - 2) * 190);	// 10 + ((raw_adc_value - 2) * (200 - 10)) / (3943 - 2)
		            x_sensibility = max(10, x_sensibility);
		        }
		        else
		        {
		        	x_sensibility = 86;
		        }
		    } else {
		        y_inclination = Y_INCLINATION;
		    }
		//printf("adc value: %d \r\n", getAdcValue(adc_device));
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
		//printf("x_sensibility: %d    y_inclination: %d\r\n", x_sensibility, y_inclination);
		state_y = filtered_y;
		state_x = filtered_x;
		usleep(10000);
	}

	return 0;
}
