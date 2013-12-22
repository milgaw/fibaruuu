#ifndef CPORT_H_
#define CPORT_H_

template<typename Port, typename Pin>
class CPort {
public:
	CPort();
	~CPort();
public:

	void setPort();
	void resetPort();
private:
	void setupPort();
	void setupPin();
private:
	GPIO_InitTypeDef m_portStructure;
};

#endif /* CPORT_H_ */
