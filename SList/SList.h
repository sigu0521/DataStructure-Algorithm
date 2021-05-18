#pragma once
#include <stdio.h>
#include <stdlib.h>


typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

SListNode* BuySListNode(SListDataType x);
void SListPrint(SListNode** pphead);

//β��βɾ
void SListPushBack(SListNode** pphead, SListDataType x);
void SListPopBack(SListNode** pphead);
//ͷ��ͷɾ
void SListPushFront(SListNode** pphead, SListDataType x);
void SListPopFront(SListNode** pphead);

//�м����ɾ��
