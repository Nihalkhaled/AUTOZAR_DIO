/********************************************************************************************
 * Module Name	:	Digital Input Output
 * File Name	:	Dio.c
 * Version		:	1.0.0
 * Created on  	: 	18/04/2020
 * Author      	: 	Nihal - Habiba - Nour
 ********************************************************************************************/
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



Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){

	uint8 PortId,PinId,loc_levelType;
	volatile uint8 * DDRx;
	volatile uint8 * Portx;
	PortId = ChannelId  /8 ;
	PinId  = ChannelId  %8 ;

	switch(PortId){
	/*in case of PORT A*/
	case DIO_PORT_A:
		Portx = PORTA;
		DDRx  = DDRA;
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
	asm("cli");	/*Disable global interrupt*/
	loc_levelType= GET_BIT(*Portx,PinId);
	asm("sei");	/*Enable global interrupt*/

	return loc_levelType;
}


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

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr )
{

//check if mask is correct
	Dio_PortType Portx = ChannelGroupIdPtr->PortIndex;
	Dio_PortLevelType Group_level;
	asm("cli");	/*Disable global interrupt*/
   switch(Portx)
   {
   case DIO_PORT_A:
	   Group_level = (((*PINA)&(ChannelGroupIdPtr->mask)) >> (ChannelGroupIdPtr->offset));
	   break;
   case DIO_PORT_B:
	   Group_level = (((*PINB)&(ChannelGroupIdPtr->mask)) >> (ChannelGroupIdPtr->offset));
	   break;
   case DIO_PORT_C:
	   Group_level = (((*PINC)&(ChannelGroupIdPtr->mask)) >> (ChannelGroupIdPtr->offset));
	   break;
   case DIO_PORT_D:
	   Group_level = (((*PIND)&(ChannelGroupIdPtr->mask)) >> (ChannelGroupIdPtr->offset));
	   break;
   default:
	   break;

   }

   asm("sei");	/*Enable global interrupt*/
   return Group_level;

}


