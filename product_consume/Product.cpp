#include "Product.h"
//---------------------------------------------------------------------------
DWORD WINAPI  Product::producer(LPVOID lpParam)
{
	while (true)
	{
		//�ȴ��ǿյĻ��������֣������߽������ѣ�ֱ���ź���ֵΪ0
		WaitForSingleObject(BufferPool::GetInstance()->m_hSemaphoreBufferEmpty, INFINITE);
		WaitForSingleObject(BufferPool::GetInstance()->mutex,INFINITE);                //the mutex P operation
		BufferPool::GetInstance()->Produce();
		Sleep(1000);
		ReleaseMutex(BufferPool::GetInstance()->mutex);                                //resource semaphore P operation
		ReleaseSemaphore(BufferPool::GetInstance()->m_hSemaphoreBufferFull,1,NULL);            //the mutex P operation
	}
	return 0;
}