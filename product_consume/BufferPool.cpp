#include "BufferPool.h"

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//unsigned short in, out;
//in = out = 0;
//获取单例实例
BufferPool * BufferPool::m_Instance = new BufferPool();

BufferPool * BufferPool::GetInstance()
{
if(NULL == m_Instance)
{
m_Instance = new BufferPool();
}
return  m_Instance;
}

void BufferPool::Produce()
{
 int i;
 std::cout<<"produce";
 //if(Product_ID>=10)
 // Product_ID=0;
 Product_ID++;
 produce_sum++;
 buffer[in]=Product_ID;
 printf(" buffer[%d]=%d    ",in,Product_ID);
 in=(in+1)%SIZE_OF_BUFFER;
    Product_Sum();
}

void BufferPool::Consume()
{
 int i;
 std::cout<<"consume";
 consume_sum++;
 Consume_ID=buffer[out];
 printf(" buffer[%d]=%d    ",out,Consume_ID);
 buffer[out]=0;
 out=(out+1)%SIZE_OF_BUFFER;
 Product_Sum();
}

void BufferPool::Product_Sum()
{
 int i,sum=0;
 for(i=0;i<SIZE_OF_BUFFER;i++)
 {
  if(buffer[i]!=0)
   sum++;
 }
// std::cout<<"  "<<sum<<"         ";
 //for(i=0;i<SIZE_OF_BUFFER;i++)
 //{
 // std::cout<<buffer[i]<<" ";
 //}
 printf("   %d\n", sum);
}
