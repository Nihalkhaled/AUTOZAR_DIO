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
	/* [SWS_Dio_00005] The Dio modules read and write services shall ensure for all services,
	 * that the data is consistent (Interruptible read-modify-write sequences are not allowed) */

	DISABLE_ALL_INTERRUPTS();	/* Disable global interrupt*/

	loc_levelType= GET_BIT(*Portx,PinId);

	ENABLE_ALL_INTERRUPTS();	/*Enable global interrupt*/

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

	if( GET_BIT(*DDRx, PinId) == OUTPUT )/* [SWS_Dio_00028] ?If the specified channel is configured as an output channel, the
	 * Dio_WriteChannel function shall set the specified Level for the specified channel. */
	{
		/* [SWS_Dio_00005] The Dio module�s read and write services shall ensure for all services,
		 * that the data is consistent (Interruptible read-modify-write sequences are not allowed) */

		DISABLE_ALL_INTERRUPTS();	/* Disable global interrupt*/

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
			/* No Action is Required */
		}
		ENABLE_ALL_INTERRUPTS();	/*Enable global interrupt*/
	}
	else
	{
		/* [SWS_Dio_00029] If the specified channel is configured as an input channel, the
		   Dio_WriteChannel function shall have no influence on the physical output.*/
		/* [SWS_Dio_00079] check if the specified channel is configured as an input channel, the
		   Dio_WriteChannel function shall have no influence on the result of the next Read-Service */
	}
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	Dio_PortLevelType Port_level;
	volatile uint8 * DDRx;
	volatile uint8 * PINx;
	volatile uint8 * PORTx;

	/* [SWS_Dio_00005] The DIO modules read and write services shall ensure for all services,
	 * that the data is consistent (Interruptible read-modify-write sequences are not allowed) */

	DISABLE_ALL_INTERRUPTS();	/* Disable global interrupt*/

	/*[SWS_Dio_00026] The configuration process for Dio module shall provide symbolic
	names for each configured DIO channel, port and group*/

	switch(PortId)
	{
	case DIO_PORT_A:
		DDRx = DDRA;
		PINx = PINA;
		PORTx = PORTA;
		break;
	case DIO_PORT_B:
		DDRx = DDRB;
		PINx = PINB;
		PORTx = PORTB;
		break;
	case DIO_PORT_C:
		DDRx = DDRC;
		PINx = PINC;
		PORTx = PORTC;
		break;
	case DIO_PORT_D:
		DDRx = DDRD;
		PINx = PINC;
		PORTx = PORTD;
		break;
	default:
		break;
	}

	/*[SWS_Dio_00012] The Dio module’s read functions shall work on input and output
	channels.*/

	/*[SWS_Dio_00013] The Dio_ReadPort function shall read the levels of all
    channels of one port. A bit value '0' indicates that the corresponding channel is
    physical STD_LOW, a bit value '1' indicates that the corresponding channel is physical
    STD_HIGH.*/

	/*[SWS_Dio_00031] The Dio_ReadPort function shall return the level of all
	channels of that port.*/

	if(*DDRx == OUTPUT)
	{
		/* [SWS_Dio_00084] If the microcontroller does not support the direct read-back of a
		                       pin value, the Dio module’s read functions shall provide the value of the output
		                       register, when they are used on a channel which is configured as an output channel */
#if DIO_READ_BACK == FALSE
		Port_level = *PORTx;
#else
		/* [SWS_Dio_00083] If the microcontroller supports the direct read-back of a pin
                           value, the Dio module’s read functions shall provide the real pin level, when they are
                           used on a channel which is configured as an output channel */
		Port_level = PORTx;
#endif
	}
	else
	{
		Port_level = *PINx;
	}

	ENABLE_ALL_INTERRUPTS(); 	/*Enable global interrupt*/
	return Port_level;
}

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr )
{

	//check if mask is correct
	Dio_PortType Portx = ChannelGroupIdPtr->PortIndex;
	Dio_PortLevelType Group_level;

	/* [SWS_Dio_00005] The Dio module�s read and write services shall ensure for all services,
	   that the data is consistent (Interruptible read-modify-write sequences are not allowed) */

	DISABLE_ALL_INTERRUPTS();	/* Disable global interrupt */
	switch(Portx)
	{
	/* [SWS_Dio_00037] The Dio_ReadChannelGroup function shall read a subset of
     the adjoining bits of a port (channel group)*/
	/* [SWS_Dio_00092] The Dio_ReadChannelGroup function shall do the masking of the channel group.*/
	/* [SWS_Dio_00093] The Dio_ReadChannelGroup function shall do the shifting so
     that the values read by the function are aligned to the LSB. */
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
	ENABLE_ALL_INTERRUPTS(); 	/*Enable global interrupt*/
	return Group_level;

}

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level )
{
	/*[SWS_Dio_00026] The configuration process for DIO module shall provide symbolic
      names for each configured DIO channel, port and group.*/

	Dio_PortType Portx = ChannelGroupIdPtr->PortIndex;

	/* [SWS_Dio_00005] The DIO module�s read and write services shall ensure for all services,
		   that the data is consistent (Interruptible read-modify-write sequences are not allowed) */

	DISABLE_ALL_INTERRUPTS();	/* Disable global interrupt */

	/*[SWS_Dio_00039] The Dio_WriteChannelGroup function shall set a subset of
      the adjoining bits of a port (channel group) to a specified level.*/

	/*[SWS_Dio_00040] The Dio_WriteChannelGroup shall not change the remaining
      channels of the port and channels which are configured as input.*/

	/*[SWS_Dio_00090] The Dio_WriteChannelGroup function shall do the masking
      of the channel group.*/

	/*[SWS_Dio_00091] The function Dio_WriteChannelGroup shall do the shifting
      so that the values written by the function are aligned to the LSB.*/

	switch(Portx)
	{
	case DIO_PORT_A:
		if(Level == STD_HIGH)
		{
			*PORTA |= ChannelGroupIdPtr->mask << ChannelGroupIdPtr->offset;
		}
		else
		{
			*PORTA &= !(ChannelGroupIdPtr->mask << ChannelGroupIdPtr->offset);
		}
		break;

	case DIO_PORT_B:
		if(Level == STD_HIGH)
		{
			*PORTB |= (ChannelGroupIdPtr->mask << ChannelGroupIdPtr->offset);
		}
		else
		{
			*PORTB &= !(ChannelGroupIdPtr->mask << ChannelGroupIdPtr->offset);
		}
		break;
	case DIO_PORT_C:
		if(Level == STD_HIGH)
		{
			*PORTC |= (ChannelGroupIdPtr->mask << ChannelGroupIdPtr->offset);
		}
		else
		{
			*PORTC &= !(ChannelGroupIdPtr->mask << ChannelGroupIdPtr->offset);
		}
		break;
	case DIO_PORT_D:
		if(Level == STD_HIGH)
		{
			*PORTD |= (ChannelGroupIdPtr->mask << ChannelGroupIdPtr->offset);
		}
		else
		{
			*PORTD &= !(ChannelGroupIdPtr->mask << ChannelGroupIdPtr->offset);
		}
		break;
	default:
		break;
	}
	/*[SWS_Dio_00056] A channel group is a formal logical combination of several
              adjoining DIO channels within a DIO port.*/
	ENABLE_ALL_INTERRUPTS(); 	/*Enable global interrupt*/
}


