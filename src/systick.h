#ifndef SYSTICK_H_
#define SYSTICK_H_
//
///* ----- SysTick definitions ----------------------------------------------- */
//
//#define SYSTICK_FREQUENCY_HZ       1000
//
//static __IO uint32_t uwTimingDelay;
//
///**
// * @brief  Inserts a delay time.
// * @param  nTime: specifies the delay time length, in SysTick ticks.
// * @retval None
// */
//void Delay(__IO uint32_t nTime)
//{
//  uwTimingDelay = nTime;
//
//  while (uwTimingDelay != 0)
//    ;
//}
//
///**
// * @brief  Decrements the TimingDelay variable.
// * @param  None
// * @retval None
// */
//void
//TimingDelay_Decrement(void)
//{
//  if (uwTimingDelay != 0x00)
//    {
//      uwTimingDelay--;
//    }
//}
//
//// ----------------------------------------------------------------------------
//
///**
// * @brief  This function is the SysTick Handler.
// * @param  None
// * @retval None
// */
//void SysTick_Handler(void)
//{
//	TimingDelay_Decrement();
//}



#endif /* SYSTICK_H_ */
