#include "app.h"
#include <string>
//uint32_t CTimer<CTimer2>::m_timer = 0;

/*
 * TODO IRQ Handler as member function / template spec
 */
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
