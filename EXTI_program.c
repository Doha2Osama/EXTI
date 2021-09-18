/*
File Name:EXTI_program
Author:DohaOsama
Date:18/9/2021
Description:EXTI Driver 
version 1.0
*/
#include "../../LIB/STD_TYPES.h"//library  contains all datatypes needed in this program
#include "../../LIB/BIT_MATH.h"//library contains clear and set and get and toggle bit it will be used in this program 
#include "EXTI_interface.h"//it is a header file that contain functions prototypes and some definitions and it will be very important to the user
#include "EXTI_private.h"//it is a header file that contains information very important in the program but it is not important for the user
#include "EXTI_config.h"
void (*EXTI_pvINT0Fuction)(void)=NULL_POINTER;
void EXTI_voidSetINT0SenseControl (u8 Copy_u8SignalControl)
{
	switch(Copy_u8SignalControl)
	{
		case FALLING_EDGE  :
		CLEAR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
		case LOW_LEVEL  :
		CLEAR_BIT(MCUCR,MCUCR_ISC00);
		CLEAR_BIT(MCUCR,MCUCR_ISC01);
		break;
		case ON_CHANGE  :
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLEAR_BIT(MCUCR,MCUCR_ISC01);
		break;
		case RISNG_EDGE :
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
		
	}
	
}
void GIE_voidEnableGlobalInterrupt (void)
{
	SET_BIT(SREG,SREG_I );
}
void GIE_voidDisEnableGlobalInterrupt (void)
{
	CLEAR_BIT(SREG,SREG_I );
}
void EXTI_voidEnableInt0(void)
{
	SET_BIT(GICR,6);
}
void EXTI_voidDisEnableInt0(void)
{
	CLEAR_BIT(GICR,6);
}
void EXTI_voidInt0SetCallBack(void(*Copy_pvNotificationFunction))//async.
{
	EXTI_pvINT0Fuction=Copy_pvNotificationFunction;
}
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvINT0Fuction!=NULL_POINTER)
	{
		EXTI_pvINT0Fuction();
	}
}
void EXTI_voidInt0Synchronous(void(*Copy_pvNotificationFunction))
{
	while(GET_BIT(GIFR,6)==0);
	SET_BIT(GIFR,6);
	EXTI_pvINT0Fuction=Copy_pvNotificationFunction;
	EXTI_pvINT0Fuction();
}
