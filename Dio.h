/********************************************************************************************
 * Module Name	:	Digital Input Output Configurations
 * File Name	:	Dio.h
 * Version		:	1.0.0
 * Created on  	: 	18/04/2020
 * Author      	: 	Nihal - Habiba - Nour
 ********************************************************************************************/


#ifndef DIO_H_
#define DIO_H_

/* include Std_Types.h header file*/
#include "Std_Types.h"


/* Dio Types */
typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;
typedef uint8 Dio_LevelType;
typedef uint8 Dio_PortLevelType;

/*  Dio_ChannelGroupConfiguration types  */
typedef struct
{
	uint8 mask;
	uint8 offset;
	Dio_PortType PortIndex;

} Dio_ChannelGroupType;

/* include Dio_Cfg.h header file*/
#include "Dio_Cfg.h"

/* A macro used to validate channel group id */
#define DIO_IS_CHANNEL_GROUPMSK_VALID(Group_Msk )(                  \
		                                    (Group_Msk  == 0x01) || \
		                                    (Group_Msk  == 0x03) || \
		                                    (Group_Msk  == 0x07) || \
		                                    (Group_Msk  == 0x0F) || \
		                                    (Group_Msk  == 0x1F) || \
		                                    (Group_Msk  == 0x3F) || \
		                                    (Group_Msk  == 0x7F) || \
		                                    (Group_Msk  == 0xFF)    \
)


/*                DIO_CHANNEL_IDs           */

#define DIO_CHANNEL_0	            ((uint8)0)
#define DIO_CHANNEL_1               ((uint8)1)
#define DIO_CHANNEL_2               ((uint8)2)
#define DIO_CHANNEL_3               ((uint8)3)
#define DIO_CHANNEL_4               ((uint8)4)
#define DIO_CHANNEL_5               ((uint8)5)
#define DIO_CHANNEL_6               ((uint8)6)
#define DIO_CHANNEL_7               ((uint8)7)
#define DIO_CHANNEL_8               ((uint8)8)
#define DIO_CHANNEL_9               ((uint8)9)
#define DIO_CHANNEL_10              ((uint8)10)
#define DIO_CHANNEL_11              ((uint8)11)
#define DIO_CHANNEL_12              ((uint8)12)
#define DIO_CHANNEL_13              ((uint8)13)
#define DIO_CHANNEL_14              ((uint8)14)
#define DIO_CHANNEL_15              ((uint8)15)
#define DIO_CHANNEL_16              ((uint8)16)
#define DIO_CHANNEL_17              ((uint8)17)
#define DIO_CHANNEL_18              ((uint8)18)
#define DIO_CHANNEL_19              ((uint8)19)
#define DIO_CHANNEL_20              ((uint8)20)
#define DIO_CHANNEL_21              ((uint8)21)
#define DIO_CHANNEL_22              ((uint8)22)
#define DIO_CHANNEL_23              ((uint8)23)
#define DIO_CHANNEL_24              ((uint8)24)
#define DIO_CHANNEL_25              ((uint8)25)
#define DIO_CHANNEL_26              ((uint8)26)
#define DIO_CHANNEL_27              ((uint8)27)
#define DIO_CHANNEL_28              ((uint8)28)
#define DIO_CHANNEL_29              ((uint8)29)
#define DIO_CHANNEL_30              ((uint8)30)
#define DIO_CHANNEL_31              ((uint8)31)


#define DIO_PORT_A			        ((uint8) 0)
#define DIO_PORT_B			        ((uint8) 1)
#define DIO_PORT_C			        ((uint8) 2)
#define DIO_PORT_D			        ((uint8) 3)



Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);//habiba

/******************************************************************************
* Service name: Dio_WriteChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId ID of DIO channel -   Range(DIO_CHANNEL_0 -> DIO_CHANNEL_31)
*                : Level Value to be written -     Range (STD_LOW -> STD_HIGH)
* Parameters(inout):None
* Parameters (out): None
* Return value: None
* Description: Service to set a level of a channel
*****************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);


Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/***************************************************************************
* Service name: Dio_ReadChannelGroup
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelGroupIdPtr Pointer to ChannelGroup
* Parameters(inout):None
* Parameters (out): None
* Return value: Dio_PortLevelType Level of a subset of the adjoining bits of a port
* Description: This Service reads a subset of the adjoining bits of a port.
******************************************************************************/
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr );


void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level );


#if DIO_VERSION_INFO_API == TRUE
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

#if DIO_FLIP_CHANNEL_API == TRUE
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
#endif


#endif /* DIO_H_ */
