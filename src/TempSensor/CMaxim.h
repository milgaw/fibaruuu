#ifndef CMAXIM_H_
#define CMAXIM_H_

class CMaxim;

template<>
class CTempSensor<CMaxim>
{
public:
	CTempSensor(){}
	~CTempSensor(){}
	template<typename Timer>
	bool registerAtTimer(Timer & timer){
		if(timer.registerListener){

		}
	}

};

#endif /* CMAXIM_H_ */
