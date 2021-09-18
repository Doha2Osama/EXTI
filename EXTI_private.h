#ifndef EXTI_PRIVATE_H

#define EXTI_PRIVATE_H

#define MCUCR *((volatile u8*)(0x55))//MCU control register

#define MCUCR_ISC00 0                //int0 sense control 0

#define MCUCR_ISC01 1				//int1 sense control 1

#define MCUCR_ISC10 2				//int2 sense control 2

#define MCUCR_ISC11 3 				//int3 sense control 3

#define MCUCSR *((volatile u8*)(0x54))

#define GICR *((volatile u8*)(0x5B))

#define GIFR *((volatile u8*)(0x5A))

#define SREG *((volatile u8*)(0x5F))

#define SREG_I  7

#define NULL_POINTER  (void* )0

#define LOW_LEVEL  0

#define RISNG_EDGE  2

#define FALLING_EDGE  3

#define ON_CHANGE  1

#endif