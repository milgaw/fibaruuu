
#include "app.h"
/*
 * TODO get rid of this
 */
#include "systick.h"

/*
 * STM32F4 CDC Usb Device interfacing to DS18B20.
 */

#define BLINK_TICKS     SYSTICK_FREQUENCY_HZ/2

// ----------------------------------------------------------------------------
/* ----- USB Device	--------------------------------------------------------- */
__ALIGN_BEGIN USB_OTG_CORE_HANDLE    USB_OTG_dev __ALIGN_END ;

int
main(void)
{
#if defined(DEBUG)
  /*
   * Send a greeting to the standard output (the semihosting debug channel
   * on Debug, ignored on Release).
   */
  printf("Hello ARM World!\n");
#endif
  /*
   * At this stage the microcontroller clock setting is already configured,
   * this is done through SystemInit() function which is called from startup
   * files (startup_cm.c) before to branch to the
   * application main. To reconfigure the default setting of SystemInit()
   * function, refer to system_stm32f4xx.c file.
   */

  RCC_ClocksTypeDef RCC_Clocks;
  /* Use SysTick as reference for the timer */
  RCC_GetClocksFreq(&RCC_Clocks);
  SysTick_Config(RCC_Clocks.HCLK_Frequency / SYSTICK_FREQUENCY_HZ);

  int seconds = 0;

	//usb init
	USBD_Init(&USB_OTG_dev,
	USB_OTG_FS_CORE_ID,
	&USR_desc,
	&USBD_CDC_cb,
	&USR_cb);

	Class1 class1;

  CTimer<CTimer2> timer2;
  CGreenLed gLed;
//
  /* Infinite loop */
  while (1)
	{
		/* Assume the LED is active low */

		/* Turn on led by setting the pin low */
  	gLed.setPort();
  	/* make led a listener of a timer */
		Delay(BLINK_TICKS);
		/* Turn off led by setting the pin high */
		gLed.resetPort();
		Delay(BLINK_TICKS);

		++seconds;

#if defined(DEBUG)
		/*
		 * Count seconds on the debug channel.
		 */
		printf("Second %d\n", seconds);
#endif
    }
}

// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

