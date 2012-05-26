#include "CVCore.h"

void * CVCore::sendAddress()
{
	if (currentThread->status == threadStats::THREAD_PROCESSING && !standBy)
		return currentThread->getEntityAddress();

	return 0;
}

void CVCore::listenToKernel(bool begin)
{
	standBy = !begin;
}
command * CVCore::sendToKernel()
{
	return compiledCommand;
}

void CVCore::processThread()
{
	//check thread stats
	if (currentThread->status == threadStats::THREAD_NULL)
		return;
	else if (currentThread->status == threadStats::THREAD_PROCESSING)
	{
		if (compiledCommand)
		{
			delete compiledCommand;
			compiledCommand = 0;
		}

		compiledCommand = new command(currentThread->getScript(), currentThread->currentLine);
	}

}