#include<stdio.h>

//˫������ļ�ʵ��

typedef int LDataType;

//˫��ڵ�
typedef struct ListNode
{
	LDataType _data;
	struct ListNode* _prev;
	struct ListNode* _next;
}ListNode;

//˫���ͷѭ������
typedef struct List
{
	struct ListNode* _head;
}List;

void listInsert(ListNode* node, LDataType val);
void lsitErase(ListNode* node);

void ininList(List* lst)
{
	//�յĴ�ͷ˫��ѭ������
	//����ѭ������
	//����ͷ���
	lst->_head = (struct ListNode*)malloc(sizeof(struct ListNode));
	//ѭ��
	lst->_head->_prev = lst->_head->_next = lst->_head;

}

//�����ڵ�
struct ListNode* creatNode(LDataType val)
{
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->_data = val;
	node->_next = node->_prev = NULL;
	return node;
}

//β��(����Ҫ���� preָ��Ϊ�ڵ� �޸�4�� o1�Ĳ���)
void listPushBack(List* lst, LDataType val)
{
	/*struct ListNode* tail = lst->_head->_prev;
	struct ListNode* newNode = creatNode(val);

	tail->_next = newNode;
	newNode->_next = tail;

	lst->_head->_prev = newNode;
	newNode->_next = lst->_head;*/
	ListInsert(lst->_head,val);//
}

//βɾ
//head->next ��һ�����ݽڵ� _head->prevβ�ڵ�  o1�Ĳ���
void listPopBack(List* lst)
{
	if (lst->_head->_prev == lst->_head)
		return;
	/*struct ListNode* tail = lst->_head->_prev;
	struct ListNode* prev = tail->_prev;

	free(tail);

	prev->_next = lst->_head;
	lst->_head->_prev = prev;*/

	lsitErase(lst->_head->_prev);
}

//��ӡ
void printList(List* lst)
{
	struct LisNode* cur = lst->_head->_next;
	while (cur != lst->_head)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

//ͷ�� head newNode _head->next
void listPushFront(List* lst, LDataType val)
{
	/*struct ListNode* newNode = creatNode(val);
	struct ListNode* next = lst->_head->_next;

	lst->_head->_next = newNode;
	newNode->_prev = lst->_head;

	next->_prev = newNode;
	newNode->_next = next;*/

	ListInsert(lst->_head->_next, val);
}

//ͷɾ
void listPopFront(List* lst)
{
	//struct ListNode* next = lst->_head->_next;
	//struct ListNode* nextnext = next->_next;
	////head next nextnext

	//free(next);

	//lst->_head->_next = nextnext;
	//nextnext->_prev = lst->_head;

	lsitErase(lst->_head->_next);
}

//����λ�ò���
void listInsert(ListNode* node, LDataType val)
{
	struct ListNode* newNode = creatNode(val);
	struct ListNode* prev = node->_prev;

	node->_prev = newNode;
	newNode->_next = node;

	prev->_next = newNode;
	newNode->_prev = prev;
}

//ͷ�� insert(head->next,val)
//β��Insert��head,val)

//����ɾ��
void lsitErase(ListNode* node)
{
	struct ListNode* prev = node->_prev;
	struct ListNode* next = node->_next;

	free(node);
	prev->_next = next;
	next->_prev = prev;
}

//����
listDestroy(List* lst)
{
	struct LsirNode* cur = lst->_head->_next;
	while (cur != lst->_head)//�ӵ�һ����Ч�ڵ㿪ʼ
	{
		struct ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	
	free(lst->_head);
	lst->_head = NULL;
}


void test()
{
	struct List lst;
	ininList(&lst);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPushBack(&lst, 5);

	listPopFront(&lst);
	listPopFront(&lst);
	listPopFront(&lst);

	/*listPopBack(&lst);
	listPopBack(&lst);
	listPopBack(&lst);
	listPopBack(&lst);
	listPopBack(&lst);*/
}

int main()
{
	test();
	return 0;
}

//1.��һ������Ϊn��˳�����ɾ����i��Ԫ�أ�Ҫ�ƶ�__a_____��Ԫ�ء����Ҫ�ڵ�i��Ԫ��ǰ����һ��Ԫ�أ�Ҫ��
//��_________��Ԫ�ء�
//A n - i��n - i + 1
//B n - i + 1��n - i
//C n - i��n - i
//D n - i + 1��n - i + 1
// 
//2.ȡ˳���ĵ�i��Ԫ�ص�ʱ��ͬi�Ĵ�С�й�(b)
//A ��
//B ��
//
//3.��һ������ n ���������������в���һ���½�㲢��Ȼ���������ʱ�临�Ӷ���b( ��
//A O��1��
//B O��n��
//C O��n2��
//D O��nlog2n��
// 
//4.���й�����������������У���ȷ���ǣ�c ����
//A �����ݽ��Ĵ洢�ռ���Բ������������ǵĴ洢˳�����߼�˳�����һ��
//B �����ݽ��Ĵ洢˳�����߼�˳����Բ�һ�£������ǵĴ洢�ռ��������
//C ���в�����ɾ��ʱ������Ҫ�ƶ����е�Ԫ��
//D ����˵��������ȷ
// 
//5.��һ��������õĲ�������ĩβ�������ɾ��β��㣬��ѡ�ã�d�����ʡʱ�䡣
//A ������
//B ��ѭ������
//C ��βָ��ĵ�ѭ������
//D ��ͷ����˫ѭ������
//
// 
//6.�������е��ص��ǣ�c����
//A ���롢ɾ������Ҫ�ƶ�Ԫ��
//B �������ȹ��ƴ洢�ռ�
//C �����������һԪ��
//D ����ռ������Ա��ȳ�����
// 
//7.��һ���������У���ɾ�� P ��ָ���ĺ�����㣬��ִ�� ?
//A p = p->next��p->next = p->next->next;
//B p->next = p->next;
//C p->next = p->next->next;
//D p = p->next->next
// 
//8.һ�����������������һ��ָ��p����Ҫ��ָ��r���뵽p֮�󣬸ý��еĲ�����c____��
//A p->next = p->next->next
//B r->next = p; p->next = r->next
//C r->next = p->next; p->next = r
//D r = p->next; p->next = r->next
//E r->next = p; p->next = r
//F p = p->next->next
// 