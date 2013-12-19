#ifndef CTIMERINTERRUPT_H_
#define CTIMERINTERRUPT_H_

class CTimerInterrupt {
public:
	CTimerInterrupt();
	virtual ~CTimerInterrupt();
	void timerEnable(void);
	/*
	 * TODO Timer Interrupt handler as template specialization
	 */
	void TIM2_IRQHandler(){
		assert_param(false);
	};
};


#endif /* CTIMERINTERRUPT_H_ */
