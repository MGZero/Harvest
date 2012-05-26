#include "CMessage.h"

CMessage::CMessage(){}

CMessage::CMessage(std::string message, List<std::string> params)
{
	_message = message;
	_continue = atoi(params[0].c_str());

	_messageASCII = new int[_message.length()];

	for(int i = 0; i < _message.length(); i++)
		_messageASCII[i] = (int)_message[i];
}

CMessage::~CMessage()
{
	if (_messageASCII)
	{
		delete [] _messageASCII;
		_messageASCII = 0;
	}
}

bool CMessage::getContinue()
{
	return _continue;
}

std::string CMessage::getMessage()
{
	return _message;
}