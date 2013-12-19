/*
 * app.h
 *
 *  Created on: Dec 16, 2013
 *      Author: milosz
 */

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
 * Timer Specializations
 */
#include "Interrupt/CTimerInterrupt.h"
/*
 * custom classes
 */
#include "Class/Class1.h"


#endif /* APP_H_ */
