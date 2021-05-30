#include<stdio.h>
//8
// �������������ҳ����ǵĵ�һ���������
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
	struct ListNode* curA, * curB;
	curA = headA;
	curB = headB;
	int lenA = 0, lenB = 0;
	//ͳ�Ƴ���
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
	int gap = abs(lenA - lenB);//ȡ����ֵ
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

	//ͬʱ�ߵ����
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
//�ж��������Ƿ��л�(����������������ָ��) ������ڽڵ�
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
		if (fast == slow)//������߼����ж� �����������
			return true;
	}
	return false;
} 
//10
//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� NULL�������ĵ㲻һ������ڽڵ㣩
//�������
//L = C - X + (N - 1 ) * C     
//c�ǻ��ĳ���  ��ʼ�ڵ㵽��ڵľ���l  ��ڵ㵽�������λ��x
//�ҵ������� �ֱ���������ͷ��㿪ʼ�� ������λ�þ�����ڽڵ��λ��
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
		if (fast == slow)//������߼����ж� �����������
			return fast;
	}
	return NULL;
}

struct ListNode* detectCycle(struct ListNode* head)
{
	struct ListNode* cur = hasCycle(head);//��һ��������
	if (cur)
	{
		//�������㿪ʼͬʱ��
		while (cur)
		{
			if (cur == head)//�����ȵĻ����ҵ��� ��һ�����
				return cur;
			cur = cur->next;
			head = head->next;
		}
	}
	return NULL;
}

//11
//����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
//Ҫ�󷵻�����������ȿ���
struct Node* copyRandomList(struct Node* head)
{
	if (head == NULL)
		return head;
	while (cur)
	{
		struct Node* cur = head;
		//��������
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->val = cur->val;
		newNode->next = cur->next;
		cur->next = newNode;
		cur = newNode->next;
	}

	//�������ָ��
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

	//����
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
//��������в������򣨲�������
//�������������һ��λ����ǰ����
//��ǰ�Ⱥ��ҵ���һ�ȴ��������ݴ��λ��
struct ListNode* insertionSortList(struct ListNode* head) 
{
	if (head == NULL || head == NULL)
		return head;
	struct ListNode* node = head->next;
	//�����һ�����������
	struct ListNode* tail = head;
	//�ж�
	while (node)
	{
		if (node->val < tail->val)
		{
			//�����������С�����һ���������ݣ���Ҫ��������������ҵ�һ�����ʵ�λ�ò���
			struct ListNode* prev, * cur;
			prev = NULL;
			cur = head;
			//�ҵ���һ������node�Ľڵ�
			while (cur && cur->val <= node->val)
			{
				prev = cur;
				cur = cur->next;
			}
			tail->next = node->next;
			//�п���ͷ������
			if (prev)
				prev->next = node;
			else
				head = node;
			prev - next = node;
			node->next = cur;

			//��һ�����ݵ�����
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
