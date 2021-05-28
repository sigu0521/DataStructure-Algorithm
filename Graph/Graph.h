#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 10
typedef int WeightType;		//ͼ������
typedef int DataType;		//������������
typedef int Vertex;			//��������


/*ͼ�ṹ����������*/
typedef struct GNode
{
	int Nv;		/* ������ */
	int Ne;		/* ���� */
	WeightType G[MaxVertexNum][MaxVertexNum];
	//DataType Data[MaxVertexNum];	/* ��Ŷ�������� */
}GNode;

/*�ߵĽṹ����*/
typedef struct ENode
{
	Vertex V1, V2;	//ÿ���������������㹹��
	WeightType Weight;	//�еı߻���Ȩ��
}ENode;

//���ݸ����Ķ����������һ��ͼ
GNode* CreateGraph(int VertexNum);
//����һ����
ENode* InitEdge(Vertex v1, Vertex v2, WeightType w);
//���߲���ͼ��
GNode* GraphInsert(GNode* Graph, ENode* E);


//����ʽ����ͼ
GNode* BuiltGraph();
//���߲���ͼ��
void InsertEdge(GNode** Graph, ENode* E);
