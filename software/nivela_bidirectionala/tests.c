/*
 * tests.c
 *
 *  Created on: Nov 21, 2024
 *      Author: razva
 */

#include "hex_displays.h"

void test_hex_displays()
{
	for(int i = 0; i < 6; i++)
	{
		set_hex_circle(1, i);
		for(int j = 0; j < 1000000; j++)
			;
	}
	for(int i = 0; i < 6; i++)
		{
			set_hex_circle(0, i);
			for(int j = 0; j < 1000000; j++)
				;
		}
}
