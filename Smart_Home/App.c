/*
 * APP.C
 *
 *  Created on: Oct 11, 2023
 *      Author: WIN
 */

#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_Types.h"
#include "BIT_Math.h"
#include "HELP.h"

#include "DIO.h"
#include "EXT0.h"
#include "USART.h"

#include "BUZZER.h"


#define BUFFER_SIZE 10
#define DecimalNums_SIZE 2
#define BUTTON 26
/*************** Variables in the main code ******************/
uint8 Check;
uint8 name_check;
uint8 password_check;
uint8 index_check_name;
uint8 index;
uint8 index_check_pass;
uint8 Buzzer_warning;
uint8 correct_names_check[BUFFER_SIZE];
/************* Variables in the Recive function ****************/
uint8 Access=10;
uint8 name[BUFFER_SIZE];
uint8 password[BUFFER_SIZE];
volatile uint8 name_index = 0;
volatile uint8 password_index = 0;
volatile uint8 receiving_password = 0;

uint16 DecimalNum;
volatile uint16 DecimalNums[DecimalNums_SIZE];
volatile uint8  DecimalNums_index = 0;

void Recive(void)
{

	uint8 received_char = USART_Receive();

	if(Access==0)
	{
		if (received_char == ',') {
			// Switch to receiving password
			receiving_password = 1;
			name[name_index] = '\0'; // Null-terminate the name string
			name_check = name_index;
			name_index = 0;
		} else if (received_char == '\n') {
			// End of transmission, process the received data
			password[password_index] = '\0'; // Null-terminate the password string
			password_check = password_index;
			password_index = 0;
			receiving_password = 0;
			Access=10;   //Any value
			Check=1;

		} else {
			// Store the received character in the appropriate buffer
			if (receiving_password && password_index < BUFFER_SIZE - 1) {
				password[password_index++] = received_char;
			} else if (!receiving_password && name_index < BUFFER_SIZE - 1) {
				name[name_index++] = received_char;
			}
		}
	}

	if(Access==1)
	{
		DecimalNum = charToDecimal(received_char);         //convert char to decimal
		DecimalNums[DecimalNums_index++] = DecimalNum;     //Put the decimal into an array

		if(DecimalNums_index == 2)
		{
			DIO_enuSetPinValue((DecimalNums[0]) , (DecimalNums[1]));   //The first number represents the pin number and the second number represents its status
			DecimalNums_index = 0;                                     //Return everything to its original state
			Access=10;                                                 //Any value except 0,1
		}
	}

	if(received_char == '*')  //before the name in app
	{
		Access=0;
	}
	else if (received_char == '#')  //before any control buttons in app
	{
		Access=1;
	}
}

int main(void)
{
	DIO_vidInit();
	EXT0_vidInit();
	USART_vidInit();

	USART_vidSetCallBack_Rx(Recive);
	USART_vidEnable_RX_Int();
	EXT0_vidSetCallBack(BUZZER_OFF);
	EXT0_vidEnable();
	GIE_VIDEnable();

	DIO_enuSetPinPullUp(BUTTON , 1);

	while(1)
	{

		if(Check==1)
		{
			if(password_check == 4)
			{
				index=0;
				for (uint8 u8CntrName_OUTER = 0; u8CntrName_OUTER < BUFFER_SIZE; u8CntrName_OUTER++ )   //BUFFER_SIZE=10
				{
					for (uint8 u8CntrName_INNER = 0; u8CntrName_INNER < name_check; u8CntrName_INNER++ )
					{
						if ( name[u8CntrName_INNER] ==  Users[u8CntrName_OUTER].Name[u8CntrName_INNER] )
						{
							index_check_name ++;
						}
						else
						{
							break;
						}
					}
					//All users with the same name
					if(index_check_name == name_check)
					{
						correct_names_check[index++]=u8CntrName_OUTER;
					}
					index_check_name=0;
				}

				/*******************************************************************************************************/
				//compare entered password with the actual password//
				uint8 index_1 = index;
				for (uint8 u8CntrPass_OUTER = 0; u8CntrPass_OUTER < index; u8CntrPass_OUTER++ )
				{
					index_1--;
					for (uint8 u8CntrPass_INNER = 0; u8CntrPass_INNER < password_check; u8CntrPass_INNER++ )
					{
						if ( password[u8CntrPass_INNER] == Users[correct_names_check[index_1]].Password[u8CntrPass_INNER] )
						{
							index_check_pass ++;
						}
						else
						{
							break;
						}
					}

					if(index_check_pass == password_check)
					{
						break;
					}

					index_check_pass=0;
				}

				if(index == 0)
				{
					Buzzer_warning++;
					//USART_Transmit('2');  //meaning wrong name
					USART_TransmitString((uint8*)"Wrong Name");
				}
				else if (index_check_pass == password_check)
				{
					Buzzer_warning=0;
					//USART_Transmit('3');  //meaning welcome
					USART_TransmitString((uint8*)"Welcome Home");
				}
				else
				{
					//USART_Transmit('4');  //some thing wrong
					USART_TransmitString((uint8*)"Some thing Wrong");
				}
			}
			else
			{
				Buzzer_warning++;
				//USART_Transmit('1');  //meaning wrong pass
				USART_TransmitString((uint8*)"Wrong Password");
			}
		}

		if(Buzzer_warning == 3)
		{
			Buzzer_warning = 0;
			BUZZER_ON();
		}

		Check=0;
		index_check_pass=0;
	}


	return 0;
}
