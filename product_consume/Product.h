#ifndef PRODUCT
#define PRODUCT
#include "BufferPool.h"
#include<windows.h>
#include<vector>
#include<iostream>
#include<string>
class Product
{
public:
Product(){};
~Product(){};
//消费产品
DWORD WINAPI producer(LPVOID lpParam);
};
#endif