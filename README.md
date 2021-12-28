# M031BSP_I2C_PCA9555A
 M031BSP_I2C_PCA9555A


update @ 2021/12/28

1. initial I2C master I2C0 : PC1 : SCL , PC0 : SDA , to drive I2C I/O extender PCA9555A

2. Two define to demo PCA9555A output , PCA9555A_DEMO01 and PCA9555A_DEMO02

	PCA9555A_DEMO01 : toggle port0 and port1 by sequence
	
	PCA9555A_DEMO02 : toggle each bit in two port by sequence

3. below is LA capture , 

set_port0_0x00_port1_0xFF

![image](https://github.com/released/M031BSP_I2C_PCA9555A/blob/main/set_port0_0xFF_port1_0x00.jpg)

set_port0_0x00_port1_0xFF

![image](https://github.com/released/M031BSP_I2C_PCA9555A/blob/main/set_port0_0x00_port1_0xFF.jpg)

4. below is demo2 log message 

![image](https://github.com/released/M031BSP_I2C_PCA9555A/blob/main/log.jpg)


