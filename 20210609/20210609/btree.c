#include<stdio.h>
#include<stdlib.h>

//ͨ������ʵ�ֶ������������
//push_backβ��  push_frontͷɾ listempty head��ȡ��ͷ
//
//int isCompleteBtree(Node* root)
//{
//	list q;
//	initList(&q);
//	if (root)
//		push_back(&q, root);
//	while (!listEmpty(&q))
//	{
//		Node* front = head(&q);
//		pop_front(&q);
//		if(root)
//		{
//			push_back(&q, front->_left);
//			push_back(&q, front->_right);
//		}
//	    else
//		break;
//	}
//	//��ʣ��Ԫ�����Ƿ��зǿսڵ� �Ƚ��ȳ�
//	while (!listEmpty(&q))
//	{
//		Node* front = head(&q);
//		pop_front(&q);
//		if (front)
//			return 0;
//	}
//}


//1
//�ж��ǲ��ǵ�ֵ������
//�����Ͼ��Ǳ���
// 
//bool _isUnivalTree(struct TreeNode* root��int val��
//	{
//		if (root)
//		{
//			return root->val == val
//				&& _isUnivalTree(root->_left,val)
//				&& _isUnivalTree(root->right,val);
//		}
//		else
//			return true;
//}
//
//bool isUnivalTree(struct TreeNode* root)
//{
//	if (root == NULL)
//		return true;
//		return _isUnivalTree(root, root->_val);
//}

//2
//��ת������
//����ת��

//struct TreeNode* invertTree(struct TreeNode* root)
//{
//	if (root == NULL)
//		return NULL;
//	//������������
//	struct TreeNode* tmp = root->left;
//	root->left = root->right;
//	root->right = tmp;
//	invertTree(root->left);
//	invertTree(root->right);
//	return root;
//}

//3
//����������Ƿ���ͬ ��ֵ�ͽṹ������ͬ 
//�������ͬ��ʽ���� �ṹӦ����ͬ
//����û��ͬʱ����սڵ� ����ͬ

//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//	if (p == NULL && q == NULL)
//		return true;
//	if (p == NULL || q == NULL)
//		return false;
//	return p->val = q->val && isSameTree(p->left��q->left�� && isSameTree(q->right,p->right));
//}

//4
//�ж�һ�����ǲ�����һ����������
//
//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//	if (p == NULL && q == NULL)
//		return true;
//	if (p == NULL || q == NULL)
//		return false;
//	return p->val = q->val && isSameTree(p->left��q->left�� && isSameTree(q->right, p->right));
//}
//
//bool isSubtree(struct Tree* s, struct TreeNode* t)
//{
//	if (t == NULL)
//		return true;
//	if (s == NULL)
//		return false;
//	return isSameTree(s, t) || isSameTree(s->left, t) || isSameTree(s->right, t);
//}

//5
//�Գƶ����� �Ƿ��Ǿ���Գ�
//
//bool _isSym(struct Tree* left,struct TreeNode* right)
//{
//	if (left == NULL && right == NULL)
//		return true;
//	if (left == NULL || right == NULL)
//		return false;
//	return (left->val == right->val) && _isSym(left->left, right->right) && _isSym(left->right, right->left);
//}
//
//bool isSymmetric(struct TreeNode* root)
//{
//	if (root == NULL)
//		return true;
//	return _isSym(root->left, root->right);
//}

//ƽ�������
//int getHeight(struct TreeNode* root)
//{
//	if (root)
//	{
//		int left = getHeight(root->left);
//		int right = getHeight(root->right);
//	    return left > right ? left + 1 : right + 1;
//	}
//	return 0;
//}
//
//bool isBalanced(struct TreeNode* root)
//{
//	if (root == NULL)
//		return true;
//	int left = getHeight(root->left);
//	int right = getHeight(root->right);
//	return abs(left - right) < 2
//		&& isBalanced(root->left)
//		&& isBalanced(root->right);
//}

