#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"









void test01()
{
	GNode* MG;		//����һ��ָ��ͼ�ṹ��ָ��
	int VertexNum = 5;	//�����ж��ٸ�����
	MG = CreateGraph(VertexNum);//���ݶ���ĸ�������һ��ͼ
	/*һ��ͼ�ж��㻹�б�*/
	//�������ж����ͼ������������ͼ�в����
	ENode* E1;
	E1 = InitEdge(3, 1, 20);
	/*E1 = (ENode*)malloc(sizeof(ENode));
	if (E1 == NULL)
	{
		exit(-1);
	}
	E1->V1 = 3;
	E1->V2 = 1;
	E1->Weight = 20;*/

	//MG = GraphInsert(MG, E1);
	InsertEdge(&MG, E1);

}

GNode* BuiltGraph()
{
	GNode* Graph;	//����һ��ͼ���
	ENode* E;		//�����߽��
	//Vertex V;		//�������������
	int Nv;			//����ĸ���
	//�������� 5 1 3 1 20
	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);
	sacnf("%d", &(Graph->Ne));
	if (Graph->Ne != 0)
	{
		E = (ENode*)malloc(sizeof(ENode));
		if (NULL == E)
		{
			exit(-1);
		}
		for (int i = 0; i < Graph->Ne; i++)
		{
			scanf("%d %d %d", &(E->V1), &(E->V2), &(E->Weight));
			InsertEdge(&Graph, E);
		}
	}
	///*������������ݵĻ�����������*/
	//for (V = 0; V < Graph->Nv; V++)
	//{
	//	scanf(" %c", &(Graph->Data[V]));
	//}
	return Graph;
}
void test02()
{
	GNode* MG;
	MG = BuiltGraph();

}


int main()
{
	//test01();
	test02();

	return 0;
}