#ifndef CPORT_H_
#define CPORT_H_

template<typename Port, typename Pin>
class CPort {
public:
	CPort();
	~CPort();
public:
	void setupClock();
	void setupPort();
	void setPort();
	void resetPort();
private:
};

#endif /* CPORT_H_ */
