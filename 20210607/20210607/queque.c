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

//β��
void queuePush(Queue* q, QDataType val)
{
	struct QNode* node = creatNode(val);
	//�����ǵ�һ���ڵ�
	if (q->_head == NULL)
		q->_head = q->_tail = node;
	else
	{
		q->_tail->_next = node;
		q->_head = node;
	}
	++q->_size;
}

//ͷɾ
void queuePop(Queue* q)
{
	if (q == NULL || q->_head == NULL)
		return;
	struct QNode* next = q->_head->_next;
	free(q->_head);
	q->_head = next;
	//����ֻ��һ������
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

//Ҫ��ȡ����Ԫ�ظ��� Ҫ����
int queueSiez(Queue* q)
{
	return q->_size;
}

//�ж϶����Ƿ�Ϊ��
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