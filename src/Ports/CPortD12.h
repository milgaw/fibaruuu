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
/*
 * private methods
 */
private:
	/*
	 * setupPort
	 */
	void setupPort()
	{
		/* GPIO Periph clock enable */
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	  GPIO_Init(GPIOD, &m_portStructure);
	}
	void setupPin()
	{
	  /* Configure pin in output push/pull mode */
		m_portStructure.GPIO_Pin = (1 << 12);
		m_portStructure.GPIO_Mode = GPIO_Mode_OUT;
		m_portStructure.GPIO_OType = GPIO_OType_PP;
		m_portStructure.GPIO_Speed = GPIO_Speed_100MHz;
		m_portStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	}
private:
	GPIO_InitTypeDef m_portStructure;
};

typedef class CPort<CPortD, CPin12> CGreenLed;
#endif /* CPORTD12_H_ */
