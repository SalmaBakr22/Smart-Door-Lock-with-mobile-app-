/*
 * BUZZER.c
 *
 *  Created on: Feb 6, 2024
 *      Author: WIN
 */
		/*----------------- Libraries and Definitions ------------*/
#include "BUZZER.h"

		/*------------------------- Function Definitions -----------------------------*/

void BUZZER_ON()
{
	DIO_enuSetPinValue(buzzer,1);
}

void BUZZER_OFF()
{
	DIO_enuSetPinValue(buzzer,0);
}

