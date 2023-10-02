#include "stm32f10x.h"

#define SCK GPIO_Pin_3
#define MOSI GPIO_Pin_4
#define MISO GPIO_Pin_9
#define SS GPIO_Pin_6


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

void spi_Init()
{
		GPIO_SetBits(GPIOB, SS);
		GPIO_ResetBits(GPIOB, SCK);
		GPIO_ResetBits(GPIOB, MOSI);
}

void clock()
{
	GPIO_SetBits(GPIOB, SCK);
	Delay_timer2_ms(50);
	GPIO_ResetBits(GPIOB, SCK);
	Delay_timer2_ms(50);
	
}

void transmit(uint8_t data)
{
		GPIO_ResetBits(GPIOB, SS);
		uint8_t i = 0;
		for(i = 0; i<8;i++)
		{
			if(data & (0x80 >> i)) GPIO_SetBits(GPIOB, MOSI);
			else{GPIO_ResetBits(GPIOB, MOSI);}
		}
		clock();
}

uint8_t receive()
{
	uint8_t data = 0;
	while(GPIO_ReadInputDataBit(GPIOA, SS));
	for(int i = 0; i < 8; i++)
	{
		while(GPIO_ReadInputDataBit(GPIOB,SCK) == 0);
		
		if(GPIO_ReadInputDataBit(GPIOB, MOSI) == 1) data = data | (0x80 >> i);
		
		while(GPIO_ReadInputDataBit(GPIOB,SCK) == 1);
	}
	
	return data;
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
		
		data = receive();
	}
}



