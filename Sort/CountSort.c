#include "Sort.h"


void CSort(int* A, int ASize, int K)
{
	//��ʱ�洢A�е��ź�����
	int* B = (int*)calloc(ASize, sizeof(int));
	//����A��Ԫ�صĸ���
	int* C = (int*)calloc(K, sizeof(int));
	//������A��ÿ��Ԫ�صĸ���,��¼��C��
	for (int i = 0; i < ASize; i++)
	{
		C[A[i]] = C[A[i]] + 1;
	}
	//�������ƫ����,
	for (int i = 1; i < K; i++)
	{
		C[i] = C[i] + C[i - 1];
	}
	//��B����ʱ��������õ���
	for (int i = ASize - 1; i >= 0; i--)
	{
		B[C[A[i]] - 1] = A[i];
		C[A[i]] = C[A[i]] - 1;
	}
	//��B���ź����������˳�򴫸�A
	for (int i = 0; i < ASize; i++)
	{
		A[i] = B[i];
	}

	free(C);
	free(B);
}

void CountSort(int* Arr, int ArrSize)
{
	//�ҵ������е����ֵ�������C�������ռ�
	int max = Arr[0];
	for (int i = 0; i < ArrSize; i++)
	{
		if (Arr[i] >= max)
		{
			max = Arr[i];
		}
	}
	CSort(Arr, ArrSize, max + 1);
}
