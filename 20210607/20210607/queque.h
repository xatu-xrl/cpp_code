#pragma once
#include"btree.h"

typedef Node* QDataType;
typedef struct QNode
{
	QDataType _data;
	struct QNode* _next;
}QNode;

typedef struct Queue
{
	//头尾指针
	struct QNode* _head;
	struct QNode* _tail;
	int _size;
}Queue;

void initQueue(Queue* q);

struct QNode* creatNode(QDataType val);

//尾插
void queuePush(Queue* q, QDataType val);

//头删
void queuePop(Queue* q);

QDataType queueFront(Queue* q);
QDataType queueBack(Queue* q);
//要获取链表元素个数 要遍历
int queueSiez(Queue* q);

//判断队列是否为空
int quequeEmpty(Queue* q);