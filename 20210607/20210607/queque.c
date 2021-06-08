#include<stdio.h>
#include<stdlib.h>
#include"queque.h"


void initQueue(Queue* q)
{
	if (q == NULL)
		return;
	q->_head = q->_tail = NULL;
	q->_size = 0;
}

struct QNode* creatNode(QDataType val)
{
	struct QNode* node = (struct QNode*)malloc(sizeof(struct QNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

//尾插
void queuePush(Queue* q, QDataType val)
{
	struct QNode* node = creatNode(val);
	//假如是第一个节点
	if (q->_head == NULL)
		q->_head = q->_tail = node;
	else
	{
		q->_tail->_next = node;
		q->_head = node;
	}
	++q->_size;
}

//头删
void queuePop(Queue* q)
{
	if (q == NULL || q->_head == NULL)
		return;
	struct QNode* next = q->_head->_next;
	free(q->_head);
	q->_head = next;
	//假如只有一个数据
	if (q->_head == NULL)
		q->_tail = NULL;
	--q->_size;
}

QDataType queueFront(Queue* q)
{
	return q->_head->_data;
}

QDataType queueBack(Queue* q)
{
	return q->_tail->_data;
}

//要获取链表元素个数 要遍历
int queueSiez(Queue* q)
{
	return q->_size;
}

//判断队列是否为空
int quequeEmpty(Queue* q)
{
	return q->_head == NULL;
}

//void test()
//{
//	struct Queue q;
//	initQueue(&q);
//	quequePush(&q, 1);
//	quequePush(&q, 2);
//	quequePush(&q, 3);
//	quequePush(&q, 4);
//
//	while (!quequeEmpty(&q))
//	{
//		printf("%d ", queueFront(&q));
//		queque(&q);
//	}
//	printf("\n");
//}