#include "List.h"

ListNode* Init02()
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (NULL == newnode)
	{
		printf("malloc error!");
		exit(-1);
	}
	newnode = NULL;
	return newnode;
}

ListNode* Insert02(ListNode* pp, int data)
{
	if (pp == NULL)
	{
		/*pp = (ListNode*)malloc(sizeof(ListNode));
		if (pp == NULL)
		{
			printf("malloc error!");
			exit(-1);
		}
		pp->value = data;
		pp->next = NULL;*/
		pp = BuyNode(data);
	}
	else
	{
		ListNode* temp = pp;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		/*ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
		if (newnode == NULL)
		{
			printf("malloc error!");
			exit(-1);
		}
		newnode->value = data;
		newnode->next = NULL;*/
		ListNode* newnode = BuyNode(data);
		temp->next = newnode;
	}
	return pp;
}

ListNode* Delete02(ListNode* pp, int data)
{
	if (pp == NULL)
	{
		printf("no node!");
		return NULL;
	}
	if (pp->value == data)
	{
		pp = pp->next;
	}
	else
	{
		ListNode* pre = pp;
		ListNode* cur = pp->next;
		while (cur != NULL)
		{
			if (cur->value == data)
			{
				if (cur->next != NULL)
				{
					pre->next = cur->next;
				}
				else
				{
					pre->next = NULL;
				}
			}
			pre = cur;
			cur = cur->next;
		}
	}
	return pp;
}