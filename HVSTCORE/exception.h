#ifndef _exception_h_
#define _exception_h_
#include <string>

class exception
{
public:
	inline std::string getError(){return _errorMessage;}
	inline int getCode(){return _errorCode;}

private:
	std::string _errorMessage;
	int _errorCode;

};

#endif