#include "Sort.h"

void BubbleSort(int* Arr, int ArrSize)
{
	//ÿ�αȽ����ڵ�Ԫ�أ������ߵĴ����ұߵģ�������
	//ÿһ�αȽ��꣬���Ὣ����һ�����ŵ�����棬ÿ�����򶼿���������һ��
	//ֱ�������Ҫ������������һ����־����û�з���������ʱ��˵���Ѿ��������
	//������ǰ�������൱����һ���Ż�
	for (int i = 1; i < ArrSize; i++)
	{
		int flag = 0;
		for (int j = 0; j < ArrSize - i; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				int tmp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = tmp;

				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
