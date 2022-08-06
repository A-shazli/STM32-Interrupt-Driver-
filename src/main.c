#include<stdint.h>
#include "stm32f4xx.h"
#include "gpio.h"
#include "7seg.h"
#include "interupt.h"
void ISR_OF_EXTI0_inc(void);
void ISR_OF_EXTI1_dec(void);
char ctr = 0;
char arr[] = {5,6,7,8};

int main(void)
{


	GPIO_Init(GPIOB,0,0,1);
	GPIO_Init(GPIOB,1,0,1);
	sev_seg_init(GPIOA,5,6,7,8,0);
	Interupt_init();
	// super loop

	while(1)
	{


	}

}

void ISR_OF_EXTI0_inc(void)
{
	//increment seven seg
	sev_seg(GPIOA,arr,++ctr);
}
void ISR_OF_EXTI1_dec(void)
{
   //decrement seven seg
	sev_seg(GPIOA,arr,--ctr);
}
void EXTI0_IRQHandler(void){
	ISR_OF_EXTI0_inc();
}
void EXTI1_IRQHandler(void){
	ISR_OF_EXTI1_dec();
}
