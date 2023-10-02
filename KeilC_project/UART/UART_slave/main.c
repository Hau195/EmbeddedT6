#include "stm32f10x.h"

#define TX GPIO_Pin_3
#define RX GPIO_Pin_4


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

uint8_t count_Bit1(uint8_t data)
{
	uint8_t count = 0;
	for(uint8_t i = 0; i< 8; i++)
	{
		if(data & (0x80 >> i)) count++;
		return count;
	}
		
}
void transmit_1bitCheck(uint8_t data)
{
	if(count_Bit1(data) % 2) GPIO_SetBits(GPIOB, TX);
	else GPIO_ResetBits(GPIOB, TX);
	Delay_timer2_ms(100);
}


void waitStart()
{
	while(GPIO_ReadInputDataBit(GPIOB, RX) == 1);
}
void wait_end()
{
	while(GPIO_ReadInputDataBit(GPIOB, RX) == 0);
}
uint8_t receive()
{
	uint8_t data = 0;
	for(int i = 0; i < 8; i++)
	{
		if(GPIO_ReadInputDataBit(GPIOB, RX) == 1) data = data | (0x80 >> i);
	}
	
	return data;
}


void receive_array(uint8_t data[], uint8_t length)
{
	for(int i = 0; i < 8; i++)
	{
		waitStart();
		data[i] = receive();
		
		if(((count_Bit1(data[i] % 2)) & (GPIO_ReadInputDataBit(GPIOB, RX) == 0))
			|| (!(count_Bit1(data[i]) % 2) & (GPIO_ReadInputDataBit(GPIOB, RX) == 1))) return;
		
		wait_end();
	}
}


int main()
{
	GPIO_config();
	Tim2_Register();
	uint8_t data[4] = {0};
	
	while(1)
	{
		//GPIO_SetBits(GPIOC, GPIO_Pin_13);
		//Delay_timer2_ms(1000);
		//GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		//Delay_timer2_ms(1000);
		
		receive_array(data, 4);
	}
}



