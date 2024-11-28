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

#endif /* ACCELEROMETER_H_ */
