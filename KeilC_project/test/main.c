#include "stm32f10x.h"


void GPIO_config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void Delay(int n)
{
	while(n--)
	{
	}
}
int main()
{
	GPIO_config();
	
	while(1)
	{
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		Delay(10000000);
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		Delay(10000000);
	}
}
