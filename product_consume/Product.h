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
//���Ѳ�Ʒ
DWORD WINAPI producer(LPVOID lpParam);
};
#endif