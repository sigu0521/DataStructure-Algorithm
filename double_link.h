

#ifndef __DOUBLE_LINK_H__
#define __DOUBLE_LINK_H__

/*�½�һ��˫�������ɹ������ر�ͷ�����򷵻�NULL*/
extern void* Create_node();
/*����(����)˫�������ɹ�����1�����򷵻�0*/
extern int Destory_dlink();
/*�ж�˫�������Ƿ�Ϊ�գ��ǣ�����1�����򷵻�0*/
extern int dlink_is_Empty();

/*����˫������Ĵ�С*/
extern int dlink_Size();

/*��ȡ˫�������Indexλ�õ�Ԫ�أ��ɹ������ؽ�㣬���򷵻�NULL*/
extern void* dlink_get(int Index);
/*��ȡ˫�������1��Ԫ�أ��ɹ������ؽ�㣬���򷵻�NULL*/
extern void* dlink_get_first();
/*��ȡ˫���������һ��Ԫ�أ��ɹ������ؽ�㣬���򷵻�NULL*/
extern void* dlink_get_last();

/*��value���뵽Indexλ�ã��ɹ�������1��ʧ�ܷ���-1*/
extern int dlink_insert(int Index, void* pval);
/*��value���뵽��ͷλ�ã��ɹ�������1��ʧ�ܷ���-1*/
extern int dlink_insert_first(void* pval);
/*��value���뵽����β�����ɹ�������1��ʧ�ܷ���-1*/
extern int dlink_insert_last(void *pval);

/*ɾ��˫������Indexλ�õĽ�㣬�ɹ�����0��ʧ�ܷ���-1*/
extern int dlink_delete(int Index);
/*ɾ��˫�������һ����㣬�ɹ�����0��ʧ�ܷ���-1*/
extern int dlink_delete_first();
/*ɾ��˫���������һ����㣬�ɹ�����0��ʧ�ܷ���-1*/
extern int dlink_delete_last();


#endif  //__DOUBLE_LINK_H__