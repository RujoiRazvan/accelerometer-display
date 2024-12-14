/*
 * adc.c
 *
 *  Created on: Dec 14, 2024
 *      Author: razva
 */


#include "adc.h"

unsigned int getAdcValue(alt_up_adc_dev * adc)
{
	alt_up_adc_update (adc);
	return alt_up_adc_read(adc, 0);
}
