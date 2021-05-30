#include<stdio.h>
//8
// 输入两个链表，找出它们的第一个公共结点
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
	struct ListNode* curA, * curB;
	curA = headA;
	curB = headB;
	int lenA = 0, lenB = 0;
	//统计长度
	while (curA)
	{
		++lenA;
		curA = curA->next;
	}

	while (curB)
	{
		++lenB;
		curB = curB->next;
	}
	curA = headA;
	curB = headB;
	int gap = abs(lenA - lenB);//取绝对值
	if (lenA > lenB)
	{
		while (gap--)
		{
			curA = curA->next;
		}
	}
	else
	{
		while (gap--)
		{
			curB = curB->next;
		}
	}

	//同时走的情况
	while (curA && curB)
	{
		if (curA == curB)
			return curA;
		curA = curA->next;
		curB = curB->next;
	}

	return NULL;
}

//9
//判断链表中是否有环(还是设置两个快慢指针) 环的入口节点
bool hasCycle(struct ListNode* head) 
{
	if (head == NULL)
		return false;
	struct ListNode* fast, * slow;
	fast = head->next;
	slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)//如果先走几步判断 进来就是真的
			return true;
	}
	return false;
} 
//10
//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL（相遇的点不一定是入口节点）
//三种情况
//L = C - X + (N - 1 ) * C     
//c是环的长度  起始节点到入口的距离l  入口点到相遇点的位置x
//找到相遇点 分别从相遇点和头结点开始走 相遇的位置就是入口节点的位置
struct ListNode* hasCycle(struct ListNode* head)
{
	if (head == NULL)
		return NULL;
	struct ListNode* fast, * slow;
	fast = head;
	slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)//如果先走几步判断 进来就是真的
			return fast;
	}
	return NULL;
}

struct ListNode* detectCycle(struct ListNode* head)
{
	struct ListNode* cur = hasCycle(head);//第一次相遇点
	if (cur)
	{
		//从相遇点开始同时走
		while (cur)
		{
			if (cur == head)//如果相等的话就找到了 第一种情况
				return cur;
			cur = cur->next;
			head = head->next;
		}
	}
	return NULL;
}

//11
//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//要求返回这个链表的深度拷贝
struct Node* copyRandomList(struct Node* head)
{
	if (head == NULL)
		return head;
	while (cur)
	{
		struct Node* cur = head;
		//拷贝数据
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->val = cur->val;
		newNode->next = cur->next;
		cur->next = newNode;
		cur = newNode->next;
	}

	//拷贝随机指针
	cur = head;
	while (cur)
	{
		struct Node* copy = cur->next;
		if (cur->random)
			copy->random = cur->random->next;
		else
			copy->random = NULL;
		cur = copy->next;
	}

	//拆链
	struct Node* newHead = NULL;
	cur = head;
	while (cur)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;

		cur->next = next;
		if (newHead == NULL)
			newHead = copy;
		if(next)
		copy->next = next->next;

		cur = next;
	}
	return newHead;
}

//12
//对链表进行插入排序（插入排序）
//从有序序列最后一个位置向前查找
//从前先后找到第一比待排序数据大的位置
struct ListNode* insertionSortList(struct ListNode* head) 
{
	if (head == NULL || head == NULL)
		return head;
	struct ListNode* node = head->next;
	//假设第一个就是有序的
	struct ListNode* tail = head;
	//判断
	while (node)
	{
		if (node->val < tail->val)
		{
			//待排序的数据小于最后一个有序数据，需要在有序的链表中找到一个合适的位置插入
			struct ListNode* prev, * cur;
			prev = NULL;
			cur = head;
			//找到第一个大于node的节点
			while (cur && cur->val <= node->val)
			{
				prev = cur;
				cur = cur->next;
			}
			tail->next = node->next;
			//有可能头部插入
			if (prev)
				prev->next = node;
			else
				head = node;
			prev - next = node;
			node->next = cur;

			//下一个数据的排序
			node = tail->next;
		}
		else
		{
			tail = tail->next;
			node = tail->next;
		}
	}
	return head;
}
