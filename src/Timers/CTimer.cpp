#include "app.h"

template<typename Timer>
CTimer<Timer>::CTimer()
{
	setupInterrupt();
	setupTimer();
}

template<typename Timer>
CTimer<Timer>::~CTimer()
{
}

