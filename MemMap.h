/*
 * MemMap.h
 *
 * Created: 12/8/2023 12:16:07 AM
 *  Author: Mohamed Ramadan
 */ 



#ifndef MEMMAP_H_
#define MEMMAP_H_

/**********************************************DIO RREGISTERS **************************************/

#define PORTA (*(volatile unsigned char *)0X3B)
#define DDRA  (*(volatile unsigned char *)0X3A)
#define PINA  (*(volatile unsigned char *)0X39)

#define PORTC (*(volatile unsigned char *)0X35)
#define DDRC  (*(volatile unsigned char *)0X34)
#define PINC  (*(volatile unsigned char *)0X33)


#define PORTB  (*(volatile unsigned char*)0x38)
#define DDRB   (*(volatile unsigned char*)0x37)
#define PINB   (*(volatile unsigned char*)0x36)


#define PORTD  (*(volatile unsigned char *)0x32)
#define DDRD   (*(volatile unsigned char *)0x31)
#define PIND   (*(volatile unsigned char *)0x30)

/************************************************************************************************************/



#endif /* MEMMAP_H_ */