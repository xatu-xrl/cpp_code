#include<stdio.h>

//双向链表的简单实现

typedef int LDataType;

//双向节点
typedef struct ListNode
{
	LDataType _data;
	struct ListNode* _prev;
	struct ListNode* _next;
}ListNode;

//双向带头循环链表
typedef struct List
{
	struct ListNode* _head;
}List;

void listInsert(ListNode* node, LDataType val);
void lsitErase(ListNode* node);

void ininList(List* lst)
{
	//空的带头双向循环链表
	//构建循环链表
	//创建头结点
	lst->_head = (struct ListNode*)malloc(sizeof(struct ListNode));
	//循环
	lst->_head->_prev = lst->_head->_next = lst->_head;

}

//创建节点
struct ListNode* creatNode(LDataType val)
{
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->_data = val;
	node->_next = node->_prev = NULL;
	return node;
}

//尾插(不需要遍历 pre指向为节点 修改4个 o1的操作)
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

//尾删
//head->next 第一个数据节点 _head->prev尾节点  o1的操作
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

//打印
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

//头插 head newNode _head->next
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

//头删
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

//任意位置插入
void listInsert(ListNode* node, LDataType val)
{
	struct ListNode* newNode = creatNode(val);
	struct ListNode* prev = node->_prev;

	node->_prev = newNode;
	newNode->_next = node;

	prev->_next = newNode;
	newNode->_prev = prev;
}

//头插 insert(head->next,val)
//尾插Insert（head,val)

//任意删除
void lsitErase(ListNode* node)
{
	struct ListNode* prev = node->_prev;
	struct ListNode* next = node->_next;

	free(node);
	prev->_next = next;
	next->_prev = prev;
}

//销毁
listDestroy(List* lst)
{
	struct LsirNode* cur = lst->_head->_next;
	while (cur != lst->_head)//从第一个有效节点开始
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

//1.在一个长度为n的顺序表中删除第i个元素，要移动__a_____个元素。如果要在第i个元素前插入一个元素，要后
//移_________个元素。
//A n - i，n - i + 1
//B n - i + 1，n - i
//C n - i，n - i
//D n - i + 1，n - i + 1
// 
//2.取顺序表的第i个元素的时间同i的大小有关(b)
//A 对
//B 错
//
//3.在一个具有 n 个结点的有序单链表中插入一个新结点并仍然保持有序的时间复杂度是b( 。
//A O（1）
//B O（n）
//C O（n2）
//D O（nlog2n）
// 
//4.下列关于线性链表的叙述中，正确的是（c ）。
//A 各数据结点的存储空间可以不连续，但它们的存储顺序与逻辑顺序必须一致
//B 各数据结点的存储顺序与逻辑顺序可以不一致，但它们的存储空间必须连续
//C 进行插入与删除时，不需要移动表中的元素
//D 以上说法均不正确
// 
//5.设一个链表最常用的操作是在末尾插入结点和删除尾结点，则选用（d）最节省时间。
//A 单链表
//B 单循环链表
//C 带尾指针的单循环链表
//D 带头结点的双循环链表
//
// 
//6.链表不具有的特点是（c）。
//A 插入、删除不需要移动元素
//B 不必事先估计存储空间
//C 可随机访问任一元素
//D 所需空间与线性表长度成正比
// 
//7.在一个单链表中，若删除 P 所指结点的后续结点，则执行 ?
//A p = p->next；p->next = p->next->next;
//B p->next = p->next;
//C p->next = p->next->next;
//D p = p->next->next
// 
//8.一个单向链表队列中有一个指针p，现要将指针r插入到p之后，该进行的操作是c____。
//A p->next = p->next->next
//B r->next = p; p->next = r->next
//C r->next = p->next; p->next = r
//D r = p->next; p->next = r->next
//E r->next = p; p->next = r
//F p = p->next->next
// 