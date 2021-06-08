#include<stdio.h>
#include<stdlib.h>
#include"queque.h"
#include"btree.h"

typedef struct BTree
{
	//���ڵ�
	Node* _root;
}BTree;

//����һ�������� ���ظ��ڵ�ָ��
//�����˳��Ϊǰ�����  ABD##E#H##CF##G##
Node* creatBinyTree(DataType arr[], int* idx)
{
	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;
	}

	//��ǰ���ĸ��ڵ�
	Node* root = (Node*)malloc(sizeof(Node));
	root->_data = arr[*idx];
	(*idx)++;

	root->_left = creatBinaryTree(arr, idx);
	root->_right = creatBinaryTree(arr, idx);//�ݹ�
	return root;

}

//ǰ�����
//�� �� ��
void preOrder(Node* root)
{
	if (root)
	{
		printf("%c ", root->_data);

		preOrder(root->_left);
		preOrder(root->_right);
	}
}

//�������
//�� �� ��
void inOrder(Node* root)
{
	if (root)
	{
		inOrder(root->_left);
		printf("%c ", root->_data);
		inOrder(root->_right);
	}
}

//�������
//�� �� ��
void postOrder(Node* root)
{
	if (root)
	{
		postOrder(root->_left);
		postOrder(root->_right);
		printf("%c ", root->_data);
	}
}


//�������ڵ����
int bTreeSize(Node* root)
{
	if (root = NULL)
		return 0;
	return bTreeSize(root->_left) + bTreeSize(root->_right) + 1;
}

//���ĸ߶�(���������ĸ߶� +1
int bTreeHeight(Node* root)
{
	if (root == NULL)
		return 0;
	int left = bTreeHeoght(root->_left);
	int right = bTreeHeight(root->_right);
	return left > right ? left + 1 : right + 1;
	//�Ե�����
}

//Ҷ�ӽڵ����
int bTreeLeafSize(Node* root)
{
	//����������Ҷ�ӵĺ�
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return bTreeLeafSize(root->_left) + bTreeLeafSize(root->_right);
}

//��k��ڵ�ĸ���
//��k��һ��
int bTreeKSize(Node* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return bTreeKSize(root->_left, k - 1) + bTreeKSize(root->_right, k - 1);
}

//����ĳ���ڵ�
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

//���ٶ����� ָ�����ȫ���ÿ� 
void bTreeDestory(Node** root)
{
	if (*root)
	{
		bTreeDesTory((&(*root)->_left));//����ָ������û���һ��ָ�� ����
		bTreeDesTory((&(*root)->_right));
		free(*root);
		*root = NULL;
	}
}

//�������
void bTreeLevelOrder(Node* root)
{
	//�������б���ڵ�
	Queue q;
	initQueue(&q);
	//���ڵ�������
	if (root)
		queuqePush(&q, root);
	//��������ÿһ���ڵ�
	while (!quequeEmpty(&q))
	{
		//��ȡ��ͷԪ��
		Node* front = queuqeFront(&q);
		//����
		quequePop(&q);

		//����˳���ܱ�
		printf("%d ", front->_data);
		//�������Ԫ�ص����Һ��ӽڵ�
		if (front->_left)
			queuePush(&q, front->_left);
		if (front->_right)
			queuePush(&q, front->_right);
	}
	printf("\n");
}


//�ж�һ�����ǲ���һ����ȫ������
//ͨ��������� ��ʣ�µ���û�зǿսڵ�
int isCompleteBtree(Node* root)
{
	Queue q;
	initQueue(&q);
	if (root)
		queuePush(&q, root);
	while (!quequeEmpty(&q))
	{
		//��ȡ��ͷԪ��
		Node* front = queueFront(&q);
		queuePop(&q);
		//���Һ������
		if (front)
		{
			queuePush(&q, front->_left);
			queuePush(&q, front->_right);
		}
		else
			break;
	}
	//�鿴ʣ��Ԫ���У��Ƿ��зǿսڵ�
	while (!quequeEmpty(&q))
	{
		Node* front = queueFront(&q);
		if (front)
			//����ʣ��Ԫ�����зǿսڵ㣬˵���ڵ㲻����
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