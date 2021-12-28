
#include <stdio.h>
#include "PCA9555A.h"

#include "i2c_driver.h"
#include <math.h>
#include "project_config.h"

/*
	Write to output port registers
	slave address + command byte + data to port 0 + data to port 1

	Write to Control registers
	slave address + command byte + data to register port 0 + data to register port 1
	
	Read from register
	slave address | W + command byte
	slave address | R + DATA (first byte) + .. + DATA (last byte)
	
*/

void PCA9555A_WriteReg(unsigned char RegAddr, unsigned char* txData , unsigned char length)
{
	unsigned char i2c_addr = PCA9555A_DEVADDR_7BIT;	// 7 BIT

	i2c_reg_write(i2c_addr ,RegAddr , txData ,length);
}

int PCA9555A_ReadReg(unsigned char RegAddr , unsigned char* rxData , unsigned char length)
{
	unsigned char i2c_addr = PCA9555A_DEVADDR_7BIT;	// 7 BIT

	I2C_ReadData(i2c_addr,RegAddr , rxData ,length);
	return 0;
}

void PCA9555A_WriteSpecificPort0(port0_index pin , unsigned char enable)
{
	unsigned char rxData[2] = {0};

	PCA9555A_ReadReg(PCA9555A_OUTPUT_PORT0 , rxData , 1);

	if (enable)
	{
		rxData[0] |= PCA9555A_CONF_ENABLE_OUTPUT(pin);
	}
	else
	{
		rxData[0] |= PCA9555A_CONF_DISABLE_OUTPUT(pin);
	}

	PCA9555A_WriteReg(PCA9555A_OUTPUT_PORT0 , rxData , 1);	
}

void PCA9555A_WriteSpecificPort1(port1_index pin , unsigned char enable)
{
	unsigned char rxData[2] = {0};

	PCA9555A_ReadReg(PCA9555A_OUTPUT_PORT1 , rxData , 1);

	if (enable)
	{
		rxData[0] |= PCA9555A_CONF_ENABLE_OUTPUT(pin);
	}
	else
	{
		rxData[0] |= PCA9555A_CONF_DISABLE_OUTPUT(pin);
	}

	PCA9555A_WriteReg(PCA9555A_OUTPUT_PORT1 , rxData , 1);	
}


void PCA9555A_WriteOutputPort(unsigned char data_port0 ,  unsigned char data_port1)
{
	unsigned char rxData[2] = {0};

	rxData[0] = data_port0;
	rxData[1] = data_port1;	
	PCA9555A_WriteReg(PCA9555A_OUTPUT_PORT0 , rxData , 2);	
}

void PCA9555A_ReadOutputPort(unsigned char* data_port0 ,  unsigned char* data_port1)
{
	unsigned char rxData[2] = {0};

	PCA9555A_ReadReg(PCA9555A_OUTPUT_PORT0 , rxData , 2);

	*data_port0 = rxData[0];
	*data_port1 = rxData[1];	
}


void PCA9555A_ReadInputPort(unsigned char* data_port0 ,  unsigned char* data_port1)
{
	unsigned char rxData[2] = {0};

	PCA9555A_ReadReg(PCA9555A_INPUT_PORT0 , rxData , 2);

	*data_port0 = rxData[0];
	*data_port1 = rxData[1];
}

void PCA9555A_Init(void)
{
	// set input (0x01) or output (0x00)
	unsigned char rxData[2] = {0};
	unsigned char data_port0 = 0;
	unsigned char data_port1 = 0;	

	data_port0 = PCA9555A_CONF_SET_BIT_OUTPUT(7)|
				PCA9555A_CONF_SET_BIT_OUTPUT(6)|
				PCA9555A_CONF_SET_BIT_OUTPUT(5)|
				PCA9555A_CONF_SET_BIT_OUTPUT(4)|
				PCA9555A_CONF_SET_BIT_OUTPUT(3)|
				PCA9555A_CONF_SET_BIT_OUTPUT(2)|
				PCA9555A_CONF_SET_BIT_OUTPUT(1)|
				PCA9555A_CONF_SET_BIT_OUTPUT(0);
				
	data_port1 = PCA9555A_CONF_SET_BIT_OUTPUT(7)|
				PCA9555A_CONF_SET_BIT_OUTPUT(6)|
				PCA9555A_CONF_SET_BIT_OUTPUT(5)|
				PCA9555A_CONF_SET_BIT_OUTPUT(4)|
				PCA9555A_CONF_SET_BIT_OUTPUT(3)|
				PCA9555A_CONF_SET_BIT_OUTPUT(2)|
				PCA9555A_CONF_SET_BIT_OUTPUT(1)|
				PCA9555A_CONF_SET_BIT_OUTPUT(0);

	rxData[0] = data_port0;
	rxData[1] = data_port1;	
	PCA9555A_WriteReg(PCA9555A_CONF_PORT0 , rxData , 2);

	PCA9555A_WriteOutputPort(0x00 , 0x00);

}


