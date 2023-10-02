#include "stm32f10x.h"

#define SCL GPIO_Pin_3
#define SDA GPIO_Pin_4
#define ACK 0
#define NACK 1

#define SLAVE_ADDRESS 0x27



void GPIO_config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
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

void transmit7bitAdd(uint8_t slave_address)
{
	for(uint8_t i = 0; i< 7;i++)
	{
		if(slave_address & (0x40 >> i)) GPIO_SetBits(GPIOB, SDA);
		else GPIO_ResetBits(GPIOB, SDA);
		
		clock();
	}
	//bit write
	GPIO_ResetBits(GPIOB, SDA);
	clock();
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

void endCondition()
{
	GPIO_ResetBits(GPIOB, SDA);
	GPIO_SetBits(GPIOB, SCL);
	Delay_timer2_ms(50);
	GPIO_SetBits(GPIOB, SDA);
}

void transmitData(uint8_t data)
{
		for(uint8_t i = 0; i< 7;i++)
	{
		if(data & (0x80 >> i)) GPIO_SetBits(GPIOB, SDA);
		else GPIO_ResetBits(GPIOB, SDA);
		
		clock();
	}
	
}


void I2C_master()
{
	
	again:
	
	setStatus();
	Delay_timer2_ms(500);
	
	startCondition();
	transmit7bitAdd(SLAVE_ADDRESS);
	
	setInputSDA();
	if(GPIO_ReadInputDataBit(GPIOB, SDA) == ACK)
	{
		setOutputSDA();
		transmitData(170);
		setInputSDA();
		if(GPIO_ReadInputDataBit(GPIOB, SDA) == ACK)
		{
			setOutputSDA();
			transmitData(48);
			setInputSDA();
			if(GPIO_ReadInputDataBit(GPIOB, SDA) == ACK)
			{
				setOutputSDA();
				endCondition();
				
			}else{
				setOutputSDA();
				goto again;
			}
		}
	}
	
}

int main()
{
	GPIO_config();
	Tim2_Register();

	uint8_t data = 170;
	
	while(1)
	{
		//GPIO_SetBits(GPIOC, GPIO_Pin_13);
		//Delay_timer2_ms(1000);
		//GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		Delay_timer2_ms(1000);
		I2C_master();
		
	}
}



