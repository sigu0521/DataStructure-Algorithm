#define _CRT_SECURE_NO_WARNINGS 1

#include "SearchTree.h"

void InitBSTree(BSTNode** pRoot)
{
    assert(pRoot);
    *pRoot = NULL;
}

BSTNode* BuyBSTNode(BSDataType data)
{
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    if (NULL == newNode)
    {
        printf("�����ڵ�ʧ��\n");
        return NULL;
    }
    newNode->_data = data;
    newNode->_pLeft = NULL;
    newNode->_pRight = NULL;
    return newNode;
}

void InOrder(BSTNode* pRoot)
{
    if (NULL == pRoot)
        return;
    InOrder(pRoot->_pLeft);
    printf("%d ", pRoot->_data);
    InOrder(pRoot->_pRight);
}

bool InsertBSTree(BSTNode** pRoot, BSDataType data)
{
    assert(pRoot);
    if (*pRoot == NULL)
    {
        (*pRoot) = BuyBSTNode(data);
        return true;
    }
    else
    {
        BSTNode* pCur = (*pRoot);
        BSTNode* pParent = NULL;
        //�ҵ��������λ��
        while (pCur)
        {
            pParent = pCur;
            if (pCur->_data == data)//�����ǰ���=Ҫ����Ľ�㣬���˳�����Ϊ���Ԫ���Ѿ�����
            {
                return false;
            }
            else if (pCur->_data > data)//�����ǰ�����>Ҫ�����������ǰ����������ȥ�Ҳ���λ��
            {
                pCur = pCur->_pLeft;
            }
            else//�����ǰ�����<Ҫ�����������ǰ����������ȥ�Ҳ���λ��
            {
                pCur = pCur->_pRight;
            }
        }
        //�����½��
        if (data > pParent->_data)//��������Ԫ�ر���Ҫ����λ�õ�Ԫ�ش���Ҫ�����Ԫ��Ӧ����Ҫ����λ�ý����Һ���
        {
            pParent->_pRight = BuyBSTNode(data);
            return true;
        }
        if (data < pParent->_data)//��������Ԫ�ر���Ҫ����λ�õ�Ԫ��С����Ҫ�����Ԫ��Ӧ����Ҫ����λ�ý�������
        {
            pParent->_pLeft = BuyBSTNode(data);
            return true;
        }
    }
    return false;
}

bool DelectBSTree(BSTNode** pRoot, BSDataType data)
{
    assert(pRoot);
    BSTNode* pCur = NULL;
    BSTNode* pParent = NULL;
    if (NULL == *pRoot)
        return false;
    else
    {
        //�ҵ���ɾ�����

        pCur = *pRoot;
        while (pCur)
        {
            if (data > pCur->_data)
            {
                pParent = pCur;
                pCur = pCur->_pRight;
            }
            else if (data < pCur->_data)
            {
                pParent = pCur;
                pCur = pCur->_pLeft;
            }
            else
                break;
        }
        //ɾ�����

        //��ɾ�����Ҷ�ӽڵ����ֻ���Һ���
        if (NULL == pCur->_pLeft)
        {
            if (pCur == *pRoot)//����ɾ�����Ǹ����
                *pRoot = pCur->_pRight;
            else if (pCur == pParent->_pLeft)
                pParent->_pLeft = pCur->_pRight;
            else
                pParent->_pRight = pCur->_pRight;
        }
        //ֻ������
        else if (NULL == pCur->_pRight)
        {
            if (pCur == *pRoot)//����ɾ�����Ǹ����
                *pRoot = pCur->_pLeft;
            else if (pCur == pParent->_pLeft)
                pParent->_pLeft = pCur->_pLeft;
            else
                pParent->_pRight = pCur->_pLeft;
        }
        //���Һ��Ӷ�����
        else
        {
            //����������ɾ�����������������ߵ�������С��/���ɾ����������������ұߵ�������󣩣�����ɾ�����������/���ұߵ���������ɾ�������/���ұߵ���
            BSTNode* Inorder = pCur->_pRight;

            while (Inorder->_pLeft)//����ѭ��������Inorder������������
            {
                pParent = Inorder;
                Inorder = Inorder->_pLeft;
            }
            pCur->_data = Inorder->_data;//����
            if (Inorder == pParent->_pLeft)
                pParent->_pLeft = Inorder->_pRight;
            else if (Inorder == pParent->_pRight)
                pParent->_pRight = Inorder->_pRight;
            pCur = Inorder;
        }
    }
    free(pCur);
    pCur = NULL;
    return true;
}

BSTNode* FindBSTree(BSTNode* pRoot, BSDataType data)
{
    BSTNode* pCur = NULL;
    if (NULL == pRoot)
        return NULL;

    pCur = pRoot;
    while (pCur)
    {
        if (pCur->_data == data)
        {
            return pCur;
        }
        else if (pCur->_data > data)
        {
            pCur = pCur->_pLeft;
        }
        else
        {
            pCur = pCur->_pRight;
        }
    }
    return NULL;
}

void DestroyBSTree(BSTNode** pRoot)
{
    assert(pRoot);
    if (*pRoot)
    {
        DestroyBSTree(&(*pRoot)->_pLeft);
        DestroyBSTree(&(*pRoot)->_pRight);
        free(*pRoot);
        *pRoot = NULL;
    }
}

BSTNode* FindBSTreeNor(BSTNode* pRoot, BSDataType data)
{
    if (NULL == pRoot)
        return NULL;
    else if (data == pRoot->_data)
        return pRoot;
    else if (data < pRoot->_data)
        return FindBSTreeNor(pRoot->_pLeft, data);
    else
        return FindBSTreeNor(pRoot->_pRight, data);
}

bool InsertBSTreeNor(BSTNode** pRoot, BSDataType data)
{
    assert(pRoot);
    if (NULL == *pRoot)
        *pRoot = BuyBSTNode(data);
    else
    {
        if (data == (*pRoot)->_data)
        {
            return false;
        }
        else if (data < (*pRoot)->_data)
            return InsertBSTree(&(*pRoot)->_pLeft, data);
        else
            return InsertBSTree(&(*pRoot)->_pRight, data);

    }
    return true;
}

bool DelectBSTreeNor(BSTNode** pRoot, BSDataType data)
{
    assert(pRoot);

    if (NULL == *pRoot)
        return false;
    else
    {

        if (data > (*pRoot)->_data)
        {
            return DelectBSTreeNor(&(*pRoot)->_pRight, data);
        }
        else if (data < (*pRoot)->_data)
        {
            return DelectBSTreeNor(&(*pRoot)->_pLeft, data);
        }
        else //data == (*pRoot)->_data
        {
            //��ʱ�Ѿ��ҵ��˴�ɾ�����
            BSTNode* pDel = *pRoot;
            if (NULL == pDel->_pLeft)
            {
                *pRoot = pDel->_pRight;
                free(pDel);
                return true;
            }
            else if (NULL == (*pRoot)->_pRight)
            {
                *pRoot = pDel->_pLeft;
                free(pDel);
                return true;
            }
            else //���Һ��Ӷ�����
            {
                BSTNode* Inorder = pDel->_pRight;
                while (Inorder->_pLeft)
                    Inorder = Inorder->_pLeft;
                pDel->_data = Inorder->_data;
                return DelectBSTreeNor(&(*pRoot)->_pRight, pDel->_data);
            }
        }
    }
}