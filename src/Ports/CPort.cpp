#include "app.h"

template<typename Port, typename Pin>
CPort<Port, Pin>::CPort()
{
	setupPin();
	setupPort();
	// TODO Auto-generated constructor stub
}

template<typename Port, typename Pin>
CPort<Port, Pin>::~CPort()
{
	// TODO Auto-generated destructor stub
}

