#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//˳�����Ч�����������б���������
//��̬˳�����ƣ��̶���С��
//ʵ�ֶ�̬˳���
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;	//ָ��̬���ٵ�����
	int size;		//��Ч���ݵĴ�С
	int capacity;	//�����ռ�Ĵ�С
}SL,SeqList;


void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListCheckCaapacity(SL* ps);

//β��βɾ��ͷ��ͷɾ
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
//����λ�õĲ���ɾ��
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);
//����  ���ֲ���
int SeqListFind(SL* ps, SLDataType x);

//����
void SeqListSort(SL* ps);

//�������ж��ֲ���
int SeqListBubaryFind(SL* ps, SLDataType x);
