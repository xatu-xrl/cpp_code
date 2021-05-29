#include<stdio.h>
//5
//将两个升序链表合并为一个新的 升序 链表并返回。
//新链表是通过拼接给定的两个链表的所有节点组成的
//法1
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
//{
//	if (l1 == NULL)
//		return l1 == NULL ? l2 : l1;
//	struct ListNode* cur1, * cur2, * newHead, * newTail;
//
//	newHead = newTail = NULL;
//	//确定头结点
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
	////同时遍历
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

//法2
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l1 == NULL ? l2 : l1;
	struct ListNode* cur1, * cur2, * newHead, * newTail;
	newHead = newTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	cur1 = l1;
	cur2 = l2;
	//同时遍历
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
//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，
//且不能改变原来的数据顺序，返回重新排列后的链表的头指针。

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
				else//尾插
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
		//小链表为空，返回大链表
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
//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900
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
			slow = slow->next;//慢的就是中间节点
		}
		//头插进行逆转
		struct ListNode* newHead = NULL;
		struct ListNode* cur = slow;
		while (cur)
		{
			struct ListNode* next = cur->next;

			cur->next = newHead;
			newHead = cur;

			cur = next;
		}
		//同时遍历
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