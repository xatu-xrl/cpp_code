//非递归的快排
//直观
//划分不能少 可以得到区间
//可以定义一个结构体 利用顺序表 或者栈 或者 队列 只要待划分的区间保存下来处理了就行

//顺序表实现
#include"list.h"

//三数取中 获取基准值
int getMid(int* arr, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])//mid end begin
			return end;
		else //mid begin end
			return begin;
	}
	else
	{
		if (arr[mid] < arr[end])
			return mid;
		else if (arr[begin] < arr[end])// begin end mid
			return end;
		else
			return begin;
	}
}

int partion(int* arr, int begin, int end)
{
	//获取基准值的位置
	int mid = getMid(arr, begin, end);
	//三个位置相对比较居中的位置
	Swap(arr, begin, mid);
	//选择基准值
	int key = arr[begin];
	int start = begin;

	while (begin < end)//直到相遇都继续走
	{
		//从后往前找小的
		while (begin < end && arr[end] >= key)
			--end;

		//找大的
		while (begin < end && arr[begin] <= key)
			++begin;

		//交换
		Swap(arr, begin, end);
	}
	//相遇时交换基准值和相遇位置的数据
	Swap(arr, start, begin);
	return begin;
}

void quickSortNoR(int* arr, int n)
{
	//创建一个顺序表，保持待划分的区间
	seqList sq;
	initseqList(&sq);
	//保存整个区间
	//先放右再放左  [0, n - 1]
	seqListpushBack(&sq, n - 1);
	seqListpushBack(&sq, 0);

	//遍历顺序表，处理所有区间
	while (!seqListEmpty(&sq))
	{
		//取出一个区间
		int left = seqListBack(&sq);
		seqListpopBack(&sq);
		int right = seqListBack(&sq);
		seqListpopBack(&sq);

		//划分区间[left,right]
		int div = partion(arr, left, right);


		//保存两个新的区间
		//[left,div - 1] 为新的下次划分   说明至少有两个元素
 		if (left < div - 1)
		{
			seqListpushBack(&sq, div - 1);
			seqListpushBack(&sq, left);
		}

		//[div+ 1,right]
		if (div + 1 < right)
		{
			seqListpushBack(&sq, div + 1);
			seqListpushBack(&sq, right);
		}
	}
}

//队列
void quickSortNoR2(int* arr, int n)
{
	Queue q;
	initQueue(&q);

	//保存区间
	quequePush(&q, 0);
	quequePush(&q, n - 1);

	//遍历队列
	while (!queueEmpty(&q))
	{
		int left = queueFront(&q);
		queuePop(&q);
		int right = queueFront(&q);
		queuePop(&q);

		//划分区间[left,right]
		int div = partion(arr, left, right);

		if (left < div - 1)
		{
			queuePush(&q, left);
			queuePush(&q, div - 1);
		}

		//[div+ 1,right]
		if (div + 1 < right)
		{
			queuePush(&q, div + 1);
			queuePush(&q, right);
		}
	}
}