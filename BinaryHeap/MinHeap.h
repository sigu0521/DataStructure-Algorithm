#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 11
#define MinData (-100)

typedef int BHDataType;

typedef struct MinHeap
{
	BHDataType* a;
	int Size;
	int Capacity;
}MinHeap;

//��ʼ���ʹ�ӡ
void MinHeapInit(MinHeap* ph);
void PrintMinHeap(MinHeap* ph);

//���Ѳ���һ��Ԫ��
void MinHeapInsert(MinHeap* ph, BHDataType x);
//ɾ��һ����ָɾ�����Ľڵ�
void MinHeapPopFront(MinHeap* ph);
