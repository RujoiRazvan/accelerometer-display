/*
 * accelerometer.c
 *
 *  Created on: Nov 21, 2024
 *      Author: razva
 */
#include "accelerometer.h"

void read_ADXL345_deviceID (alt_up_accelerometer_spi_dev *accelerometer_dev)
{
    alt_u32 device_id_address = 0x00;	// Accelerometer ID address
    alt_u8 data = 0;

    int error = alt_up_accelerometer_spi_read(accelerometer_dev, device_id_address, &data);

    if (!error)
    {
        printf("Accelerometer ID: 0x%X", data);
    }
    else
    	printf("Wrong Accelerometer ID\r\n");
}

void print_accelerometer_axis(alt_up_accelerometer_spi_dev *accelerometer_dev)
{
	alt_32 x = 0;
	alt_32 y = 0;
	alt_32 z = 0;
	alt_up_accelerometer_spi_read_x_axis(accelerometer_dev, &x);
	alt_up_accelerometer_spi_read_y_axis(accelerometer_dev, &y);
	alt_up_accelerometer_spi_read_z_axis(accelerometer_dev, &z);
	printf("x: %d, y: %d, z: %d \r\n", x, y, z);
}

int applyHysteresis(int current_value, int previous_value, int threshold)
{
    if (abs(current_value - previous_value) > threshold) {
        return current_value;
    } else {
        return previous_value;
    }
}

void CalibrateSensor(alt_up_accelerometer_spi_dev *accelerometer_dev, alt_32 *xOffset, alt_32 *yOffset)
{
	alt_up_accelerometer_spi_read_x_axis(accelerometer_dev, xOffset);
	alt_up_accelerometer_spi_read_y_axis(accelerometer_dev, yOffset);
}
