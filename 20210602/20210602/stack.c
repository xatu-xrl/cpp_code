#include<stdio.h>
#include<stdlib.h>
//1
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
typedef int STDataType;

//顺序结构的实现：实现一个简单的顺序表 提供
typedef struct stack
{
	STDataType* _data;//指向动态开辟的数组
	int _size;//有效数据个数
	int _capacity;//容量空间大小
}stack;


//初始化
void ininStack(stack* st)
{
	if (st == NULL)
		return;
	st->_data = NULL;
	st->_size = st->_capacity = 0;
}

void checkCapacity(stack* st)
{
	if (st->_size == st->_capacity)
	{
		int newCap = st->_capacity == 0 ? 1 : 2 * st->_capacity;
		st->_data = (STDataType*)realloc(st->_data, sizeof(STDataType) * newCap);
	}
}

//尾插
void stackPush(stack* st, STDataType val)
{
	if (st == NULL)
		return;
	checkCapacity(st);
	st->_data[st->_size++] = val;
}

//尾删
void stackPop(stack* st)
{
	if (st == NULL || st->_size == 0)
		return;
	--st->_size;
}

int stackSize(stack* st)
{
	if (st == NULL)
		return 0;
	return st->_size;
}

int stackEmpty(stack* st)
{
	if (st == NULL)
		return 1;//表示是空 0是非空
	else
		return 0;
}

STDataType stackTop(stack* st)
{
	return st->_data[st->_size - 1];
}

bool isValid(char* s)
{
	//括号映射
	char map[3][2] = { {'(',')'},{'[',']'},{'{','}'} };
	struct stack st;
	ininStack(&st);
	while (*s)
	{
		int flag = 0;
		//左括号 入栈 镶嵌的全部 有顺序的一次入一个
		//有可能是任意一个左括号
		for (int i = 0; i < 3; ++i)
		{
			if (*s == map[i][0])
			{
				stackPush(&st, *s);
				//判断下一个
				++s;
				flag = 1;
				break;
			}
		}
		//右括号 匹配
		//判断前面是否有入栈操作 
		if (flag == 0)
		{
			//没有左括号
			if (stackEmpty(&st))
				return false;
			//取栈顶元素 某一个左括号
			char topChar = stackTop(&st);
			stackPop(&st);
			//找到当前*s对应的左括号 这个时候*s的左括号入栈了 现在是右括号
			for (int i = 0; i < 3; ++i)
			{
				if (map[i][1] == *s)
				{
					if (topChar == map[i][0])
					{
						//判断下一个
						++s;
						break;
					}
					else
						return false;
				}
			}
		}
	}
	//判断栈是不是空的
	return stackEmpty(&st);
}

//2
//用队列实现栈
//入栈  入队
//出栈 出队在入队前  n-1先出再入 最后一个直接出

//
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
int queueSize(Queue* q)
{
	return q->_size;
}

//判断队列是否为空
int quequeEmpty(Queue* q)
{
	return q->_head == NULL;
}

void queueDestroy(Queue* q)
{
	QNode* cur = q->_head;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_head = q->_tail = NULL;
}


typedef struct
{
	//队列成员
	struct Queue q;
} MyStack;

MyStack* myStackCreate()
{
	//动态创建
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	initQueue(&pst->q);//不是本身的成员 需要取地址
	return pst;
}

void myStackPush(MyStack* obj, int x)
{
	queuePush(&obj->q, x);
}


int myStackPop(MyStack* obj) 
{
	int n = queueSize(&obj->q);
	while (n > 1)
	{
		//出队和入队
		int front = queueFront(&obj->q);
		queuePop(&obj->q);
		queuePush(&obj->q, front);
		--n;
	}
	int top = queueFront(&obj->q);
	queuePop(&obj->q);
	return top;
}


int myStackTop(MyStack* obj) 
{
	return queueBack(&obj->q);
}


bool myStackEmpty(MyStack* obj) 
{
	return quequeEmpty(&obj->q);
}

void myStackFree(MyStack* obj)
{
	queueDestroy(&obj->q);
	free(obj);
}
