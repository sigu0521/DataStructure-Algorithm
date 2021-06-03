#include "rbtree.h"
#include <iostream>
using namespace std;
//Ҷ�ӽڵ�Ĭ��ֵ
Node nil(-1);
Node* NIL = &nil;
//���Ĺ��캯��
Node::Node(int k) : key(k)
{
	p = left = right = NIL;
	color = BLACK;
}
//rbtree���캯��
RBTree::RBTree(Node* n) :root(n) 
{
	n->left = n->right = n->p = NIL;
}
//���������ӡ
void RBTree::InorderTreeWalk(Node* n)
{
	if (n == NIL)
		return;
	InorderTreeWalk(n->left);
	cout << n->key << ' ';
	InorderTreeWalk(n->right);
}
//����
void RBTree::RightRotate(Node* n)
{
	if (n == root)//�жϸýڵ��Ƿ�Ϊ���ڵ�
		root = n->left;

	Node* temp = n->left;

	n->left = temp->right;
	temp->right->p = n;

	temp->right = n;
	temp->p = n->p;
	if (n == n->p->left)
		n->p->left = temp;
	else
		n->p->right = temp;

	n->p = temp;
}
//����
void RBTree::LeftRotate(Node* n)
{
	if (n == root)
		root = n->right;

	Node* temp = n->right;

	n->right = temp->left;
	temp->left->p = n;

	temp->left = n;
	temp->p = n->p;
	if (n == n->p->left)
		n->p->left = temp;
	else
		n->p->right = temp;

	n->p = temp;
}
//����
Node* RBTree::Search(int k)
{
	Node* cur = root;
	
	while (cur->key != k)
	{
		//left
		if (k < cur->key && cur->left != NIL)
		{
			cur = cur->left;
		}//right
		else if (k > cur->key && cur->right != NIL)
		{
			cur = cur->right;
		}//no found
		else
			return NIL;
	}//�ҵ�
	return cur;
}
//����
Node* RBTree::Insert(int k)
{
	Node* cur = root;//��������
	Node* prev = root;//�������ֵ�ĸ����
	while (cur != NIL)//�ҵ�Ҫ�����λ��(һ�㶼������β������)
	{
		prev = cur;
		if (k < cur->key)
		{
			cur = cur->left;
		}
		else if (k > cur->key)
		{
			cur = cur->right;
		}
		else
		{
			cout << k << " already in rbtree." << endl;
			return NIL;//����ֱ�ӷ���NIL
		}
	}
	if (k < prev->key)//����߲���
	{
		prev->left = new Node(k);
		prev->left->p = prev;
		prev->left->left = prev->left->right = NIL;
		prev->left->color = RED;//�²���Ľڵ�Ĭ��Ϊ��ɫ
		//�����Ҫ������ɫ��飬��֤�����������
		InsertFixup(prev->left);
		return prev->left;//���صĶ��ǲ���Ľڵ�
	}
	else if (k > prev->key)
	{
		prev->right = new Node(k);
		prev->right->p = prev;
		prev->right->left = prev->right->right = NIL;
		prev->right->color = RED;
		InsertFixup(prev->right);
		return prev->right;
	}
}
//������ɫ
void RBTree::InsertFixup(Node* s)
{
	while (s->p->color == RED)//ֻ�и����Ϊ��ɫ���ǲ���Ҫ������ɫ
	{
		if (s->p == s->p->p->left)//������Ϊ�� red and left
		{
			Node* u = s->p->p->right;//u -->uncle  p-->parent  g-->grandparent
			if (u->color == RED)//u p ��Ϊ�� ---->u p ��ڣ�g ��� -->OK
			{
				s->p->color = u->color = BLACK;
				s = s->p->p;//����ȥ�鿴�������ɫ�Ƿ��ͻ
			}
			else if (u->color == BLACK && s == s->p->left)//g p s ������ and �ں��
			{
				//p ��� g ���---->g����--->OK
				s->p->color = BLACK;
				s->p->p->color = RED;
				RightRotate(s->p->p);
			}
			else if (u->color == BLACK && s == s->p->right)//g p s ������ and �ں��
			{
				// p ����(g s p ���������������) --> g ��� s ��� -->g ����(whileѭ��������ǵ���)
				s = s->p;
				LeftRotate(s);
			}
		}
		else if (s->p == s->p->p->right)
		{
			Node* u = s->p->p->left;
			if (u->color == RED)
			{
				s->p->color = u->color = BLACK;
				s->p->p->color = RED;
				s = s->p->p;
			}
			else if (u->color == BLACK && s == s->p->right)
			{
				s->p->color = BLACK;
				s->p->p->color = RED;
				LeftRotate(s->p->p);
			}
			else if (u->color == BLACK && s == s->p->left)
			{
				s = s->p;
				RightRotate(s);
			}
		}
	}
	root->color = BLACK;//���������ת����ɫ����󵽸��ڵ����ɫʼ��Ϊ��ɫ
}
//ɾ��
bool RBTree::Delete(int k)
{
	Node* toDelete = Search(k);
	if (toDelete == NIL)//û��Ҫɾ����ֵ������false
	{
		return false;
	}
	Node* toRepleace = toDelete;
	ColorType Delete_color = toDelete->color;
	Node* Flag;
	if (toDelete->left == NIL)//���ӿ�
	{
		Flag = toDelete->right;
		TransPlant(toDelete, toDelete->right);
	}
	else if (toDelete->right == NIL)//�Һ��ӿ�
	{
		Flag = toDelete->left;
		TransPlant(toDelete, toDelete->left);
	}
	else//�м�λ��
	{
		toRepleace = Successor(toDelete);//����������Сֵ���滻
		Flag = toRepleace->right;//�����������ɾ���Ľڵ��λ��
		Delete_color = toRepleace->color;
		if (toRepleace->p == toDelete)//��Сֵ�պ���delete��������
		{
			TransPlant(toDelete, toRepleace);
			toRepleace->left = toDelete->left;
			toDelete->left->p = toRepleace;
			toRepleace->color = toDelete->color;
		}
		else
		{
			//�ҵ���Сֵ���Ȱ���Сֵ���������ԽӺ�
			TransPlant(toRepleace, toRepleace->right);
			//����Сֵ����ɾ���Ľڵ�λ��
			toRepleace->left = toDelete->left;
			toDelete->left->p = toRepleace;
			toRepleace->right = toDelete->right;
			toDelete->right->p = toRepleace;
			TransPlant(toDelete, toRepleace);
		}
	}
	if (Delete_color == BLACK)//ɾ���ڵ��Ǻ�ɫ����Ҫ������ɫ
		DeleteFixup(Flag);
	return true;
}
//ɾ�����ɫ
void RBTree::DeleteFixup(Node* n)
{
	while (n->color == BLACK && n != root)
	{
		if (n == n->p->left)
		{
			Node* bother = n->p->right;
			if (bother->color == RED)
			{
				n->p->color = RED;
				bother->color = BLACK;
				LeftRotate(n->p);
				bother = n->p->right;
			}
			else if (bother->left->color == BLACK && bother->right->color == BLACK)
			{
				n->p->color = RED;
				n = n->p;
			}
			else if (bother->color == BLACK && bother->left->color == RED)
			{
				bother->color = RED;
				bother->left->color = BLACK;
				RightRotate(bother);
			}
			else if (bother->right->color == RED)
			{

				bother->right->color = BLACK;
				bother->color = n->p->color;
				n->p->color = BLACK;
				LeftRotate(n->p);
				n = root;
			}
		}
		else if (n = n->p->right)
		{
			Node* bother = n->p->left;
			if (bother->color == RED)
			{
				n->p->color = RED;
				bother->color = BLACK;
				RightRotate(n->p);
				bother = n->p->left;
			}
			else if (bother->left->color == BLACK && bother->right->color == BLACK)
			{
				n->p->color = RED;
				n = n->p;
			}
			else if (bother->color == BLACK && bother->right->color == RED)
			{
				bother->color = RED;
				bother->right->color = BLACK;
				LeftRotate(bother);
			}
			else if (bother->left->color == RED)
			{
				bother->left->color = BLACK;
				bother->color = n->p->color;
				n->p->color = BLACK;
				RightRotate(n->p);
				n = root;
			}
		}
	}
	n->color = BLACK;
}
//����������Сֵ�滻ɾ���ڵ�
Node* RBTree::Successor(Node* n)
{
	Node* cur = n;
	if (cur->right != NIL)
	{
		return RBTree(cur->right).Minnum();
	}
	else if (cur->p != NIL)
	{
		return cur->p;
	}
	else return NIL;
}
//���е����ֵ
Node* RBTree::Minnum()
{
	Node* cur = root;
	while (cur->left != NIL)
		cur = cur->left;
	return cur;
}
//���е���Сֵ
Node* RBTree::Maxnum()
{
	Node* cur = root;
	while (cur->right != NIL)
		cur = cur->right;
	return cur;
}
//��n2���ӵ�n1�ĸ��������
void RBTree::TransPlant(Node* n1, Node* n2)
{
	n2->p = n1->p;
	if (n1 == n1->p->left)//��
	{
		n1->p->left = n2;
	}
	else if(n1 == n1->p->right)//��
	{
		n1->p->right = n2;
	}
	else//��
		root = n2;
}
