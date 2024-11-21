/*
 * accelerometer.c
 *
 *  Created on: Nov 21, 2024
 *      Author: razva
 */
#include "accelerometer.h"

void accelerometer_init()
{
	alt_up_accelerometer_spi_dev* accelerometer_device = alt_up_accelerometer_spi_open_dev("/dev/accelerometer_spi_0");
	if(accelerometer_device != NULL)
		printf("Device found\r\n");
	else
		printf("Device not found\r\n");
}
