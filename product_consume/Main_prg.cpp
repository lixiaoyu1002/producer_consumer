#include<stdlib.h>
#include<windows.h>
#include "BufferPool.h"
#include "Product.h"
#include "Consume.h"

typedef DWORD (WINAPI *pTheadFunc)(LPVOID lpParam);

const unsigned short p_count=5;        //the number of produce one time
const unsigned short c_count=5;        //the number of consumer one time
const unsigned short s_count=p_count+c_count;  //the sum number of threads
bool control = true;
HANDLE threads[s_count];               //the handle of every thread
DWORD Producer_threadID[p_count];            //the mark of producer thread
DWORD Consumer_threadID[c_count];            //the mark of consumer thread

void Create_P_Threads();
void Create_C_Threads();

void Create_P_Threads()                                  //create producer thread
{
	for(int i=0;i<p_count;i++)
	{
		 DWORD (WINAPI Product::*pProductPoint)(LPVOID lpParam) = &Product::producer;
		 int* ptemp= (int*)&pProductPoint;
		 DWORD (WINAPI *pProductThread)(LPVOID lpParam) = *(pTheadFunc*)ptemp;
		 //生产者线程
		 threads[i]=CreateThread(NULL,0,pProductThread,NULL,0,&Producer_threadID[i]);
		 if(threads[i]==NULL)
			control=false;
	}
}


void Create_C_Threads()
{
	for(int i=p_count;i<s_count;i++)
	{

		DWORD (WINAPI Consume::*pConsumePoint)(LPVOID lpParam) = &Consume::ConsumeProduct;
		int* ptemp= (int*)&pConsumePoint;
		DWORD (WINAPI *pConsumeThread)(LPVOID lpParam) = *(pTheadFunc*)ptemp;
		//消费者线程
		threads[i]=CreateThread(NULL,0,pConsumeThread,NULL,0,&Consumer_threadID[i-p_count]);
		if(threads[i]==NULL)
			control=false;
	 }
}


void info()
{
	std::cout<<"\n"<<std::endl;
	std::cout<<"produce/consume    used_total  buffer_state(from 0 to 9)"<<std::endl;
}


int main()
{
 info();
 BufferPool::GetInstance()->mutex=CreateMutex(NULL,FALSE,NULL);
 BufferPool::GetInstance()->mutex2=CreateMutex(NULL,FALSE,NULL);
 BufferPool::GetInstance()->m_hSemaphoreBufferFull=CreateSemaphore(NULL,0,SIZE_OF_BUFFER,NULL);
 BufferPool::GetInstance()->m_hSemaphoreBufferEmpty=CreateSemaphore(NULL,SIZE_OF_BUFFER,SIZE_OF_BUFFER,NULL);
 Create_C_Threads();
 Create_P_Threads();
 
	 while(control)
	 {
		  if(getchar())
		  {
			   std::cout<<std::endl;
			   std::cout<<"the total produce product number is "<<BufferPool::GetInstance()->produce_sum<<std::endl;
			   std::cout<<"the total consume product number is "<<BufferPool::GetInstance()->consume_sum<<std::endl;
			   break;
		  }
	 }
	 return 0;
}