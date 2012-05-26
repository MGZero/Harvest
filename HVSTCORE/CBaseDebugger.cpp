#include "CBaseDebugger.h"

CBaseDebugger::CBaseDebugger(bool engine)
{
	debugFile = new CDBG("debugDump.DBG");
	fromEngine = engine;
	debugFile->confirm();
}

CBaseDebugger::~CBaseDebugger()
{
	delete debugFile;
}

void CBaseDebugger::live()
{
	if (!fromEngine)
		delete this;
}

void CBaseDebugger::writeToFile(std::string data)
{
	debugFile->writeString(data);
}

