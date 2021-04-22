/********************************************************************************************
 * Module Name	:	Digital Input Output
 * File Name	:	Dio_Cfg.h
 * Version		:	1.0.0
 * Created on  	: 	25/04/2020
 * Author      	: 	Nihal - Habiba - Nour
 ********************************************************************************************/

#ifndef DIO_CFG_H_
#define DIO_CFG_H_


/* Maximum number of Dio channels */
#define MAX_NUM_PINS							32

/* Maximum number of Dio Ports */
#define MAX_NUM_PORTS							2

/* Number of the configured Dio Channel */
#define DIO_CONFIGURED_CHANNELS				   	3

/* Number of the configured Dio Ports */
#define DIO_CONFIGURED_PORTS					2

/* Number of the configured Dio Channel Group */
#define DIO_CONFIGURED_CHANNEL_GROUP			1



/* Channel Index in the Array of configuration structure in Dio_Lcfg.c */
#define LED1_CHANNEL_ID_INDEX				    ((uint8) 0x00)
#define LED1_CHANNEL_NUM	     			    DIO_CHANNEL_0
                                                
#define LED2_CHANNEL_ID_INDEX				    ((uint8) 0x01)
#define LED2_CHANNEL_NUM					    DIO_CHANNEL_1
                                                
#define LED3_CHANNEL_ID_INDEX				    ((uint8) 0x02)
#define LED3_CHANNEL_NUM				        DIO_CHANNEL_2


/* DIO Configured Channel Group */
#define LED_PORT_GROUP_1						DIO_PORT_B
#define LED_MASK_GROUP_1						0b00111000
#define LED_OFFSET_GROUP_1						2
#define LED										(&ConfiguredChannelGroups[0])



/*Adds / removes the service Dio_FlipChannel() from the code.*/
#define DIO_FLIP_CHANNEL_API FALSE

/*Adds / removes the service Dio_MaskedWritePort() from the code.*/
#define DIO_MASKED_WRITE_PORT_API FALSE

/*Adds / removes the service Dio_ GetVersionInfo() from the code.*/
#define DIO_VERSION_INFO_API FALSE


extern const Dio_ChannelGroupType ConfiguredChannelGroups[DIO_CONFIGURED_CHANNEL_GROUP];
extern const Dio_ChannelType ConfiguredChannels[DIO_CONFIGURED_CHANNELS];


#endif /* DIO_CFG_H_ */
