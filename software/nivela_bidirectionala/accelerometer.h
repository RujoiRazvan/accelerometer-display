/*
 * accelerometer.h
 *
 *  Created on: Nov 21, 2024
 *      Author: razva
 */

#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

#include "global.h"
#include <altera_up_avalon_accelerometer_spi.h>

void read_ADXL345_deviceID (alt_up_accelerometer_spi_dev *accelerometer_dev);

void print_accelerometer_axis(alt_up_accelerometer_spi_dev *accelerometer_dev);

int applyHysteresis(int current_value, int previous_value, int threshold);

void CalibrateSensor(alt_up_accelerometer_spi_dev *accelerometer_dev, alt_32 *xOffset, alt_32 *yOffset);

#endif /* ACCELEROMETER_H_ */
