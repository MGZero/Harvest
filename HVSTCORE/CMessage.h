#ifndef _CMESSAGE_H_
#define _CMESSAGE_H_

#include <string>
#include <sstream>
#include "List.h"

class CMessage
{
public:
	CMessage();
	CMessage(std::string message, List<std::string> params);
	virtual ~CMessage();

	bool getContinue();
	std::string getMessage();
	int * getIntMessage();

private:
	std::string _message;
	int * _messageASCII;
	bool _continue; //determines what symbol should be shown for the "next" icon


};

#endif