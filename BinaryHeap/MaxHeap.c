#include "MaxHeap.h"


void PrintMaxHeap(MaxHeap* ph)
{
	if (ph->Size == 0)
	{
		printf("no element");
		return;
	}
	for (int i = 1; i <= ph->Size; i++)
	{
		printf("%d ", ph->a[i]);
	}
	printf("\n");
}


void MaxHeapInit(MaxHeap* ph)
{
	ph->a = malloc(sizeof(BHDataType) * MaxSize);
	if (ph->a == NULL)
	{
		printf("malloc error!");
		//exit(-1);
		return;
	}
	ph->Size = 0;
	ph->Capacity = MaxSize;
	ph->a[0] = MaxData;
}


void MaxHeapInsert(MaxHeap* ph, BHDataType x)
{
	if (ph->Size == ph->Capacity)
	{
		printf("is full! ");
		exit(-1);
		//return;
	}
	int i = ++ph->Size;
	for ( ; ph->a[i / 2] < x; i /= 2)
	{
		ph->a[i] = ph->a[i / 2];
	}
	ph->a[i] = x;
}

void MaxHeapPopFront(MaxHeap* ph)
{
	//�������Ϊ0����������û��Ԫ��
	if (ph->Size == 0)
	{
		printf("is Empty!");
		return;
	}
	//�ҵ��ѵ����һ��Ԫ��
	int end = ph->Size;
	//�����һ��Ԫ���滻��ͷ��
	ph->a[1] = ph->a[end];
	//��¼���Ԫ��Ϊ���ֵ
	BHDataType Max = ph->a[1];
	//����һ�����ӽ��
	int i, child;
	//��1��ʼ��������֤�к��ӽ�㣬��һ�δӺ��ӽ�����
	for (i = 1; 2 * i <= ph->Size; i = child)
	{
		//�ѵ�����Ϊ�����±������
		child = 2 * i;
		//������Ӳ������һ��Ԫ�أ�˵���������Һ��ӣ�ѡ���������нϴ��һ��
		if (child != ph->Size && ph->a[child] < ph->a[child + 1])
		{
			child++;
		}//������ӽ�㶼����С�������������ʣ�����ȷ���ý����ǵ�ǰ�ѵ����ֵ
		if (Max >= ph->a[child])
		{
			break;
		}
		//������ӽ������������ӽڵ�������
		else
		{
			ph->a[i] = ph->a[child];
		}
	}
	ph->a[i] = Max;
	ph->Size--;
}
