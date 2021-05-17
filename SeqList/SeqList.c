
#include "SeqList.h"

//��ʼ��
void SeqListInit(SL* ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}

	ps->size = 0;
	ps->capacity = 4;
}
//��ӡ����
void SeqListPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//��̬����
void SeqListCheckCaapacity(SL* ps)
{
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
	}
}

//β��βɾ��ͷ��ͷɾ
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//���������Ҫ����
	SeqListCheckCaapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SL* ps)
{
	assert(ps);

	//ps->a[ps->size - 1] = 0;
	ps->size--;
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	int end = ps->size - 1;
	//���������Ҫ����
	SeqListCheckCaapacity(ps);
	//ÿһ��������Ų��
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	//�����ͷ������
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SL* ps)
{
	assert(ps);

	int start = 0;
	while (start < ps->size)
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	ps->size--;
}
//����λ�õĲ���ɾ��
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	SeqListCheckCaapacity(ps);
	//(posһ��Ҫ��0��size֮��)
	if (pos > ps->size - 1 || pos < 0)
	{
		printf("����λ��%d�������鷶Χ�ڣ�����ʧ��\n",pos);
		exit(-1);
	}
	int end = ps->size - 1;
	//ÿһ��������Ų��
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	//�����pos������
	ps->a[pos] = x;
	ps->size++;
}
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	if (pos > ps->size - 1 || pos < 0)
	{
		printf("ɾ��λ��%d�������鷶Χ�ڣ�ɾ��ʧ��\n", pos);
		exit(-1);
	}

	int start = pos;
	while (start < ps->size)
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	ps->size--;
}

//���� 
int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;//�ҵ��ͷ����±�
		}
	}
	return -1;//û�ҵ�
}

//����  Bubble Sort
void SeqListSort(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		int flag = 0;
		for (int j = 0; j < ps->size - i - 1; j++)
		{
			if (ps->a[j] > ps->a[j + 1])
			{
				int tmp = ps->a[j];
				ps->a[j] = ps->a[j + 1];
				ps->a[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

//�������ж��ֲ���
int SeqListBubaryFind(SL* ps, SLDataType x)
{
	assert(ps);
	if (ps->a[0] > x || ps->a[ps->size-1] < x)
	{
		printf("%d����������\n",x);
		return -1;
	}

	int left = 0;
	int right = ps->size - 1;
	int mid = (left + right) / 2;
	if (ps->a[mid] > x)
	{
		right = mid;
	}
	else if (ps->a[mid] < x)
	{
		left = mid;
	}
	else if (ps->a[mid] == x)
	{
		return mid;
	}
	printf("%d�����ڣ�δ���������ҵ�,����", x);
	return -1;
}