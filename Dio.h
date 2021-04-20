/*
 * Dio_int.h
 *
 *  Created on: April 18, 2021
 *      Author: Nihal khaled
 */

#ifndef DIO_H_
#define DIO_H_

#include "Std_Types.h"
#include "Dio_Cfg.h"

/* Dio Types */

typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;
typedef uint8 Dio_LevelType;
typedef uint8 Dio_PortLevelType;



/*  Dio_ChannelGroupConfiguration types */
typedef struct
{
  uint8 mask;
  uint8 offset;
  Dio_PortType PortIndex;

} Dio_ChannelGroupType;

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


#define DIO_PORT_A			        ((uint8)0)
#define DIO_PORT_B			        ((uint8)1)
#define DIO_PORT_C			        ((uint8)2)
#define DIO_PORT_D			        ((uint8)3)




Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);//habiba

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);//nihal

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);//nour

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);//habiba

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr );//nihal

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level );//nour

void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo);//habiba

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);//nihal



#endif /* DIO_H_ */
