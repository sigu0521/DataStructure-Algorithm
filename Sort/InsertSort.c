#include "Sort.h"

void InsertSort(int* Arr, int ArrSize)
{
	//forѭ���̶�n�Σ�whileѭ��������((n-1)+(n-2)+...+(1))=n/2
	//ʱ�临�Ӷ�Ϊn*(n/2)------->O(n^2)
	//�ռ临�Ӷ�ΪO(1)
	for (int i = 1; i < ArrSize; i++)
	{
		int tmp = Arr[i];
		int j = i;
		while (j > 0 && Arr[j - 1] > tmp)
		{
			Arr[j] = Arr[j - 1];
			j--;
		}
		if (j != i)
		{
			Arr[j] = tmp;
		}
	}
}
