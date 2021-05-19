#include "Sort.h"

int partition(int* Arr, int left, int right)
{
	int pivot = Arr[left];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (i < j && Arr[j] >= pivot)
		{
			j--;
		}
		//ps���ҵ�������һ��ֵ�Ȼ�׼ֵ��С�Ļ����Ͱ����ֵ�ŵ����ȥ
		Arr[i] = Arr[j];
		while (i < j && Arr[i] <= pivot)
		{
			i++;
		}
		//�ҵ�ǰ����һ��ֵ�Ȼ�׼ֵ��Ļ����Ͱ����ֵ�ŵ�����ȥ�����֪��i��j����ѭ����ֹ
		Arr[j] = Arr[i];
	}
	Arr[i] = pivot;
	return i;
}

void QSort(int* Arr, int left, int right)
{
	if (left < right)
	{
		//�һ�׼λ�ã�ÿ���ҵ��Ļ�׼λ�ö��Ѿ���������ˣ���Ϊ��׼λ�õ���߱���С���ұ߱�����
		//���Եݹ�ʱ�Ͳ������Ż�׼λ���ˣ��൱��ÿ��������֮���׼λ�ö����ź��ˣ��ݹ������ֹ
		int mid = partition(Arr, left, right);
		QSort(Arr, left, mid - 1);
		QSort(Arr, mid + 1, right);
	}
}
/*���ŵĻ���˼�����ѡ��һ����׼λ�ã����������׼λ��С�����ŵ�������ߣ�
**�����λ�ô�����ŵ��ұߣ��ݹ�Ľ�����Ԫ���������*/
void QuickSort(int* Arr, int ArrSize)
{
	QSort(Arr, 0, ArrSize - 1);
}

