#include<stdio.h>
#include<stdlib.h>
//前序遍历

//递归
//int getSize(struct TreeNode* root)
//{
//	if (root)
//	{
//		return getSize(root->left) + getSize(root->right) + 1;
//	}
//	return 0;
//}
////递归的遍历
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

//非递归的前序遍历
//左边的节点：自上而下 右边相反
//1.访问每一个节点开始的最左路径，访问到每一个节点入栈
//2.最左路径访问完成之后，获取栈顶元素。继续访问以栈顶元素的右子树为根的结构，继续执行第一步
//3.栈为空时 && 右子树为空 此时结束遍历

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
	//当前遍历的节点不为空或者栈不为空
	while (root || !stackEmpty(&st))
	{
		while (root)
		{
			arr[idx++] = root->val;
			//当前节点入栈
			stackPush(&st, root);
			root = root->left;
		}

		//获取栈顶元素 访问右子树
		root = stackTop(&st);
		stackPop(&st);
		root = root->right;
	}
	*returnSize = idx;
	return arr;
}


//中序遍历
//1.以结点开始，走最左路径，此路径遇到到的每一个节点首先入栈，但是不能访问
//2.获取栈顶元素，访问栈顶元素
//3.获取栈顶元素的右子树。继续执行第一步
//4.结束：栈为空&&右子树为空

//非递归

int inorderTraversal(struct TreeNode* root, int* returnSize)
{
	int sz = getSize(root);
	int* arr = (int*)malloc(sizeof(int) * sz);
	stack st;
	ininStack(&st);
	int idx = 0;
	while (root || !stackEmpty(&st))
	{
		//遍历最左
		while (root)
		{
			stackPush(&st, root);
			root = root->left;
		}
		//获取栈顶元素并访问
		root = stackTop(&st);
		stackPop(&st);
		arr[idx++] = root->val;
		//访问栈顶元素的右子树
		root = root->right;
	}
	*returnSize = idx;
	return arr;
}

//后序遍历

//1.以结点开始，遍历最做路径，遇到每一个节点入栈
//2.获取栈顶元素，当前栈顶元素是否可以访问？ a.没有右子树可以访问 执行第一步
//  b.右子树访问完成可以访问 执行第一步
// c有右子树但是没有访问 不可以访问当前元素 首先访问右子树  执行第一步
//3.节点为空 && 栈为空

//如何确定当前右子树是否已经访问完成 可以看上一次访问的节点 用一个指针记录看有没有访问过右子树的根

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{

	int sz = getSize(root);
	int* arr = (int*)malloc(sizeof(int) * sz);
	stack st;
	ininStack(&st);
	int idx = 0;
	//上一次访问的节点
	struct TreeNode* prev = NULL;
	while (root || !stackEmpty(&st))
	{
		while (root)
		{
			stackPush(&st, root);
			root = root->left;
		}
		struct TreeNode* top = stackTop(&st);
		//判断栈顶元素是否可以访问
		//可以访问的情况是没有右子树或者右子树已经访问完成
		//右子树访问完成的情况就是 上一次访问的节点就是右子树的根节点
		if (top->right == NULL || top->right == prev)
		{
			arr[idx++] = root->val;
			stackPop(&st);
			//更新pre
			prev = top;
		}
		else 
			//访问右子树 此时栈顶元素是不可以出栈的
			root = top->right;
	}
	*returnSize = idx;
	return arr;
}

