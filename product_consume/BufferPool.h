#ifndef BUFFERPOOL
#define BUFFERPOOL
#include<windows.h>
#include<vector>
#include<iostream>
#include<string>
#define SIZE_OF_BUFFER 4
using namespace std;
//控制参数类
class BufferPool
{
public:
	static BufferPool * GetInstance();
	
	void Produce();
	void Consume();
	void Product_Sum();

	//多线程互斥信号量
	HANDLE mutex;
	HANDLE mutex2;

	//多线程同步信号量
	//空缓冲区
	HANDLE m_hSemaphoreBufferEmpty;
	//非空缓冲区
	HANDLE m_hSemaphoreBufferFull;

	unsigned int produce_sum;            //the total produce number
	unsigned int consume_sum;            //the total consume number

private:

	unsigned short in;                   //the mark of position entering the space 
	unsigned short out;                  //the mark of position leaving the space
	unsigned int Product_ID;
	unsigned int Consume_ID;

	static BufferPool *m_Instance;
	int buffer[SIZE_OF_BUFFER];          //缓冲池

	BufferPool()
	{
		int i = 0;
		in = out = 0;
		produce_sum = consume_sum = 0;
		Product_ID = Consume_ID = 0;
		for(;i < SIZE_OF_BUFFER; i++)
			buffer[i] = 0;
	
	};

};
#endif