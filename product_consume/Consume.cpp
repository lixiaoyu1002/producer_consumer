#include "Consume.h"
//---------------------------------------------------------------------------

DWORD WINAPI Consume::ConsumeProduct(LPVOID lpParam)
{
	while (true)
	{
		//等待非空的缓冲区出现，消费者进行消费，直到事件值为0
		WaitForSingleObject(BufferPool::GetInstance()->m_hSemaphoreBufferFull, INFINITE);
		WaitForSingleObject(BufferPool::GetInstance()->mutex2,INFINITE);                //the mutex P operation
		BufferPool::GetInstance()->Consume();
		Sleep(1000);
	    ReleaseMutex(BufferPool::GetInstance()->mutex2);                                //resource semaphore P operation
		ReleaseSemaphore(BufferPool::GetInstance()->m_hSemaphoreBufferEmpty,1,NULL);            //the mutex P operation
	}
	return 0;
}