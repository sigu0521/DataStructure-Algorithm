#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

/*
*ʵ��˫����������ɾ�����Լ�ʵ�����ݵ�������ң����룬ɾ��
*author: sigu
*time  : 2021.05.16
*/

/*�������*/
typedef struct double_link_node *d_node;
struct double_link_node
{
	d_node prev;    //ָ��ǰ�����
	d_node next;	//ָ���̽��
	void* p;		//���ֵ�Ĵ��(�����������ֵ�Ĵ��)
};
/*��ʼ��ͷ��㣬ͷ��㲻����κ�ֵ*/
static d_node phead = NULL;

/*˫�����������,��ʼ��Ϊ0*/
static int count = 0;

/*�½���㣬�ɹ����ؽ�㣬ʧ�ܷ���NULL*/
d_node Create_node(void* pval)
{
	d_node pnode = NULL;
	pnode = (struct double_link_node*)malloc(sizeof(struct double_link_node));
	if (pnode == NULL)
	{
		printf("Create dlink node error!");
		return NULL;
	}
	//��ʼ������ǰ���ͺ�̶�ָ���Լ�
	pnode->prev = pnode->next = pnode;
	//��ʼ������ֵΪ����Ĳ���
	pnode->p = pval;

	return pnode;
}

/*�½�˫�������ɹ�����0��ʧ�ܷ���-1*/
int Create_dlink()
{
	d_node phead = Create_node(NULL);
	if (phead == NULL)
		return -1;

	count = 0;//��һ��������Ϊ0
	return phead;//��ŵ�NULL������ı䣩
}
/*��������Ƿ�Ϊ�գ��ǣ�����true���񣬷���false*/
bool dlink_is_Empty()
{
	return count == 0;//countΪ0��Ҳ����˵��ʱ˫������ֻ��ͷ��㣬ͷ����ŵ�NULL
}

/*����˫������ĳ���*/
int dlink_Size()
{
	return count;//���㿪ʼ������ÿ�μ�һ����㣬count�ͼ�һ
}

/*��ȡ�����Indexλ�õ�Ԫ�أ��ɹ������ؽ�㣬ʧ�ܣ�����NULL*/
d_node dlink_get(int Index)
{	//��Index��ֵС��0�ʹ�������ĳ��ȵ�ʱ��һ��������
	if (Index<0 || Index>=count)
	{
		printf("Index is out of bound!\n");
		return NULL;
	}
	/*����˫����������ʣ����Է�������ң�������ң��������*/
	/*����ǰ�벿�ֵ�ʱ���������*/
	if (Index <= (count / 2))//������0��1/2��λ��
	{
		d_node pnode = phead->next;
		int i = 0;
		/*���ǵĽڵ��Ǵ��㿪ʼ�����ģ�Ҳ���ǵ�һ����㣬count=0��Ҳ����˵��Indexλ����Index-1��*/
		for (i = 0; i < Index; i++)//
		{
			pnode = pnode->next;
		}
		return pnode;
	}
	/*���ں�һ�벿�ֵ�ʱ�򣬷������*/
	int len = count - Index;
	d_node rnode = phead->prev;//�ʼ���ҵ�λ�ñ�����һ�����
	while (len != 0)//��len==0��˵���ҵ�Index���
	{
		rnode = rnode->prev;
		len--;
	}
	return rnode;
}

/*��ȡ��һ�����*/
d_node dlink_get_first()
{
	return 	dlink_get(0);
}

/*��ȡ���һ����㣬�ɹ������ظýڵ㣬ʧ�ܷ���NULL*/
d_node dlink_get_last()
{
	return dlink_get(count - 1);
}

/*��value����Indexλ�ã��ɹ�����1��ʧ�ܷ���0*/
