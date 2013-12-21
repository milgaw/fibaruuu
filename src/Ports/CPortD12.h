#ifndef CPORTD12_H_
#define CPORTD12_H_

class CPortD;
class CPin12;

template<>
class CPort<CPortD, CPin12>
{
/*
 * public methods
 */
public:
	/*
	 * setupPort
	 */
	void setupPort()
	{

		/* GPIO Periph clock enable */
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);


	  GPIO_InitTypeDef GPIO_InitStructure;

	  /* Configure pin in output push/pull mode */
	  GPIO_InitStructure.GPIO_Pin = (1 << 12);
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  GPIO_Init(GPIOD, &GPIO_InitStructure);
	}
	/*
	 * setPort
	 */
	void setPort()
	{
	  GPIOD->BSRRL = 12;
	}
	/*
	 * resetPort
	 */
	void resetPort()
	{
//		GPIO_ResetBits(GPIOD, (1 << 12));
		GPIOD->BSRRH = 12;
	}

};

typedef class CPort<CPortD, CPin12> CGreenLed;
#endif /* CPORTD12_H_ */
