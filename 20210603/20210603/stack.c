#include<stdio.h>
#include<stdlib.h>
//1
//用队列实现栈
//两个栈 一个专门用来入队 一个专门用来出队

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

void stackDestory(stack* st)
{
	if (st)
	{
		if (st->_data)
		{
			free(st->_data);
			st->_data = NULL;
			st->_size = st->_capacity = 0;
		}
	}
}



typedef struct
{
	//定义栈成员
	//入队栈
	stack pushST;
	//出队栈
	stack popST;
} MyQueue;

//初始化
MyQueue* myQueueCreate()
{
	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
	ininStack(&pq->pushST);
	ininStack(&pq->popST);
	return pq;
}


//入队栈 push的一个操作
void myQueuePush(MyQueue* obj, int x)
{
	stackPush(&obj->pushST, x);
}

//出队栈
int myQueuePop(MyQueue* obj) 
{
	//判断出队栈是否为空
	int front = 0;
	if (!stackEmpty(&obj->popST))
	{
		front = stackTop(&obj->popST);
		stackPop(&obj->popST);
	}
	else
	{
		//入队栈的元素存入出队栈
		while (!stackEmpty(&obj->pushST))
		{
			stackPush(&obj->popST, stackTop(&obj->pushST));
			stackPop(&obj->pushST);
		}
		front = stackToop(&obj->popST);
		stackPop(&obj->popST);
	}
}

//获取队头元素
int myQueuePeek(MyQueue* obj)
{
	//判断出队栈是否为空
	int front = 0;
	if (stackEmpty(&obj->popST))
	
		//入队栈的元素存入出队栈
		while (!stackEmpty(&obj->pushST))
		{
			stackPush(&obj->popST, stackTop(&obj->pushST));
			stackPop(&obj->pushST);
		}
	
	return stackTop(&obj->popST);
}


bool myQueueEmpty(MyQueue* obj)
{
	return stackEmpty(&obj->pushST) && stackEmpty(&obj->popST);
}

//销毁
void myQueueFree(MyQueue* obj)
{
	stackDestory(&obj->pushST);
	stackDestory(&obj->popST);
	free(obj);
}


//2
//设计循环队列（逻辑连续 入队队尾移动 出队对头移动 空间大小固定）
typedef struct
{
	int _front;//队头元素的位置
	int _rear;//队尾元素的下一个位置 不是队尾！！！

	int _k;//队列大小
	int* _data;//存放空间的首地址
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) 
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->_data = (int*)malloc(sizeof(int*) * (k + 1));//多开的用来判断是不是可以继续入队
	cq->_k = k;
	cq->_front = cq->_rear = 0;//0~k都行 逻辑连续不影响
}

//队尾入队
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	//需要判断有没有满
	if (myCircularQueueIsFull(obj))
		return false;
	obj->_data[obj->_rear] = value;
	//循环结构 需要判断队尾有没有越界
	if (obj->_rear > k)
		obj->_rear = 0;
	return true;
}

//队头出队
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return false;

	obj->_front++;
	//判断越界
	if (obj->_front > obj->_k)
		obj->_front = 0;
	return true;
}

//获取对头元素
int myCircularQueueFront(MyCircularQueue* obj) 
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->_data[obj->_front];
}


int myCircularQueueRear(MyCircularQueue* obj) 
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	if (obj->_rear != 0)
		return obj->_data[obj->_rear - 1];//如果在0 需要注意是在最后的位置
	else
		return obj->_data[obj->_k];
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj) 
{
	return obj->_front == obj->_rear;
}


bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return(obj->_rear + 1) % (obj->_k + 1) == obj->_front;
}


void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->_data);
	free(obj);
}