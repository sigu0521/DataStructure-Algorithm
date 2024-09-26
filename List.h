#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode
{
	int value;
	struct ListNode* next;
}ListNode;


ListNode* Init02();
void Destory(ListNode** pp);
ListNode* BuyNode(int data);

ListNode* Insert02(ListNode* pp, int data);
ListNode* Delete02(ListNode* pp, int data);
void Print(ListNode** pp);
