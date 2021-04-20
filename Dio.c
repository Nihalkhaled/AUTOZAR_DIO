/*
 * Dio.c
 *
 *  Created on: Apr 18, 2021
 *      Author: Nihal khaled
 */

#include "Dio.h"


#define PORTA	 (volatile uint8*)0x003B
#define DDRA	 (volatile uint8*)0x003A
#define PINA	 (volatile uint8*)0x0039
#define PORTB	 (volatile uint8*)0x0038
#define DDRB	 (volatile uint8*)0x0037
#define PINB	 (volatile uint8*)0x0036
#define PORTC	 (volatile uint8*)0x0035
#define DDRC	 (volatile uint8*)0x0034
#define PINC	 (volatile uint8*)0x0033
#define PORTD	 (volatile uint8*)0x0032
#define DDRD	 (volatile uint8*)0x0031
#define PIND	 (volatile uint8*)0x0030


#define CLEAR_BIT(reg, n)        ((reg) &= ~(1 << (n)))
#define SET_BIT(reg, n)          ((reg) |= 1 << (n))
#define GET_BIT(reg, n)          (((reg) >> (n)) & 1)

#define OUTPUT				1
#define INPUT				0




void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	uint8 PortId,PinId;
	volatile uint8 * DDRx;
	volatile uint8 * Portx;


	PortId = ChannelId  / 8 ;
	PinId  = ChannelId % 8 ;

	switch (PortId)
	{
	case DIO_PORT_A:
		Portx = PORTA;
		//DDRx  = &DDRA;
		break;

	case DIO_PORT_B:
		Portx = PORTB;
		DDRx = DDRB;
		break;

	case DIO_PORT_C:
		Portx = PORTC;
		DDRx  = DDRC;
		break;

	case DIO_PORT_D:
		Portx = PORTD;
		DDRx  = DDRD;
		break;
	}

	if( GET_BIT(*DDRx, PinId) == OUTPUT )
	{
		/* [SWS_Dio_00005] The Dio module’s read and write services shall ensure for all services,
				that the data is consistent (Interruptible read-modify-write sequences are not allowed) */

		asm("cli");	/*Disable global interrupt*/
		if( Level == STD_HIGH )
		{
			SET_BIT(*Portx, PinId );
		}
		else if ( Level == STD_LOW )
		{
			CLEAR_BIT(*Portx, PinId );
		}
		else
		{
			/* No Action Required */
		}
		asm("sei");	/*Enable global interrupt*/
	}
	else
	{
		/* [SWS_Dio_00029] If the specified channel is configured as an input channel, the
		 * Dio_WriteChannel function shall have no influence on the physical output.
		 *
		 * [SWS_Dio_00079] check if the specified channel is configured as an input channel, the
		 * Dio_WriteChannel function shall have no influence on the result of the next Read-Service */
	}
}
