/********************************************************************************************
 * Module Name	:	Digital Input Output
 * File Name	:	Dio_Lcfg.c
 * Version		:	1.0.0
 * Created on  	: 	25/04/2020
 * Author      	: 	Nihal - Habiba - Nour
 ********************************************************************************************/

#include "Dio.h"

const Dio_ChannelGroupType ConfiguredChannelGroups[DIO_NUMBER_OF_CONFIGURED_CHANNEL_GROUP]=
{
		{
				.PortIndex = DIO_PORT_B,
				.mask      = 0b00111000,
				.offset    = 3
		}

};
