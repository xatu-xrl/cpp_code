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
	//ͷβָ��
	struct QNode* _head;
	struct QNode* _tail;
	int _size;
}Queue;

void initQueue(Queue* q);

struct QNode* creatNode(QDataType val);

//β��
void queuePush(Queue* q, QDataType val);

//ͷɾ
void queuePop(Queue* q);

QDataType queueFront(Queue* q);
QDataType queueBack(Queue* q);
//Ҫ��ȡ����Ԫ�ظ��� Ҫ����
int queueSiez(Queue* q);

//�ж϶����Ƿ�Ϊ��
int quequeEmpty(Queue* q);