#include<stdio.h>
#include<stdlib.h>

//通过链表实现二叉树层序遍历
//push_back尾插  push_front头删 listempty head获取表头
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
//	//看剩余元素中是否有非空节点 先进先出
//	while (!listEmpty(&q))
//	{
//		Node* front = head(&q);
//		pop_front(&q);
//		if (front)
//			return 0;
//	}
//}


//1
//判断是不是单值二叉树
//本质上就是遍历
// 
//bool _isUnivalTree(struct TreeNode* root，int val）
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
//反转二叉树
//镜像转变

//struct TreeNode* invertTree(struct TreeNode* root)
//{
//	if (root == NULL)
//		return NULL;
//	//交换左右子树
//	struct TreeNode* tmp = root->left;
//	root->left = root->right;
//	root->right = tmp;
//	invertTree(root->left);
//	invertTree(root->right);
//	return root;
//}

//3
//检查两棵树是否相同 数值和结构都得相同 
//如果是相同方式遍历 结构应该相同
//若果没有同时到达空节点 则不相同

//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//	if (p == NULL && q == NULL)
//		return true;
//	if (p == NULL || q == NULL)
//		return false;
//	return p->val = q->val && isSameTree(p->left，q->left） && isSameTree(q->right,p->right));
//}

//4
//判断一个树是不是另一个树的子树
//
//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//	if (p == NULL && q == NULL)
//		return true;
//	if (p == NULL || q == NULL)
//		return false;
//	return p->val = q->val && isSameTree(p->left，q->left） && isSameTree(q->right, p->right));
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
//对称二叉树 是否是镜像对称
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

//平衡二叉树
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

