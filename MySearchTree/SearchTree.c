#include "SearchTree.h"

TreeNode* SearchTreeInit()
{
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	if (NULL == root)
	{
		exit(-1);
	}
	root = NULL;
	return root;
}
TreeNode* SearchTreeBuyNode(int data)
{
	TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
	if (NULL == newnode)
	{
		exit(-1);
	}
	newnode->value = data;
	newnode->Left = newnode->Right = NULL;

	return newnode;
}


TreeNode* SearchTreeInsert(TreeNode* root, int data)
{
	if (root == NULL)
	{
		root = SearchTreeBuyNode(data);
	}
 	else if (data < root->value)
	{
		root->Left = SearchTreeInsert(root->Left, data);
	}
	else if (data > root->value)
	{
		root->Right = SearchTreeInsert(root->Right, data);
	}

	return root;
}
//�ǵݹ�ʵ�������ֵ
TreeNode* FindMax(TreeNode* root)
{
	if (root != NULL)
	{
		while (root->Right != NULL)
		{
			root = root->Right;
		}
	}
	return root;
}
//�ݹ�ʵ������Сֵ
TreeNode* FindMin(TreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (root->Left == NULL)
	{
		return root;
	}
	else
		return FindMin(root->Left);
}

TreeNode* Find(TreeNode* root, int data)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (data < root->value)
	{
		return Find(root->Left,data);
	}
	else if (data > root->value)
	{
		return Find(root->Right, data);
	}
	else 
		return root;
}
//ɾ��Ҫ���������
//1.û�нڵ� 2.���ڸ��ڵ� 3.С�ڸ��ڵ� 4.Ҫɾ���Ľڵ���һ���ӽڵ� 5.Ҫɾ���Ľڵ������ڵ�
TreeNode* SearchTreeDelete(TreeNode* root, int data)
{
	TreeNode* temp;
	if (root == NULL)
	{
		return NULL;
	}
	else if (data < root->value)
	{
		root->Left = SearchTreeDelete(root->Left, data);
	}
	else if (data > root->value)
	{
		root->Right = SearchTreeDelete(root->Right, data);
	}
	else if (root->Left && root->Right)
	{
		temp = FindMin(root->Right);
		root->value = temp->value;
		root->Right = SearchTreeDelete(root->Right, temp->value);
	}
	else
	{
		temp = root;
		if (root->Left == NULL)
		{
			root = root->Right;
		}
		else if (root->Right == NULL)
		{
			root = root->Left;
		}
		free(temp);
	}
	return root;
}

void SearchTreeDestroy(TreeNode** root)
{
	if (*root)
	{
		SearchTreeDestroy(&(*root)->Left);
		SearchTreeDestroy(&(*root)->Right);
		free(*root);
		*root = NULL;
	}
}

void InOreder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	InOreder(root->Left);
	printf("%d ", root->value);
	InOreder(root->Right);
}
