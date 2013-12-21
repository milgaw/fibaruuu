#ifndef CLED_H_
#define CLED_H_

template<typename Led>
class CLed {
public:
	CLed();
	~CLed();
};

class CLed1;
template<>
class CLed<CLed1>
{

};
#endif /* CLED_H_ */
