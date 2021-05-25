#include<stdio.h>
#include<stdlib.h>
//定义节点：数据 + 指针
typedef int LDataType;
typedef struct listNode
{
	LDataType _data;
	struct listNode* _next;
}listNode;

//链表
typedef struct list
{
	//保存第一个节点的地址
	listNode* _head;
}list;

//创建节点
listNode* creatListNode(LDataType val)
{
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

void listInit(list* lst)
{
	//初始化为空链表
	if (lst == NULL)
		return;
	lst->_head = NULL;
}

//尾插
void listPushBack(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	//表示创建第一个节点
	if (lst->_head == NULL)
	{
		//插入第一个节点
		lst->_head = creatListNode(val);
	}
	else
	{
		//遍历找到最后一个节点
		struct listNode* prev = NULL;
		struct listNode* tail = lst->_head;
		
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}

		tail->_next = creatListNode(val);
	}
}

//尾部删除（需要释放空间）
void listPopBack(list* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	//遍历 从第一个开始然后找到最后一个节点
	listNode* prev = NULL;
	listNode* tail = lst->_head;
	while (tail->_next != NULL)//只要next不为空 就不是最后一个节点
	{
		prev = tail;
		tail = tail->_data;
	}
	//释放
	free(tail);
	//更新next
	if (lst->_head->_next == NULL)//只有一个节点
		lst->_head == NULL;
	else
		prev->_next == NULL;
	prev->_next = NULL;
}

//头插(修改头部的指向和新的节点的指向)O（1）
void listPushFront(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	struct listNode* node = creatListNode(val);
	node->_next = lst->_head;
	lst->_head = node;//是不是空列表都是一样的操作
}

//头部删除(需要修改头的指向)O(1)
void listPopFront(list* lst)
{
	if (lst == NULL || lst->_head == NULL);
	  return;
	  listNode* next = lst->_head->_next;
	  free(lst->_head);
	  lst->_head = next;
}

//某个地方插入
void listInsertAfter(listNode* node,LDataType val)
{
	if (node == NULL)
		return;
	listNode* newNode = creatListNode(val);
	listNode* next = node->_next;//是可以进行解引用操作的
	node->_next = newNode;
	newNode->_next = next;
}

//删除某个数据 给个node 删除的是下一个节点
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

//链表销毁
void listDestroy(list* lst)//销毁节点（保存下一个）
{
	if (lst == NULL)
		return;
	listNode* cur = lst->_head;
	while (cur)
	{
		//保存下一个位置
		listNode* next = cur->_next;
		//释放
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