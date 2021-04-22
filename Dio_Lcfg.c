/********************************************************************************************
 * Module Name	:	Digital Input Output
 * File Name	:	Dio_Lcfg.c
 * Version		:	1.0.0
 * Created on  	: 	25/04/2020
 * Author      	: 	Nihal - Habiba - Nour
 ********************************************************************************************/


#include "Dio.h"


const Dio_ChannelGroupType ConfiguredChannelGroups[DIO_CONFIGURED_CHANNEL_GROUP]=
{
		{
				.PortIndex=LED_PORT_GROUP_1,
				.mask=	   LED_MASK_GROUP_1,
				.offset=   LED_OFFSET_GROUP_1
		}

};

const Dio_ChannelType ConfiguredChannels[DIO_CONFIGURED_CHANNELS]=
{
	        [LED1_CHANNEL_ID_INDEX] = LED1_CHANNEL_NUM,
			[LED2_CHANNEL_ID_INDEX] = LED2_CHANNEL_NUM,
			[LED3_CHANNEL_ID_INDEX] = LED3_CHANNEL_NUM,


};
