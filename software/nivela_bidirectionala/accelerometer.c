/*
 * accelerometer.c
 *
 *  Created on: Nov 21, 2024
 *      Author: razva
 */
#include "accelerometer.h"
#include <string.h>
#include <stdio.h>

void accelerometer_init(alt_up_accelerometer_spi_dev* accelerometer_device, const char* device_name)
{
	accelerometer_device = alt_up_accelerometer_spi_open_dev(device_name);
	if(accelerometer_device != NULL)
		printf("Device found %s\r\n", device_name);
	else
		printf("Device not found %s \r\n", device_name);
}

void read_ADXL345_deviceID (alt_up_accelerometer_spi_dev *accelerometer_dev)
{
    uint32_t device_id_address = 0x00;	// Device ID address
    alt_u8 data = 0;

    int error = alt_up_accelerometer_spi_read(accelerometer_dev, device_id_address, &data);

    if (!error)
    {
        printf("Device ID is: 0x%X", data);
    }
}
