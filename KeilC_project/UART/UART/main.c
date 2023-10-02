#include "stm32f10x.h"

#define TX GPIO_Pin_3
#define RX GPIO_Pin_4
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

void start_condition()
{
	GPIO_ResetBits(GPIOB, TX);
	Delay_timer2_ms(200);
}
void end_condition()
{
	GPIO_ResetBits(GPIOB, TX);
	GPIO_SetBits(GPIOB, TX);
	Delay_timer2_ms(20);
}
void transmit(uint8_t data)
{
	for(uint8_t i = 0; i< 7;i++)
	{
		if(data & (0x80 >> i)) GPIO_SetBits(GPIOB, TX);
		else GPIO_ResetBits(GPIOB, TX);
	}
}


int main()
{
	GPIO_config();
	Tim2_Register();

	uint8_t data[] = {162, 45, 86, 123};
	uint8_t i = 0;
	
	GPIO_SetBits(GPIOB, TX);
	Delay_timer2_ms(1000);
	
	while(i<4)
	{
		start_condition();
		
		transmit(data[i]);
		
		transmit_1bitCheck(data[i]);
		
		end_condition();
		i++;
		
	}
}



