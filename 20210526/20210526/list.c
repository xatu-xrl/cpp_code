#include<stdio.h>
//1.
//����һ�������ͷ�ڵ� head ��һ������ val 
//����ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
//struct ListNode* removeElements(struct ListNode* head, int val) 
//{
//	struct ListNode* prev; 
//	struct ListNode* cur;
//	cur = head;
//	prev = NULL;//��һ������Ҫɾ���� ͷҪ���� ���µ�һ�¸�ֵ
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			//��¼��һ��ָ��
//			struct LisNode* next = cur->next;
//			//�ͷ�
//			free(cur);
//			//�������� ���ͷ�˳������ν
//			if (prev == NULL)
//				head = next;
//			else
//			    prev->next = next;//ǰ��Ӧ�õ�����һ�����ͷŵ���һ��λ��
//
//			cur = next;//�൱���ƶ�cur
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//}

//2.
//��ת����
//��1 ͷ��
//struct ListNode* reverseList(struct ListNode* head) 
//{
//	if (head == NULL || head->next == NULL)
//		return head;
//	struct ListNode* newHead, * cur, * next;
//	newHead = NULL;
//	cur = head;
//	while (cur)
//	{
//		//�����ͷ��
//		next = cur->next;
//		//ͷ��
//		cur->next = newHead;//��ǰ�ڵ����һ��λ�õ���ͷ 1��ָ��2 ָ����һ���б��ͷ
//		newHead = cur;//ͷ���ڵ�ǰ����ڵ�
//
//		cur = next;//����
//	}
//	return newHead;
//}
//��2

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
//�����м�ڵ� ������� ���صڶ���
//һ�α����ҵ��ڵ� ���ӽڵ��� һ����һ��һ��������
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
//��������k���ڵ㣨���ÿ����k�� Ȼ��ͬʱ�� ��������ʱ�� �ҵ���
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//    struct ListNode* fast, * slow;
//    fast = slow = pListHead;
//    while (k--)
//    {
//        if (fast)
//            fast = fast->next;
//        else
//            return NULL;//k>������
//    }
//    while (fast)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return slow;
//}

//5
//��������������ϲ�Ϊһ���µ� ���� �������ء�
//��������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l1 == NULL ? l2 : l1;
	struct ListNode* cur1, * cur2, * newHead, * newTail;

	newHead = newTail = NULL;
	//ȷ��ͷ���
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
	return newHead;
}