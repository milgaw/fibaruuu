#ifndef CTIMERINTERRUPT_H_
#define CTIMERINTERRUPT_H_

/*
 * TIM2 specialization
 */
class CTimer2;

template<>
class CTimer<CTimer2>
{
/*
 * public methods
 */
public:
	CTimer()
	{
		setupInterrupt();
		setupTimer();
	}

	/*
	 * TODO Timer Interrupt handler as template specialization
	 */
	static void TIM2_IRQHandler();
	/*
	 * update timer
	 */
	static bool updateTimer()
	{
		--CTimer<CTimer2>::m_timer;
		if(0 == CTimer<CTimer2>::m_timer){
			return true;
		}
		CTimer<CTimer2>::m_timer = 0;
		return false;
	}

	bool registerListener(){

	}

/*
 * private methods
 */
private:
	/*
	 * setup NVIC for timer(2)
	 */
	inline void setupInterrupt( void )
	{
		NVIC_InitTypeDef NVIC_InitStructure;

		/* Enable the TIM2 gloabal Interrupt */
		NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);
	}

	/*
	 * setup timer (2)
	 */
	inline void setupTimer( void )
	{
		TIM_TimeBaseInitTypeDef timerInitStructure;
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
	}

	/*
	 * private members
	 */
	private:
		static uint32_t m_timer; 			//current timer value
		static uint32_t m_setTimer; 	//value the timer was set


};


#endif /* CTIMERINTERRUPT_H_ */
