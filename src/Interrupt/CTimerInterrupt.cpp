#include "app.h"

/*
 * CTimerInterrupt()
 */

CTimerInterrupt::CTimerInterrupt() {

//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	TIM_TimeBaseInitTypeDef timerInitStructure;
//	timerInitStructure.TIM_Prescaler = 40000;
//	timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	timerInitStructure.TIM_Period = 500;
//	timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	timerInitStructure.TIM_RepetitionCounter = 0;
//	TIM_TimeBaseInit(TIM2, &timerInitStructure);
//	TIM_Cmd(TIM2, ENABLE);
	NVIC_InitTypeDef NVIC_InitStructure;
	/* Enable the TIM2 gloabal Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* TIM2 clock enable */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	/* Time base configuration */
	timerInitStructure.TIM_Period = 1000 - 1; // 1 MHz down to 1 KHz (1 ms)
	timerInitStructure.TIM_Prescaler = 84 - 1; // 24 MHz Clock down to 1 MHz (adjust per your clock)
	timerInitStructure.TIM_ClockDivision = 0;
	timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &timerInitStructure);
	/* TIM IT enable */
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	/* TIM2 enable counter */
	TIM_Cmd(TIM2, ENABLE);

}

/*
 * ~CTimerInterrupt()
 */

CTimerInterrupt::~CTimerInterrupt() {
	// TODO Auto-generated destructor stub
}

/*
 * timerEnable
 */
void CTimerInterrupt::timerEnable(void)
{

}

extern "C" {

void TIM2_IRQHandler()
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		GPIO_ToggleBits(GPIOD, GPIO_Pin_12);
	}
}
}
