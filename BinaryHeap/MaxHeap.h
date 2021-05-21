#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 11
#define MaxData 100

typedef int BHDataType;

typedef struct MaxHeap
{
	BHDataType* a;
	int Size;
	int Capacity;
}MaxHeap;

//��ʼ���ʹ�ӡ
void MaxHeapInit(MaxHeap* ph);
void PrintMaxHeap(MaxHeap* ph);

//���Ѳ���һ��Ԫ��
void MaxHeapInsert(MaxHeap* ph, BHDataType x);
//ɾ��һ����ָɾ�����Ľڵ�
void MaxHeapPopFront(MaxHeap* ph);
