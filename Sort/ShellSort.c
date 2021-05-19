#include "Sort.h"

void ShellSort(int* Arr, int ArrSize)
{
	int step = ArrSize / 2;
	//step���ܵ���0����Ȼ������ѭ��
	for (step; step > 0; step /= 2)
	{
		for (int i = step; i < ArrSize; i++)
		{
			int j = i;
			int temp = Arr[j];
			while (j - step >= 0 && Arr[j - step] > temp)
			{
				Arr[j] = Arr[j - step];
				j = j - step;
			}
			Arr[j] = temp;
		}
	}
}
/*�Ҳ��������飬����Ӧλ�õ����Ƚϣ����в�������
*��󵱲���Ϊ1ʱ�����������Ƚϣ�����˳��
*/