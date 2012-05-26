#include "CKernel.h"

void CKernel::addToQueue(CThread *thread)
{
	thread->status = threadStats::THREAD_READY;
	readyQueue.enqueue(&thread);
}

void CKernel::contextSwitch(int coreID)
{
	cores[coreID].currentThread->status = threadStats::THREAD_WAITING;
	contextQueue.enqueue(&cores[coreID].currentThread);
	cores[coreID].currentThread = 0;
}

void CKernel::assignToCore(queue Queue)
{
	for (int i = 0; i < 4; i++)
	{
		if (!cores[i].currentThread)
		{
			cores[i].currentThread = (CThread*)Queue.dequeue();
			cores[i].currentThread->status = threadStats::THREAD_PROCESSING;
			return;
		}
	}
}

void CKernel::checkForFinishedCommand(bool finished, int coreID)
{
	if (finished)
		cores[coreID].currentThread->currentLine++;
}

command CKernel::sendToMapCreation(int coreID)
{
	command * tempCom = cores[coreID].sendToKernel();
	return *tempCom;
}

void * CKernel::sendEntityAddress(int coreID)
{
	void * temp = 0;
	temp = cores[coreID].sendAddress();
	return temp;
}

void CKernel::waitForMapCreation(bool begin, int coreID)
{
	cores[coreID].listenToKernel(begin);
}

void CKernel::executeCore(int coreID)
{
	cores[coreID].processThread();
	

}

