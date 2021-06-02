#include<stdio.h>
#include<stdlib.h>
//栈 只要逻辑连续就可以
//一般顺序表实现

//typedef int STDataType;
//
////顺序结构的实现：实现一个简单的顺序表 提供
//typedef struct stack
//{
//	STDataType* _data;//指向动态开辟的数组
//	int _size;//有效数据个数
//	int _capacity;//容量空间大小
//}stack;
//
//
////初始化
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
////尾插
//void stackPush(stack* st, STDataType val)
//{
//	if (st == NULL)
//		return;
//	checkCapacity(st);
//	st->_data[st->_size++] = val;
//}
//
////尾删
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
//		return 1;//表示是空 0是非空
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

//队列（相当于排队）
//一般用非连续的结构实现
//带有尾指针的单链表

typedef int QDataType;
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
void queuePush(Queue* q,QDataType val)
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