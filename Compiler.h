/********************************************************************************************s
 * File Name	:	Compiler.h
 * Version		:	1.0.0
 * Created on  	: 	18/04/2020
 * Author      	: 	Nihal - Habiba - Nour
 ********************************************************************************************/

#ifndef COMPILER_H_
#define COMPILER_H_


#define NULL_PTR                           ((void *)0)
#define TYPEDEF			                   typedef
#define INLINE                             inline
#define LOCAL_INLINE                       static inline
#define STATIC                             static
#define DISABLE_ALL_INTERRUPTS()           asm("cli")
#define ENABLE_ALL_INTERRUPTS()            asm("sei")

#endif /* COMPILER_H_ */
