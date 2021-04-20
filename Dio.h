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


#define DIO_u8PIN_0	              (uint8_t) 0
#define DIO_u8PIN_1               (uint8_t) 1
#define DIO_u8PIN_2               (uint8_t) 2
#define DIO_u8PIN_3               (uint8_t) 3
#define DIO_u8PIN_4               (uint8_t) 4
#define DIO_u8PIN_5               (uint8_t) 5
#define DIO_u8PIN_6               (uint8_t) 6
#define DIO_u8PIN_7               (uint8_t) 7
#define DIO_u8PIN_8               (uint8_t) 8
#define DIO_u8PIN_9               (uint8_t) 9
#define DIO_u8PIN_10              (uint8_t) 10
#define DIO_u8PIN_11              (uint8_t) 11
#define DIO_u8PIN_12              (uint8_t) 12
#define DIO_u8PIN_13              (uint8_t) 13
#define DIO_u8PIN_14              (uint8_t) 14
#define DIO_u8PIN_15              (uint8_t) 15
#define DIO_u8PIN_16              (uint8_t) 16
#define DIO_u8PIN_17              (uint8_t) 17
#define DIO_u8PIN_18              (uint8_t) 18
#define DIO_u8PIN_19              (uint8_t) 19
#define DIO_u8PIN_20              (uint8_t) 20
#define DIO_u8PIN_21              (uint8_t) 21
#define DIO_u8PIN_22              (uint8_t) 22
#define DIO_u8PIN_23              (uint8_t) 23
#define DIO_u8PIN_24              (uint8_t) 24
#define DIO_u8PIN_25              (uint8_t) 25
#define DIO_u8PIN_26              (uint8_t) 26
#define DIO_u8PIN_27              (uint8_t) 27
#define DIO_u8PIN_28              (uint8_t) 28
#define DIO_u8PIN_29              (uint8_t) 29
#define DIO_u8PIN_30              (uint8_t) 30
#define DIO_u8PIN_31              (uint8_t) 31


#define DIO_PORT_A			      ((uint8) 0)
#define DIO_PORT_B			      ((uint8) 1)
#define DIO_PORT_C			      ((uint8) 2)
#define DIO_PORT_D			      ((uint8) 3)



Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);//habiba

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);//nihal

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);//nour

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);//habiba

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr );//nihal

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level );//nour

void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo);//habiba

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);//nihal



#endif /* DIO_H_ */
