#include<stdio.h>
#include<stdlib.h>
//����ڵ㣺���� + ָ��
typedef int LDataType;
typedef struct listNode
{
	LDataType _data;
	struct listNode* _next;
}listNode;

//����
typedef struct list
{
	//�����һ���ڵ�ĵ�ַ
	listNode* _head;
}list;

//�����ڵ�
listNode* creatListNode(LDataType val)
{
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

void listInit(list* lst)
{
	//��ʼ��Ϊ������
	if (lst == NULL)
		return;
	lst->_head = NULL;
}

//β��
void listPushBack(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	//��ʾ������һ���ڵ�
	if (lst->_head == NULL)
	{
		//�����һ���ڵ�
		lst->_head = creatListNode(val);
	}
	else
	{
		//�����ҵ����һ���ڵ�
		struct listNode* prev = NULL;
		struct listNode* tail = lst->_head;
		
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}

		tail->_next = creatListNode(val);
	}
}

//β��ɾ������Ҫ�ͷſռ䣩
void listPopBack(list* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	//���� �ӵ�һ����ʼȻ���ҵ����һ���ڵ�
	listNode* prev = NULL;
	listNode* tail = lst->_head;
	while (tail->_next != NULL)//ֻҪnext��Ϊ�� �Ͳ������һ���ڵ�
	{
		prev = tail;
		tail = tail->_data;
	}
	//�ͷ�
	free(tail);
	//����next
	if (lst->_head->_next == NULL)//ֻ��һ���ڵ�
		lst->_head == NULL;
	else
		prev->_next == NULL;
	prev->_next = NULL;
}

//ͷ��(�޸�ͷ����ָ����µĽڵ��ָ��)O��1��
void listPushFront(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	struct listNode* node = creatListNode(val);
	node->_next = lst->_head;
	lst->_head = node;//�ǲ��ǿ��б���һ���Ĳ���
}

//ͷ��ɾ��(��Ҫ�޸�ͷ��ָ��)O(1)
void listPopFront(list* lst)
{
	if (lst == NULL || lst->_head == NULL);
	  return;
	  listNode* next = lst->_head->_next;
	  free(lst->_head);
	  lst->_head = next;
}

//ĳ���ط�����
void listInsertAfter(listNode* node,LDataType val)
{
	if (node == NULL)
		return;
	listNode* newNode = creatListNode(val);
	listNode* next = node->_next;//�ǿ��Խ��н����ò�����
	node->_next = newNode;
	newNode->_next = next;
}

//ɾ��ĳ������ ����node ɾ��������һ���ڵ�
void listEraseAfter(listNode* node)
{
	if (node == NULL || node->_next == NULL)
		return;
	listNode* next = node->_next;
	listNode* nextnext = next->_next;

	free(next);
	node->_next = nextnext;
}

listNode* listFind(list*  lst, LDataType val)
{
	if (lst == NULL || lst->_head == NULL)
		return NULL;
	listNode* cur = lst->_head;
	while (cur)
	{
		if (cur->_data == val)
			return cur;

		cur = cur->_next;
	}
	return NULL;
}

//��������
void listDestroy(list* lst)//���ٽڵ㣨������һ����
{
	if (lst == NULL)
		return;
	listNode* cur = lst->_head;
	while (cur)
	{
		//������һ��λ��
		listNode* next = cur->_next;
		//�ͷ�
		free(cur);
		cur = next;
	}
	lst->_head = NULL;
}


//void test()
//{
//	list lst;
//	listInit(&lst);
//	listPushFront(&lst, 5);
//	listPushFront(&lst, 4);
//	listPushFront(&lst, 3);
//	listPushFront(&lst, 2);//1 2 3 4 5 6
//	listPushFront(&lst, 1);
//
//	listPopFront(&lst);
//	listPopFront(&lst);
//	listPopFront(&lst);
//}
//void test()
//{
//	list lst;
//	listInit(&lst);
//	listPushBack(&lst, 1);
//	listPushBack(&lst, 2);
//	listPushBack(&lst, 3);
//	listPushBack(&lst, 4);
//	listPushBack(&lst, 5);
//
//	listPopBack(&lst);
//	listPopBack(&lst);
//	listPopBack(&lst);
//}

int main()
{
	test();
	return 0;
}