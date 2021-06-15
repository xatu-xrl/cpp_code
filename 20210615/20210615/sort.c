#include<stdio.h>
//交换排序
//快速排序 升序
//horae 选一个基准值（一般是第一个）也可以选中间位置 防止有序 性能极大退化 从剩余元素中开始遍历 一二步不能交换顺序
// 如果是递减顺序的话  1.从后往前找大的  2.
//1.从后往前找到第一个小于基准值的数据
//2.从前往后找到第一个大于基准值的数据
//3.交换两个值
//4.继续走 换到相遇
//5.用相遇位置和基准值交换

//划分区间  返回划分区间之后 基准值所在的位置

void Swap(int* arr, int n1, int n2)
{
	int tmp = arr[n1];
	arr[n1] = arr[n2];
	arr[n2] = tmp;
}

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

//不稳定的排序
//数据有序时，可能会导致栈溢出 on^2
void quickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//找到了基准值该在的位置
	int div = partion(arr, begin, end);
	//左右两部分进行快速排序
	//[beigin, div - 1]
	//[div + 1, end]
	quickSort(arr, begin, div);
	quickSort(arr, div + 1, end);

}