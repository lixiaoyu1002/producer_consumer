#ifndef CONSUME
#define CONSUME
#include "BufferPool.h"
#include<windows.h>
#include<vector>
#include<iostream>
#include<string>
class Consume
{
public:
Consume(){};
~Consume(){};
//消费产品
DWORD WINAPI ConsumeProduct(LPVOID lpParam);
};
#endif