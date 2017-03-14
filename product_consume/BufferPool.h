#ifndef BUFFERPOOL
#define BUFFERPOOL
#include<windows.h>
#include<vector>
#include<iostream>
#include<string>
#define SIZE_OF_BUFFER 4
using namespace std;
//���Ʋ�����
class BufferPool
{
public:
	static BufferPool * GetInstance();
	
	void Produce();
	void Consume();
	void Product_Sum();

	//���̻߳����ź���
	HANDLE mutex;
	HANDLE mutex2;

	//���߳�ͬ���ź���
	//�ջ�����
	HANDLE m_hSemaphoreBufferEmpty;
	//�ǿջ�����
	HANDLE m_hSemaphoreBufferFull;

	unsigned int produce_sum;            //the total produce number
	unsigned int consume_sum;            //the total consume number

private:

	unsigned short in;                   //the mark of position entering the space 
	unsigned short out;                  //the mark of position leaving the space
	unsigned int Product_ID;
	unsigned int Consume_ID;

	static BufferPool *m_Instance;
	int buffer[SIZE_OF_BUFFER];          //�����

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