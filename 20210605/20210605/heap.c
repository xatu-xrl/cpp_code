#include<stdio.h>
#include<stdlib.h>
//二叉树的性质
//1. 若规定根节点的层数为1，则一棵非空二叉树的第i层上最多有2 ^ (i - 1) 个结点.
//2. 若规定根节点的层数为1，则深度为h的二叉树的最大结点数是2 ^ h - 1.
//3. 对任何一棵二叉树, 如果度为0其叶结点个数为 n0, 度为2的分支结点个数为 n2, 则有n0＝n2＋1
//4. 若规定根节点的层数为1，具有n个结点的满二叉树的深度，h = Log2(n + 1). (ps：Log2(n + 1)是log以2为
//底，n + 1为对数)
//
// 5. 对于具有n个结点的完全二叉树，如果按照从上至下从左至右的数组顺序对所有节点从0开始编号，则对
//于序号为i的结点有：
//	1. 若i > 0，i位置节点的双亲序号：(i - 1) / 2；i = 0，i为根节点编号，无双亲节点
//	2. 若2i + 1 < n，左孩子序号：2i + 1，2i + 1 >= n否则无左孩子
//	3. 若2i + 2 < n，右孩子序号：2i + 2，2i + 2 >= n否则无右孩子

typedef int HDataType;
typedef struct heap
{
	HDataType* _data;
	int _size;
	int _capacity;
}heap;

void heapInit(heap* hp)
{
	if (hp == NULL)
		return;
	hp->_data = NULL;
	hp->_size = hp->_capacity = 0;
}

//假设为小堆 向下调整的过程
void shiftDown(int* arr, int n, int curPos)//数组的指针 大小 当前需要调整的位置
 {
	//从左右孩子中找最小的
	//左孩子位置 2*curse + 1 编号从0开始
    //在比较和需要的值进行比较
	int child = 2 * curPos + 1;
	while (child < n)//孩子是存在的
	{
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		if (arr[child < arr[curPos]])
		{
			int tmp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = tmp;
			//继续执行从当前调整的位置进行操作
			curPos = child;
			child = 2 * curPos + 1;
		}
		else
			break;
	}
}

//向上调整logn的操作
void shiftUp(int* arr, int n, int cur)
{
	//父节点的位置
	int parent = (cur - 1) / 2;
	while (cur > 0)
	{
		//比较
		if (arr[cur] < arr[parent])
		{
			int tmp = arr[cur];
			arr[cur] = arr[parent];
			arr[parent];

			//更新到父节点的位置 继续向上更新
			cur = parent;
			parent = (cur - 1) / 2;
		}
		else
			break;
	}
}


void checkCapacity(heap* hp)
{
	if(hp->_size = hp->_capacity)
	{
		hp->_capacity = hp->_capacity  == 0 ? 1 : 2*hp->_capacity;
		hp->_data = (HDataType*)realloc(hp->_data, sizeof(HDataType) * hp->_capacity);
	}
}

void heapPush(heap* hp, HDataType val)
{
	//检查容量  尾插 向上调整
	checkCapacity(hp);

	hp->_data[hp->_size] = val;
	shiftUp(hp->_data, hp->_size, hp->_size - 1);
	hp->_size++;
}

//小堆->大堆 他的子结构都得是大堆 就是左右子树必须是堆
//从下往上调整
//从最后一个非叶子结点开始调整 就是倒数第二层的最后一个 （n-2）/2
//向下调整的次数和非叶子节点的个数相同

void creatHeap(int* arr, int n)
{
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		shiftDown(arr, n, i);
	}
}

int heapEmpty(heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return 1;
	else
		return 0;
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//堆顶和最后一个叶子进行交换
//尾部删除
//从0向下调整
void heapPop(heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return;
	Swap(hp->_data[0], &hp->_data[hp->_size - 1]);
	hp->_size--;
	shiftDown(hp->_data, hp->_size, 0);
}

HDataType heapTop(heap* hp)
{
	return hp->_data[0];
}

//堆来排序 不建议这么写
void test()
{
	int arr[] = { 20,17,4,16,5,3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//建堆o（n）
	for (int i = (n - 2 / 2); i >= 0; --i)
	{
		shiftDown(arr, n, i);
	}
	//堆排序o（logn）
	int end = n - 1;
	while (end > 0)
	{
		//删除的过程
		Swap(&arr[0], &arr[end]);
		shiftDown(arr, end, 0);
		--end;
	}
}

//void test()
//{
//	heap hp;
//	heapInit(&hp);
//	heapPush(&hp, 28);
//	heapPush(&hp, 29);
//	heapPush(&hp, 45);
//	heapPush(&hp, 46);
//	heapPush(&hp, 25);
//	heapPush(&hp, 38);
//	heapPush(&hp, 19);
//	heapPush(&hp, 8);
//
//}

int main()
{
	test();
	return 0;
}