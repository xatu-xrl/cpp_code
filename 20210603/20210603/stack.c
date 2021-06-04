#include<stdio.h>
#include<stdlib.h>
//1
//�ö���ʵ��ջ
//����ջ һ��ר��������� һ��ר����������

typedef int STDataType;

//˳��ṹ��ʵ�֣�ʵ��һ���򵥵�˳��� �ṩ
typedef struct stack
{
	STDataType* _data;//ָ��̬���ٵ�����
	int _size;//��Ч���ݸ���
	int _capacity;//�����ռ��С
}stack;


//��ʼ��
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

//β��
void stackPush(stack* st, STDataType val)
{
	if (st == NULL)
		return;
	checkCapacity(st);
	st->_data[st->_size++] = val;
}

//βɾ
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
		return 1;//��ʾ�ǿ� 0�Ƿǿ�
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
	//����ջ��Ա
	//���ջ
	stack pushST;
	//����ջ
	stack popST;
} MyQueue;

//��ʼ��
MyQueue* myQueueCreate()
{
	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
	ininStack(&pq->pushST);
	ininStack(&pq->popST);
	return pq;
}


//���ջ push��һ������
void myQueuePush(MyQueue* obj, int x)
{
	stackPush(&obj->pushST, x);
}

//����ջ
int myQueuePop(MyQueue* obj) 
{
	//�жϳ���ջ�Ƿ�Ϊ��
	int front = 0;
	if (!stackEmpty(&obj->popST))
	{
		front = stackTop(&obj->popST);
		stackPop(&obj->popST);
	}
	else
	{
		//���ջ��Ԫ�ش������ջ
		while (!stackEmpty(&obj->pushST))
		{
			stackPush(&obj->popST, stackTop(&obj->pushST));
			stackPop(&obj->pushST);
		}
		front = stackToop(&obj->popST);
		stackPop(&obj->popST);
	}
}

//��ȡ��ͷԪ��
int myQueuePeek(MyQueue* obj)
{
	//�жϳ���ջ�Ƿ�Ϊ��
	int front = 0;
	if (stackEmpty(&obj->popST))
	
		//���ջ��Ԫ�ش������ջ
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

//����
void myQueueFree(MyQueue* obj)
{
	stackDestory(&obj->pushST);
	stackDestory(&obj->popST);
	free(obj);
}


//2
//���ѭ�����У��߼����� ��Ӷ�β�ƶ� ���Ӷ�ͷ�ƶ� �ռ��С�̶���
typedef struct
{
	int _front;//��ͷԪ�ص�λ��
	int _rear;//��βԪ�ص���һ��λ�� ���Ƕ�β������

	int _k;//���д�С
	int* _data;//��ſռ���׵�ַ
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) 
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->_data = (int*)malloc(sizeof(int*) * (k + 1));//�࿪�������ж��ǲ��ǿ��Լ������
	cq->_k = k;
	cq->_front = cq->_rear = 0;//0~k���� �߼�������Ӱ��
}

//��β���
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	//��Ҫ�ж���û����
	if (myCircularQueueIsFull(obj))
		return false;
	obj->_data[obj->_rear] = value;
	//ѭ���ṹ ��Ҫ�ж϶�β��û��Խ��
	if (obj->_rear > k)
		obj->_rear = 0;
	return true;
}

//��ͷ����
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return false;

	obj->_front++;
	//�ж�Խ��
	if (obj->_front > obj->_k)
		obj->_front = 0;
	return true;
}

//��ȡ��ͷԪ��
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
		return obj->_data[obj->_rear - 1];//�����0 ��Ҫע����������λ��
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