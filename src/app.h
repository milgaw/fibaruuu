#ifndef APP_H_
#define APP_H_

//#include <utility>
//#include <array>

/*
 * Utilities
 */
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include <stdio.h>
/*
 * C++
 */
#include <unordered_map>
#include <atomic>
#include <vector>
/*
 * USB DEVICE INTERFACE
 * TODO Get rid of that from root src
 */
extern "C"{
	#include "usbd_cdc_core.h"
	#include "usbd_cdc.h"
	#include "usbd_usr.h"
	#include "usbd_desc.h"
	#include "usb_core.h"
	#include "usbd_core.h"
}
/*
 * PORTS Specs
 * TODO Specialize LED3 LED5 LED6
 */

#include "Ports/CPort.h"
// LED 4
#include "Ports/CPortD12.h"

/*
 * Timer template and Specializations
 */
#include "Timers/CTimer.h"
#include "Timers/CTimer2.h"
/*
 * Temperature sensors
 */
#include "TempSensor/CTempSensor.h"
#include "TempSensor/CMaxim.h"

#endif /* APP_H_ */
