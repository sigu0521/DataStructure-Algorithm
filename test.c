#include "List.h"


void Print(ListNode** pp)
{
	ListNode* temp = *pp;
	if (temp == NULL)
	{
		printf("no node!");
		return;
	}
	while (temp)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

ListNode* BuyNode(int data)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		printf("malloc error!");
		exit(-1);
	}
	newnode->value = data;
	newnode->next = NULL;

	return newnode;
}

void Init01(ListNode* *pp)
{
	assert(*pp);
	*pp = NULL;
}

void Insert01(ListNode** pp, int data)
{
	if (*pp == NULL)
	{
		/**pp = (ListNode*)malloc(sizeof(ListNode));
		if (*pp == NULL)
		{
			printf("malloc error!");
			exit(-1);
		}
		(*pp)->value = data;
		(*pp)->next = NULL;*/
		*pp = BuyNode(data);
	}
	else
	{ 
		ListNode* temp = *pp;
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
		//temp = temp->next;
	}
}

void Delete01(ListNode** pp, int data)
{
	if (*pp == NULL)
	{
		printf("no node");
		return;
	}
	if ((*pp)->value == data)
	{
		(*pp) = (*pp)->next;
	}
	else
	{
		ListNode* pre = *pp;
		ListNode* cur = (*pp)->next;
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
				return;
			}
			pre = cur;
			cur = cur->next;
		}
		printf("no node!");
		return;
	}
}

void Destory(ListNode** pp)
{
	if (*pp != NULL)
	{
		Destory(&(*pp)->next);
		free(*pp);
		*pp = NULL;
	}
}

void test01()
{
	//初始化方法
	ListNode* p = NULL;//初始化第四种方法
	//p = Init01();//初始化第一种方法
    //Init02(&p); //初始化第二种方法
	//p = NULL;  //初始化第三种方法

	//插入结点01  无返回值
	/*Insert01(&p, 1);
	Insert01(&p, 2);
	Insert01(&p, 3);*/
	//插入结点02  有返回值
	p = Insert02(p, 1);
	p = Insert02(p, 2);
	p = Insert02(p, 3);
	Print(&p);

	//删除结点01  无返回值
	/*Delete01(&p, 3);
	p = Insert02(p, 4);*/
	//删除结点02  有返回值
	p = Delete02(p, 4);
	p = Insert02(p, 4);

	Print(&p);
	//Destory(&p);
	Print(&p);

}

int main()
{
	test01();

	return 0;
}