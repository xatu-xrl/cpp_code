#include<stdio.h>
#include<stdlib.h>
//ջ ֻҪ�߼������Ϳ���
//һ��˳���ʵ��

//typedef int STDataType;
//
////˳��ṹ��ʵ�֣�ʵ��һ���򵥵�˳��� �ṩ
//typedef struct stack
//{
//	STDataType* _data;//ָ��̬���ٵ�����
//	int _size;//��Ч���ݸ���
//	int _capacity;//�����ռ��С
//}stack;
//
//
////��ʼ��
//void ininStack(stack* st)
//{
//	if (st == NULL)
//		return;
//	st->_data = NULL;
//	st->_size = st->_capacity = 0;
//}
//
//void checkCapacity(stack* st)
//{
//	if (st->_size == st->_capacity)
//	{
//		int newCap = st->_capacity == 0 ? 1 : 2 * st->_capacity;
//		st->_data = (STDataType*)realloc(st->_data, sizeof(STDataType) * newCap);
//	}
//}
//
////β��
//void stackPush(stack* st, STDataType val)
//{
//	if (st == NULL)
//		return;
//	checkCapacity(st);
//	st->_data[st->_size++] = val;
//}
//
////βɾ
//void stackPop(stack* st)
//{
//	if (st == NULL || st->_size == 0)
//		return;
//	--st->_size;
//}
//
//int stackSize(stack* st)
//{
//	if (st == NULL)
//		return 0;
//	return st->_size;
//}
//
//int stackEmpty(stack* st)
//{
//	if (st == NULL)
//		return 1;//��ʾ�ǿ� 0�Ƿǿ�
//	else
//		return 0;
//}
//
//STDataType stackTop(stack* st)
//{
//	return st->_data[st->_size - 1];
//}
//
//void test()
//{
//	stack st;
//	ininStack(&st);
//
//	stackPush(&st, 1);
//	stackPush(&st, 2);
//	stackPush(&st, 3);
//	stackPush(&st, 4);
//	
//	while (!stackEmpty(&st))
//	{
//		printf("%d ", stackTop(&st));
//		stackPop(&st);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//���У��൱���Ŷӣ�
//һ���÷������Ľṹʵ��
//����βָ��ĵ�����

typedef int QDataType;
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
void queuePush(Queue* q,QDataType val)
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
	--q-> _size;
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

void test()
{
	struct Queue q;
	initQueue(&q);
	quequePush(&q, 1);
	quequePush(&q, 2);
	quequePush(&q, 3);
	quequePush(&q, 4);
  
	while (!quequeEmpty(&q))
	{
		printf("%d ", queueFront(&q));
		queque(&q);
	}
	printf("\n");
}