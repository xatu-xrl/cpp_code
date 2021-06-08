#include<stdio.h>
#include<stdlib.h>
#include"queque.h"
#include"btree.h"

typedef struct BTree
{
	//根节点
	Node* _root;
}BTree;

//创建一个二叉树 返回根节点指针
//数组的顺序为前序遍历  ABD##E#H##CF##G##
Node* creatBinyTree(DataType arr[], int* idx)
{
	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;
	}

	//当前树的根节点
	Node* root = (Node*)malloc(sizeof(Node));
	root->_data = arr[*idx];
	(*idx)++;

	root->_left = creatBinaryTree(arr, idx);
	root->_right = creatBinaryTree(arr, idx);//递归
	return root;

}

//前序遍历
//根 左 右
void preOrder(Node* root)
{
	if (root)
	{
		printf("%c ", root->_data);

		preOrder(root->_left);
		preOrder(root->_right);
	}
}

//中序遍历
//左 根 右
void inOrder(Node* root)
{
	if (root)
	{
		inOrder(root->_left);
		printf("%c ", root->_data);
		inOrder(root->_right);
	}
}

//后序遍历
//左 右 根
void postOrder(Node* root)
{
	if (root)
	{
		postOrder(root->_left);
		postOrder(root->_right);
		printf("%c ", root->_data);
	}
}


//二叉树节点个数
int bTreeSize(Node* root)
{
	if (root = NULL)
		return 0;
	return bTreeSize(root->_left) + bTreeSize(root->_right) + 1;
}

//树的高度(左右子树的高度 +1
int bTreeHeight(Node* root)
{
	if (root == NULL)
		return 0;
	int left = bTreeHeoght(root->_left);
	int right = bTreeHeight(root->_right);
	return left > right ? left + 1 : right + 1;
	//自底向上
}

//叶子节点个数
int bTreeLeafSize(Node* root)
{
	//左右子树的叶子的和
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return bTreeLeafSize(root->_left) + bTreeLeafSize(root->_right);
}

//第k层节点的个数
//看k减一层
int bTreeKSize(Node* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return bTreeKSize(root->_left, k - 1) + bTreeKSize(root->_right, k - 1);
}

//查找某个节点
Node* bTreeFind(Node* root, char ch)
{
	if (root)
	{
		Node* node;
		if (root->_data == ch)
			return root;
		node = bTreeFind(root->_left, ch);
		if (node)
			return node;
		else
			bTreeFind(root->_right,  ch);
	}
	else
	    return NULL;
}

//销毁二叉树 指针可以全部置空 
void bTreeDestory(Node** root)
{
	if (*root)
	{
		bTreeDesTory((&(*root)->_left));//二级指针解引用还是一级指针 访问
		bTreeDesTory((&(*root)->_right));
		free(*root);
		*root = NULL;
	}
}

//层序遍历
void bTreeLevelOrder(Node* root)
{
	//借助队列保存节点
	Queue q;
	initQueue(&q);
	//根节点存入队列
	if (root)
		queuqePush(&q, root);
	//遍历队列每一个节点
	while (!quequeEmpty(&q))
	{
		//获取队头元素
		Node* front = queuqeFront(&q);
		//出队
		quequePop(&q);

		//左右顺序不能变
		printf("%d ", front->_data);
		//保存队友元素的左右孩子节点
		if (front->_left)
			queuePush(&q, front->_left);
		if (front->_right)
			queuePush(&q, front->_right);
	}
	printf("\n");
}


//判断一个树是不是一个完全二叉树
//通过层序遍历 看剩下的有没有非空节点
int isCompleteBtree(Node* root)
{
	Queue q;
	initQueue(&q);
	if (root)
		queuePush(&q, root);
	while (!quequeEmpty(&q))
	{
		//获取队头元素
		Node* front = queueFront(&q);
		queuePop(&q);
		//左右孩子入队
		if (front)
		{
			queuePush(&q, front->_left);
			queuePush(&q, front->_right);
		}
		else
			break;
	}
	//查看剩余元素中，是否有非空节点
	while (!quequeEmpty(&q))
	{
		Node* front = queueFront(&q);
		if (front)
			//若果剩余元素中有非空节点，说明节点不连续
			return 0;
	}
	return 1;
}

void test()
{
	char arr[] = "ABD##E#H##CF##G##";
	int idx = 0;
	Node* root = creatBinaryTree(arr, &idx);
}


int main()
{
	test();
	return 0;
}