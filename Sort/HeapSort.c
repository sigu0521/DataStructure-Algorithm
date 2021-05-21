#include "Sort.h"


void Percdown(int* Arr, int parent, int N)
{
	int temp = Arr[parent];
	int child = 2 * parent + 1;
	while (child <= N)
	{
		if (child != N && Arr[child] < Arr[child + 1])
		{
			child++;
		}
		if (temp >= Arr[child]) break;

		Arr[parent] = Arr[child];
		parent = child;
		child = 2 * parent + 1;
	}
	Arr[parent] = temp;
}

void HeapSort(int* Arr, int ArrSize)
{
	//�����󶥶�
	for (int i = (ArrSize - 2) / 2; i >= 0; i--)
	{
		//ע�⿪ʼλ��Ϊ0�����Ժ�ƽ���ķ������в�ͬ
		//��0�±꿪ʼ��������Ӧ���ӽ��Ϊ
		//parent = i��
		//child = 2*i+1��
		//���Ƶ�child = ArrSize-1ʱ
		//parent = (ArrSize - 2)/2
		Percdown(Arr, i, ArrSize - 1);
	}
	//����λ�ú��ϸ�����
	for (int i = ArrSize - 1; i > 0; i--)
	{
		int tmp = Arr[i];
		Arr[i] = Arr[0];
		Arr[0] = tmp;
		Percdown(Arr, 0, i-1);
	}
}
