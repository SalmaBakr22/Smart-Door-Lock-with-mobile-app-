/*
 * HELP.c
 *
 *  Created on: Jan 30, 2024
 *      Author: WIN
 */

#include "STD_Types.h"
#include "HELP.h"

data Users[10]=
{
		{{"Ali"},{"1111"}},
		{{"Salma"},{"2222"}},
		{{"Ahmed"},{"3333"}},
		{{"Mohamed"},{"4444"}},
		{{"Mona"},{"5555"}},
		{{"Soha"},{"6666"}},
		{{"Eman"},{"7777"}},
		{{"Ansam"},{"8888"}},
		{{"Doha"},{"9999"}},
		{{"Omar"},{"0000"}},

};


uint16 charToDecimal(uint16 u16charTodec)
{
	u16charTodec-=48;
   return u16charTodec;
}
