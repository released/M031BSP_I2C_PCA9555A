
#ifndef PCA9555A_H_
#define PCA9555A_H_

#include <stdio.h>

//#define PCA9555A_DEMO01
#define PCA9555A_DEMO02

#define PCA9555A_DEVADDR_7BIT					(0x20)		// 7 bit	, A0 / A1 / A2 : LOW
#define PCA9555A_DEVADDR_8BIT					(PCA9555A_DEVADDR_7BIT << 1)

// PCA9555A Registers
#define PCA9555A_INPUT_PORT0					(0x00)		// READ			, DEFAULT : XXXX XXXX
#define PCA9555A_INPUT_PORT1					(0x01)		// READ			, DEFAULT : XXXX XXXX
#define PCA9555A_OUTPUT_PORT0					(0x02)		// READ , WRITE	, DEFAULT : 1111 1111
#define PCA9555A_OUTPUT_PORT1					(0x03)		// READ , WRITE	, DEFAULT : 1111 1111
#define PCA9555A_POLARITY_PORT0					(0x04)		// READ , WRITE	, DEFAULT : 0000 0000
#define PCA9555A_POLARITY_PORT1					(0x05)		// READ , WRITE	, DEFAULT : 0000 0000


/*
	 If a bit in these registers is set to 1, the corresponding port pin is enabled as a high-impedance input. 
	 If a bit in these registers is cleared to 0, the corresponding port pin is enabled as an output. 
*/
#define PCA9555A_CONF_PORT0						(0x06)		// READ , WRITE	, DEFAULT : 1111 1111
#define PCA9555A_CONF_PORT1						(0x07)		// READ , WRITE	, DEFAULT : 1111 1111

#define PCA9555A_CONF_INPUT						(0x01)
#define PCA9555A_CONF_OUTPUT					(0x00)

#define PCA9555A_CONF_SET_BIT_INPUT(x)			(PCA9555A_CONF_INPUT << x)
#define PCA9555A_CONF_SET_BIT_OUTPUT(x)			(PCA9555A_CONF_OUTPUT << x)

#define PCA9555A_CONF_ENABLE_OUTPUT(x)			(1 << x)
#define PCA9555A_CONF_DISABLE_OUTPUT(x)			(0 << x)

typedef enum
{
	P0_0 ,
	P0_1 ,
	P0_2 ,
	P0_3 ,
	P0_4 ,
	P0_5 ,
	P0_6 ,
	P0_7 ,
}port0_index;


typedef enum
{	
	P1_0 ,
	P1_1 ,
	P1_2 ,
	P1_3 ,
	P1_4 ,
	P1_5 ,
	P1_6 ,
	P1_7 ,
}port1_index;

void PCA9555A_WriteReg(unsigned char RegAddr, unsigned char* txData , unsigned char length);
int PCA9555A_ReadReg(unsigned char RegAddr , unsigned char* rxData , unsigned char length);

void PCA9555A_WriteSpecificPort0(port0_index pin , unsigned char enable);
void PCA9555A_WriteSpecificPort1(port1_index pin , unsigned char enable);

void PCA9555A_WriteOutputPort(unsigned char data_port0 ,  unsigned char data_port1);
void PCA9555A_ReadOutputPort(unsigned char* data_port0 ,  unsigned char* data_port1);
void PCA9555A_ReadInputPort(unsigned char* data_port0 ,  unsigned char* data_port1);

void PCA9555A_Init(void);


#endif /* PCA9555A_H_ */
