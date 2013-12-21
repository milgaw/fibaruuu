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
/*
 * USB DEVICE INTERFACE
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
 *PORTS Specs
 */

#include "Ports/CPort.h"
#include "Ports/CPortD12.h"

/*
 * LEDS Specs
 */
#include "Leds/CLed.h"
//#include "Leds/CLed1.h"

/*
 * Timer template and Specializations
 */
#include "Timers/CTimer.h"
#include "Timers/CTimer2.h"

/*
 * custom classes
 */
#include "Class/Class1.h"


#endif /* APP_H_ */
