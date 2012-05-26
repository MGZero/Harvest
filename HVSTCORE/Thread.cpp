#include "Thread.h"

CThread::CThread(HS Script, void * entityAddress)
{
	status = threadStats::THREAD_UNASSIGNED;
	this->script = script;
	this->lineCount = lineCount;
	this->entityAddress = entityAddress;
}

CThread::~CThread()
{
	lineCount = 0;
	status = threadStats::THREAD_NULL;
	entityAddress = 0;
}

int CThread::getlineCount()
{
	return lineCount;
}

HS CThread::getScript()
{
	return script;
}

/*void * CThread::getEntityAddress()
{
	return entityAddress;
}*/
	
