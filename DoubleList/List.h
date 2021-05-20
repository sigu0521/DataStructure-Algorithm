#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;


ListNode* ListInit(); 
//�����������
void ListClear(ListNode* phead);
//���ٰ���ͷ���
void ListDestory(ListNode* phead);
ListNode* BuyListNode(LTDataType x);
void ListPrint(ListNode* phead);
//β��βɾ
void ListPushBack(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);
//ͷ��ͷɾ
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);

ListNode* ListFind(ListNode* phead, LTDataType x);
//��posǰ����x
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);


