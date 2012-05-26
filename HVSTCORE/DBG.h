#ifndef _DBG_H_
#define _DBG_H_

#include <stdio.h>
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <istream>

class CDBG
{
public:
	CDBG(){}
	CDBG(const char * fileName);

	~CDBG();

	void writeString();
	void writeString(std::string text);
	void confirm();
	void catchError(std::string error);

private:
	std::ofstream debugDump;

};

#endif