/*
 * accelerometer.h
 *
 *  Created on: Nov 21, 2024
 *      Author: razva
 */

#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

#include <altera_up_avalon_accelerometer_spi.h>

void accelerometer_init(alt_up_accelerometer_spi_dev* accelerometer_device, const char* device_name);

void read_ADXL345_deviceID (alt_up_accelerometer_spi_dev *accelerometer_dev);

#endif /* ACCELEROMETER_H_ */
