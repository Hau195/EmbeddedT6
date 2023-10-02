#include "stm32f10x.h"

#define SDA GPIO_Pin_3
#define SCL GPIO_Pin_4
#define ACK 0
#define NACK 1
#define ADDRESS 0x27


void GPIO_config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}
void Tim2_Register(void)
{
	RCC->APB1ENR |= 0x01;
	TIM2->ARR = 0xFFFF;
	TIM2->PSC = 72-1;
	TIM2->CR1 = 0x01;
	TIM2->EGR = 0x01;
}

void Delay_timer2_ms(uint32_t u32Delay)
{
	while(u32Delay)
	{
		TIM2->CNT = 0U;
		while(TIM2->CNT < 1000);
		u32Delay--;
	}
}


void clock()
{
	GPIO_SetBits(GPIOB, SCL);
	Delay_timer2_ms(50);
	GPIO_ResetBits(GPIOB, SCL);
	Delay_timer2_ms(50);
	
}

void setStatus()
{
	GPIO_SetBits(GPIOB, SDA);
	GPIO_SetBits(GPIOB, SCL);
}

void startCondition()
{
	GPIO_ResetBits(GPIOB, SDA);
	Delay_timer2_ms(50);
	GPIO_ResetBits(GPIOB, SCL);
}

void waitStart()
{
	while(GPIO_ReadInputDataBit(GPIOB, SCL) == 1)
	{
		if(GPIO_ReadInputDataBit(GPIOB, SDA) == 0)
		{
			while(GPIO_ReadInputDataBit(GPIOB, SCL) == 1);
			return;
		}
	}
}
void setInputSDA()
{
	GPIOB->CRL &= ~(GPIO_CRL_MODE4);
	GPIOB->CRL |= GPIO_CRL_MODE4_1;
	GPIOB->BSRR = GPIO_Pin_4;
}

void setOutputSDA()
{
	GPIOB->CRL &= ~(GPIO_CRL_MODE4);
	GPIOB->CRL |= GPIO_CRL_MODE4_0;
	GPIOB->BRR = GPIO_Pin_4;
}


uint8_t receiveAdd()
{
	uint8_t data = 0;

	for(int i = 0; i < 8; i++)
	{
		while(GPIO_ReadInputDataBit(GPIOB,SCL) == 0);
		
		if(GPIO_ReadInputDataBit(GPIOB, SDA) == 1) data = data | (0x80 >> i);
		
		while(GPIO_ReadInputDataBit(GPIOB,SCL) == 1);
	}
	
	return data;
}

uint8_t receiveData()
{
	uint8_t data = 0;
	for(int i = 0; i < 8; i++)
	{
		while(GPIO_ReadInputDataBit(GPIOB,SCL) == 0);
		
		if(GPIO_ReadInputDataBit(GPIOB, SDA) == 1) data = data | (0x80 >> i);
		
		while(GPIO_ReadInputDataBit(GPIOB,SCL) == 1);
	}
	
	return data;
}

int data[2];

void I2c_slave()
{
	waitStart();
	
	uint8_t add_WriteorRead = receiveAdd();
	
	setOutputSDA();
	uint8_t add_Receive = add_WriteorRead >> 1;
	if(add_Receive == ADDRESS) GPIO_ResetBits(GPIOB, SDA);
	else{
		GPIO_SetBits(GPIOA, SDA);
		while(GPIO_ReadInputDataBit(GPIOB, SCL) == 0);
		setInputSDA();
		return;
	}
	while(GPIO_ReadInputDataBit(GPIOB, SCL) == 0);
	setInputSDA();
	
	if((add_WriteorRead & 1) == 0)
	{
		data[0] = receiveData();
		setOutputSDA();
		GPIO_ResetBits(GPIOB, SDA);
		while(GPIO_ReadInputDataBit(GPIOB, SCL) == 0);
		setInputSDA();
		
		data[1] = receiveData();
		setOutputSDA();
		GPIO_ResetBits(GPIOB, SDA);
		while(GPIO_ReadInputDataBit(GPIOB, SCL) == 0);
		setInputSDA();
		return;
	}else{}
}



int main()
{
	GPIO_config();
	Tim2_Register();
	uint8_t data = 0;
	
	while(1)
	{
		//GPIO_SetBits(GPIOC, GPIO_Pin_13);
		//Delay_timer2_ms(1000);
		//GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		//Delay_timer2_ms(1000);
		
		I2c_slave();
	}
}



