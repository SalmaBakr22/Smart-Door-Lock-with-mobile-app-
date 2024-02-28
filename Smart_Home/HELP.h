/*
 * HELP.h
 *
 *  Created on: Jan 30, 2024
 *      Author: WIN
 */

#ifndef HELP_H_
#define HELP_H_

typedef struct
{
	uint8 Name[10];
	uint8 Password[5];
}data;

extern data Users[10];


uint16 charToDecimal(uint16 u16charTodec);

#endif /* HELP_H_ */
