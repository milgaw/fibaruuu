#ifndef CTIMER_H_
#define CTIMER_H_
/*
 * Generic Timer
 */
template<typename Timer, typename... Listeners>
class CTimer {
public:
	CTimer();
	~CTimer();
public:
	void 				timerEnable(void);
	static bool updateTimer();
	bool 				registerListener();
private:
/*
 * setup NVIC for current timer
 */
	inline void setupInterrupt( void ){}
	inline void setupTimer( void ){}

};

#endif /* CTIMER_H_ */
