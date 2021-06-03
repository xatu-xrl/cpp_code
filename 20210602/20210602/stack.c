#include<stdio.h>
#include<stdlib.h>
//1
//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
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

bool isValid(char* s)
{
	//����ӳ��
	char map[3][2] = { {'(',')'},{'[',']'},{'{','}'} };
	struct stack st;
	ininStack(&st);
	while (*s)
	{
		int flag = 0;
		//������ ��ջ ��Ƕ��ȫ�� ��˳���һ����һ��
		//�п���������һ��������
		for (int i = 0; i < 3; ++i)
		{
			if (*s == map[i][0])
			{
				stackPush(&st, *s);
				//�ж���һ��
				++s;
				flag = 1;
				break;
			}
		}
		//������ ƥ��
		//�ж�ǰ���Ƿ�����ջ���� 
		if (flag == 0)
		{
			//û��������
			if (stackEmpty(&st))
				return false;
			//ȡջ��Ԫ�� ĳһ��������
			char topChar = stackTop(&st);
			stackPop(&st);
			//�ҵ���ǰ*s��Ӧ�������� ���ʱ��*s����������ջ�� ������������
			for (int i = 0; i < 3; ++i)
			{
				if (map[i][1] == *s)
				{
					if (topChar == map[i][0])
					{
						//�ж���һ��
						++s;
						break;
					}
					else
						return false;
				}
			}
		}
	}
	//�ж�ջ�ǲ��ǿյ�
	return stackEmpty(&st);
}

//2
//�ö���ʵ��ջ
//��ջ  ���
//��ջ ���������ǰ  n-1�ȳ����� ���һ��ֱ�ӳ�

//
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
int queueSize(Queue* q)
{
	return q->_size;
}

//�ж϶����Ƿ�Ϊ��
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
	//���г�Ա
	struct Queue q;
} MyStack;

MyStack* myStackCreate()
{
	//��̬����
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	initQueue(&pst->q);//���Ǳ���ĳ�Ա ��Ҫȡ��ַ
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
		//���Ӻ����
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
