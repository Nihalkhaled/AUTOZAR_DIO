/********************************************************************************************
 * File Name	:	Det.h
 * Version		:	1.0.0
 * Created on  	: 	18/04/2020
 * Author      	: 	Nihal - Habiba - Nour
 ********************************************************************************************/

#ifndef DET_H_
#define DET_H_


#include"Std_Types.h"



#define DET_VENDOR_ID                    (uint16)0x0026

#define	DET_MODULE_ID					 (uint8)120

#define	DET_INSTANCE_ID		             (uint8)1

#define DET_SW_MAJOR_VERSION             (uint8)1
#define DET_SW_MINOR_VERSION             (uint8)0
#define DET_SW_PATCH_VERSION             (uint8)0

#define DET_AR_RELEASE_MAJOR_VERSION     (uint8)1
#define DET_AR_RELEASE_MINOR_VERSION     (uint8)0
#define DET_AR_RELEASE_PATCH_VERSION     (uint8)0


Std_ReturnType Det_ReportError(uint16 ModuleId,uint8 InstanceId,uint8 ApiId,uint8 ErrorId);


#endif /* DET_H_ */
