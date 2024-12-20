/*
 * global.h
 *
 *  Created on: Nov 22, 2024
 *      Author: razva
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <string.h>
#include <stdio.h>
#include <system.h>
#include <unistd.h>
#include <altera_up_avalon_accelerometer_spi.h>
#include <altera_up_avalon_adc.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define DIV_3941(value) (((value) * 17) >> 16)


#define HEX_BASE_ADDR  HEX_0_BASE
#define HEX_OFFSET     0x10

#define TURN_ON_UP_LEDS ~0x63
#define TURN_ON_DOWN_LEDS ~0x5C

#define TURN_ON_MIDDLE_LINE 0xBF

#define UP_LEDS 1
#define DOWN_LEDS 0

#define TURN_OFF 0xFF
#define TURN_ON 0x80	// Do not turn on DP

#define HYSTERESIS_THRESHOLD 30
#define Y_INCLINATION 50

#endif /* GLOBAL_H_ */
