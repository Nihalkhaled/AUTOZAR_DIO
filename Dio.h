/*
 * Dio_int.h
 *
 *  Created on: April 18, 2021
 *      Author: Nihal khaled
 */

#ifndef DIO_H_
#define DIO_H_


/*  Dio_ChannelGroupConfiguration types */
typedef struct
{
  uint8 mask;
  uint8 offset;
  Dio_PortType PortIndex;

} Dio_ChannelGroupType;

/* Dio Types */
typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;
typedef uint8 Dio_LevelType;
typedef uint8 Dio_PortLevelType;






Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr );

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level );

void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo);

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

void Dio_MaskedWritePort ( Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask );


#endif /* DIO_H_ */
