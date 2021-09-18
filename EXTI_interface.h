#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H



void EXTI_voidSetINT0SenseControl (u8 Copy_u8SignalControl);
void GIE_voidEnableGlobalInterrupt (void);
void GIE_voidDisEnableGlobalInterrupt (void);
void EXTI_voidEnableInt0(void);
void EXTI_voidDisEnableInt0(void);
void EXTI_voidInt0SetCallBack(void(*Copy_pvNotificationFunction));
void EXTI_voidInt0Synchronous(void(*Copy_pvNotificationFunction));
#endif