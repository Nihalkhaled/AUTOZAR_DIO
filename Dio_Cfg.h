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
#define MAX_NUM_DIO_PINS							        31

/* Maximum number of Dio Ports */
#define MAX_NUM_DIO_PORTS							        4

/* Number of the configured Dio Channel */
#define DIO_NUMBER_OF_CONFIGURED_CHANNELS				   	3

/* Number of the configured Dio Ports */
#define DIO_NUMBER_OF_CONFIGURED_PORTS				     	2

/* Number of the configured Dio Channel Group */
#define DIO_NUMBER_OF_CONFIGURED_CHANNEL_GROUP		      	1



/* DIO Configured Channel */
#define LED1_NUM	     			                        DIO_CHANNEL_0
#define LED2_NUM					                        DIO_CHANNEL_1
#define LED3_NUM				                            DIO_CHANNEL_2


/* DIO Configured Channel Group */
#define LED_GROUP1					     		           (&ConfiguredChannelGroups[0])


/*Determines If the microcontroller supports the direct read-back of a pin value or not*/
#define DIO_READ_BACK FALSE

/*Adds or removes the Dio_FlipChannel API from the code.*/
#define DIO_FLIP_CHANNEL_API                               FALSE

/*Adds or removes the Dio_GetVersionInfo API from the code.*/
#define DIO_VERSION_INFO_API                               FALSE

/* Pre-Compile option for development error detection API */
#define DIO_DevErrorDetect_API						       FALSE

/* ConfiguredChannelGroups array which configure the required groups of channel in array in Dio_Lcfg.c */
extern const Dio_ChannelGroupType ConfiguredChannelGroups[DIO_NUMBER_OF_CONFIGURED_CHANNEL_GROUP];


#endif /* DIO_CFG_H_ */
