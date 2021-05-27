#include "AvlTree.h"


void AvlTreeInit(AvlNode** root)
{
	assert(*root);
	*root = NULL;
}

static int Height(AvlNode* root)
{
	if (NULL == root)
	{
		return -1;
	}
	else
	{
		return root->Height;
	}
}



AvlNode* AvlTreeInsert(AvlNode* root, int data)
{
	if (NULL == root)
	{
		root = (AvlNode*)malloc(sizeof(AvlNode));
		if (NULL == root)
		{
			exit(-1);
		}
		root->value = data;
		root->Left = root->Right = NULL;
		root->Height = 0;
	}
	else if (data < root->value)
	{
		root->Left = AvlTreeInsert(root->Left, data);
		//����߲��� L
		if (Height(root->Left) - Height(root->Right) == 2)
		{
			//���뵽�������������� L
			if (data < root->Left->value)  //LL
			{
				//ִ��һ�ε���ת
				root = SingleRotateWithLeft(root);
			}
			else   //LR
			{
				//˫��ת 
				root = DoubleRotateWithLeft(root);
			}
		}
	}
	else if (data > root->value)
	{
		root->Right = AvlTreeInsert(root->Right, data);
		//���ұ߲��� R
		if (Height(root->Right) - Height(root->Left) == 2)
		{
			//���뵽�������������� L
			if (data < root->Right->value)  //RL
			{
				//˫��ת 
				root = DoubleRotateWithRight(root);
			}
			else   //RR
			{
				//ִ��һ�ε���ת
				root = SingleRotateWithRight(root);
			}
		}
	}
	//���������ڵ�ĸ߶�
	root->Height = fmax(Height(root->Left), Height(root->Right)) + 1;
	return root;
}

//��������ת LL
AvlNode* SingleRotateWithLeft(AvlNode* P)
{
	//P  ��ָParent   S   ��ָSon
	AvlNode* S;
	S = P->Left;
	//����ת 1. P������ڵ�λ��  ָ��  S�ڵ���ҽڵ�
	//2. ��S�ڵ�ճ��������ӽڵ�  ���ӵ�  P�ڵ�
	P->Left = S->Right;
	S->Right = P;

	//���¸߶�
	P->Height = fmax(Height(P->Left), Height(P->Right)) + 1;
	S->Height = fmax(Height(S->Left), Height(S->Right)) + 1;

	//����S��ʾ S���游�ڵ���ӽڵ�
	return S;
}
//��������ת RR
AvlNode* SingleRotateWithRight(AvlNode* P)
{

	AvlNode* S;
	S = P->Right;
	//����ת 1. P�����ҽڵ�λ��  ָ��  S�ڵ����ڵ�
	//2. ��S�ڵ�ճ��������ӽڵ�  ���ӵ�  P�ڵ�
	P->Right = S->Left;
	S->Left = P;

	//���¸߶�
	P->Height = fmax(Height(P->Left), Height(P->Right)) + 1;
	S->Height = fmax(Height(S->Left), Height(S->Right)) + 1;

	//����S��ʾ S���游�ڵ���ӽڵ�
	return S;
}

//������������תLR
AvlNode* DoubleRotateWithLeft(AvlNode* G)
{
	//���ȶ��游�ڵ㣨G�ڵ㣩���ӽڵ㣨P�ڵ㣩����һ������ת
	G->Left = SingleRotateWithRight(G->Left);//R
	//Ȼ���ٶ��游�ڵ����һ������ת
	return SingleRotateWithLeft(G);//L
}

//������������תRL
AvlNode* DoubleRotateWithRight(AvlNode* G)
{
	//���ȶ��游�ڵ㣨G�ڵ㣩���ӽڵ㣨P�ڵ㣩����һ������ת
	G->Right = SingleRotateWithLeft(G->Right);//L
	//Ȼ���ٶ��游�ڵ����һ������ת
	return SingleRotateWithRight(G); //R
}