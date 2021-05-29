#include<stdio.h>
//5
//��������������ϲ�Ϊһ���µ� ���� �������ء�
//��������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
//��1
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
//{
//	if (l1 == NULL)
//		return l1 == NULL ? l2 : l1;
//	struct ListNode* cur1, * cur2, * newHead, * newTail;
//
//	newHead = newTail = NULL;
//	//ȷ��ͷ���
//	if (l1->val <= l2->val)
//	{
//		newHead = newTail = l1;
//		l1 = l1->next;
//	}
//	else
//	{
//		newHead = newTail = l2;
//		l2 = l2->next;
//	}
	//cur1 = l1;
	//cur2 = l2;
	////ͬʱ����
	//while (cur1 && cur2)
	//{
	//	if (cur1->val <= cur2->val)
	//	{
	//		newTail->next = cur1;
	//		newTail = newTail->next;
	//		cur1 = cur1->next;
	//	}
	//	else
	//	{
	//		newTail->next = cur2;
	//		newTail = newTail->next;
	//		cur2 = cur2->next;
	//	}
	//}
	//if (cur1)
	//	newTail->next = cur1;
	//if (cur2)
	//	newTail->next = cur2;
	//return newHead;
//}

//��2
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l1 == NULL ? l2 : l1;
	struct ListNode* cur1, * cur2, * newHead, * newTail;
	newHead = newTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	cur1 = l1;
	cur2 = l2;
	//ͬʱ����
	while (cur1 && cur2)
	{
		if (cur1->val <= cur2->val)
		{
			newTail->next = cur1;
			newTail = newTail->next;
			cur1 = cur1->next;
		}
		else
		{
			newTail->next = cur2;
			newTail = newTail->next;
			cur2 = cur2->next;
		}
	}
	if (cur1)
		newTail->next = cur1;
	if (cur2)
		newTail->next = cur2;
	struct ListNode* head = newHead->next;
	free(newHead);
	return head;
}

//6
//����һ�����ͷָ�� ListNode* pHead����һ��ֵx����дһ�δ��뽫����С��x�Ľ������������֮ǰ��
//�Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣

class Partition {
pubilc:
	ListNode* partition(ListNode* pHead, int x)
	{
		if (pHead == NULL)
			return pHead;
		struct LisNode* greaterHead, * greaterTail, * lessHead, * lessTail, *cur;
		greaterHead = greaterTail = lessHead = lessTail = NULL;
		cur = pHead;
		while (cur)
		{
			if (cur->val < x)
			{
				if (lessTail == NULL)
				{
					lessHead = lessTail = cur;
				}
				else//β��
				{
					lessTail->next = cur;
					lessTail = lessTail->next
				}
				cur = cur->next;
			}
			else
			{
				if (greaterTail == NULL)
				{
					greaterHead = greaterTail = cur;
				}
				else
				{
					greaterTail->next = cur;
					greaterTail = greaterTail->next
				}
				cur = cur->next;
			}
		}
		if (greaterTail)
			greater->next = NULL;
		//С����Ϊ�գ����ش�����
		if (lessrHead == NULL)
			return greaterHead;
		if (greaterHead == NULL)
		{
			if (lessTail)
				lessTail->next = NULL;
			return lessHead;
		}
		lseeTail->next = greaterHead;
		return lessHead;
	}
};

//7
//����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A)
	{
		if (A == NULL || A->next == NULL)
			return true;
		struct ListNode* fast.* slow;
		fast = slow = A;
		while (fast && fast->next)
		{
			fast == fast->next->next;
			slow = slow->next;//���ľ����м�ڵ�
		}
		//ͷ�������ת
		struct ListNode* newHead = NULL;
		struct ListNode* cur = slow;
		while (cur)
		{
			struct ListNode* next = cur->next;

			cur->next = newHead;
			newHead = cur;

			cur = next;
		}
		//ͬʱ����
		while (A && newHead)
		{
			if (A->val != newHead->val)
				return false;
			A = A->next;
			newHead = newHead->next;
		}
		return true;
	}
};