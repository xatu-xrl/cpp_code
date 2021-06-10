#include<stdio.h>
#include<stdlib.h>
//ǰ�����

//�ݹ�
//int getSize(struct TreeNode* root)
//{
//	if (root)
//	{
//		return getSize(root->left) + getSize(root->right) + 1;
//	}
//	return 0;
//}
////�ݹ�ı���
//void preorder(struct TreeNode* root, int* arr, int* idx)
//{
//	if (root)
//	{
//		arr[*idx] = root->val;
//		(*idx)++;
//		preorder(root->left, arr, idx);
//		preorder(root->right, arr, idx);
//	}
//}
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize)
//{
//	int sz = getSize(root);
//	int* arr = (int*)malloc(sizeof(int) * sz);
//	int idx = 0;
//	preorder(root, arr, &idx);
//	*returnSize = idx;
//	return arr;
//}

//�ǵݹ��ǰ�����
//��ߵĽڵ㣺���϶��� �ұ��෴
//1.����ÿһ���ڵ㿪ʼ������·�������ʵ�ÿһ���ڵ���ջ
//2.����·���������֮�󣬻�ȡջ��Ԫ�ء�����������ջ��Ԫ�ص�������Ϊ���Ľṹ������ִ�е�һ��
//3.ջΪ��ʱ && ������Ϊ�� ��ʱ��������

typedef struct TreeNode* STDataType;


typedef struct stack
{
	STDataType* _data;
	int _size;
	int _capacity;
}stack;

int getSize(struct TreeNode* root)
{
	if (root)
	{
		return getSize(root->left) + getSize(root->right) + 1;
	}
	return 0;
}

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
		return 1;
	else
		return 0;
}

STDataType stackTop(stack* st)
{
	return st->_data[st->_size - 1];
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	int sz = getSize(root);
	int* arr = malloc(sizeof(int) * sz);
	stack st;
	ininStack(&st);
	int idx = 0;
	//��ǰ�����Ľڵ㲻Ϊ�ջ���ջ��Ϊ��
	while (root || !stackEmpty(&st))
	{
		while (root)
		{
			arr[idx++] = root->val;
			//��ǰ�ڵ���ջ
			stackPush(&st, root);
			root = root->left;
		}

		//��ȡջ��Ԫ�� ����������
		root = stackTop(&st);
		stackPop(&st);
		root = root->right;
	}
	*returnSize = idx;
	return arr;
}


//�������
//1.�Խ�㿪ʼ��������·������·����������ÿһ���ڵ�������ջ�����ǲ��ܷ���
//2.��ȡջ��Ԫ�أ�����ջ��Ԫ��
//3.��ȡջ��Ԫ�ص�������������ִ�е�һ��
//4.������ջΪ��&&������Ϊ��

//�ǵݹ�

int inorderTraversal(struct TreeNode* root, int* returnSize)
{
	int sz = getSize(root);
	int* arr = (int*)malloc(sizeof(int) * sz);
	stack st;
	ininStack(&st);
	int idx = 0;
	while (root || !stackEmpty(&st))
	{
		//��������
		while (root)
		{
			stackPush(&st, root);
			root = root->left;
		}
		//��ȡջ��Ԫ�ز�����
		root = stackTop(&st);
		stackPop(&st);
		arr[idx++] = root->val;
		//����ջ��Ԫ�ص�������
		root = root->right;
	}
	*returnSize = idx;
	return arr;
}

//�������

//1.�Խ�㿪ʼ����������·��������ÿһ���ڵ���ջ
//2.��ȡջ��Ԫ�أ���ǰջ��Ԫ���Ƿ���Է��ʣ� a.û�����������Է��� ִ�е�һ��
//  b.������������ɿ��Է��� ִ�е�һ��
// c������������û�з��� �����Է��ʵ�ǰԪ�� ���ȷ���������  ִ�е�һ��
//3.�ڵ�Ϊ�� && ջΪ��

//���ȷ����ǰ�������Ƿ��Ѿ�������� ���Կ���һ�η��ʵĽڵ� ��һ��ָ���¼����û�з��ʹ��������ĸ�

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{

	int sz = getSize(root);
	int* arr = (int*)malloc(sizeof(int) * sz);
	stack st;
	ininStack(&st);
	int idx = 0;
	//��һ�η��ʵĽڵ�
	struct TreeNode* prev = NULL;
	while (root || !stackEmpty(&st))
	{
		while (root)
		{
			stackPush(&st, root);
			root = root->left;
		}
		struct TreeNode* top = stackTop(&st);
		//�ж�ջ��Ԫ���Ƿ���Է���
		//���Է��ʵ������û�������������������Ѿ��������
		//������������ɵ�������� ��һ�η��ʵĽڵ�����������ĸ��ڵ�
		if (top->right == NULL || top->right == prev)
		{
			arr[idx++] = root->val;
			stackPop(&st);
			//����pre
			prev = top;
		}
		else 
			//���������� ��ʱջ��Ԫ���ǲ����Գ�ջ��
			root = top->right;
	}
	*returnSize = idx;
	return arr;
}

