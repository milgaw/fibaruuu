#ifndef CPORTD12_H_
#define CPORTD12_H_
/*
 * TODO Counter of pins assigned to PORTD to switch on/off GPIOD Clock
 */
class CPortD;
/*
 * TODO Makec CPin more flexible, reusable for different pin numbers/modes etc.
 */
class CPin12;

template<>
class CPort<CPortD, CPin12>
{
/*
 * public methods
 */
public:

	CPort()
	{
		setupPin();
		setupPort();
		// TODO Auto-generated constructor stub
	}

	/*
	 * setPort
	 */
	void setPort()
	{
	  GPIOD->BSRRL = 1 << 12;
	}
	/*
	 * resetPort
	 */
	void resetPort()
	{
		GPIOD->BSRRH = 1 << 12;
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
	}
	void setupPin()
	{
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	  /* Configure pin in output push/pull mode */
		m_portStructure.GPIO_Pin = (1 << 12);
		m_portStructure.GPIO_Mode = GPIO_Mode_OUT;
		m_portStructure.GPIO_OType = GPIO_OType_PP;
		m_portStructure.GPIO_Speed = GPIO_Speed_100MHz;
		m_portStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  GPIO_Init(GPIOD, &m_portStructure);
	}
private:
	GPIO_InitTypeDef m_portStructure;
};

typedef class CPort<CPortD, CPin12> CGreenLed;
#endif /* CPORTD12_H_ */
