#include<stdio.h>
//1.
//给你一个链表的头节点 head 和一个整数 val 
//请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
//struct ListNode* removeElements(struct ListNode* head, int val) 
//{
//	struct ListNode* prev; 
//	struct ListNode* cur;
//	cur = head;
//	prev = NULL;//第一个就是要删除的 头要更新 更新到一下个值
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			//记录下一个指针
//			struct LisNode* next = cur->next;
//			//释放
//			free(cur);
//			//重新连接 和释放顺序无所谓
//			if (prev == NULL)
//				head = next;
//			else
//			    prev->next = next;//前驱应该等于下一个被释放的下一个位置
//
//			cur = next;//相当于移动cur
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//}

//2.
//翻转链表
//法1 头插
//struct ListNode* reverseList(struct ListNode* head) 
//{
//	if (head == NULL || head->next == NULL)
//		return head;
//	struct ListNode* newHead, * cur, * next;
//	newHead = NULL;
//	cur = head;
//	while (cur)
//	{
//		//链表的头插
//		next = cur->next;
//		//头插
//		cur->next = newHead;//当前节点的下一个位置等于头 1不指向2 指向下一个列表的头
//		newHead = cur;//头等于当前这个节点
//
//		cur = next;//更新
//	}
//	return newHead;
//}
//法2

//struct ListNode* reverseList(struct ListNode* head)
//{
//	if (head == NULL || head->next == NULL)
//		return head;
//	struct ListNode* n1, *n2, *n3;
//	n1 = NULL;
//	n2 = head;
//	n3 = n2->next;
//	while (n2)
//	{
//		n2->next = n1;
//		n1 = n2;
//		n2 = n3;
//		if(n3)
//		n3 = n3->next;
//	}
//	return n1;
//}

//3
//返回中间节点 如果有俩 返回第二个
//一次遍历找到节点 都从节点走 一个走一步一个走两步
//struct ListNode* middleNode(struct ListNode* head)
//{
//	struct ListNode* fast = head, * slow = head;
//	while (fast && fast->next)
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//	}
//	return slow;
//}

//4
//链表倒数第k个节点（先让快的走k个 然后同时走 到结束的时候 找到）
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//    struct ListNode* fast, * slow;
//    fast = slow = pListHead;
//    while (k--)
//    {
//        if (fast)
//            fast = fast->next;
//        else
//            return NULL;//k>链表长度
//    }
//    while (fast)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return slow;
//}

//5
//将两个升序链表合并为一个新的 升序 链表并返回。
//新链表是通过拼接给定的两个链表的所有节点组成的
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l1 == NULL ? l2 : l1;
	struct ListNode* cur1, * cur2, * newHead, * newTail;

	newHead = newTail = NULL;
	//确定头结点
	if (l1->val <= l2->val)
	{
		newHead = newTail = l1;
		l1 = l1->next;
	}
	else
	{
		newHead = newTail = l2;
		l2 = l2->next;
	}
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
	return newHead;
}