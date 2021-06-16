#include<stdio.h>

//挖坑法快速排序

//void Swap(int* arr, int n1, int n2)
//{
//	int tmp = arr[n1];
//	arr[n1] = arr[n2];
//	arr[n2] = tmp;
//}
//
////三数取中 获取基准值
//int getMid(int* arr, int begin, int end)
//{
//	int mid = begin + (end - begin) / 2;
//	if (arr[begin] > arr[mid])
//	{
//		if (arr[mid] > arr[end])
//			return mid;
//		else if (arr[begin] > arr[end])//mid end begin
//			return end;
//		else //mid begin end
//			return begin;
//	}
//	else
//	{
//		if (arr[mid] < arr[end])
//			return mid;
//		else if (arr[begin] < arr[end])// begin end mid
//			return end;
//		else
//			return begin;
//	}
//}
//
////返回基准值的位置 
//int partion(int* arr, int begin, int end)
//{
//	int mid = getMid(arr, begin, end);
//	Swap(arr, begin, end);
//
//	//第一个值作为基准值，第一个位置就是第一个坑
//	int key = arr[begin];
//	while (begin < end)
//	{
//		//从后向前找小的
//		while (begin < end && arr[end] >= key)
//			--end;
//
//		//填坑
//		arr[begin] = arr[end];
//
//		//从前向后找大的
//		while (begin < end && arr[begin] <= key)
//			++begin;
//		//填坑
//		arr[end] = arr[begin];
//	}
//	//相遇时 这个值作作为基准值
//	arr[begin] = key;
//	return begin;
//}
//
//void quickSort(int* arr, int begin, int end)
//{
//	if (begin >= end)
//		return;
//	int div = partion(arr, begin, end);
//
//	quickSort(arr, begin, div - 1);
//	quickSort(arr, div + 1, end);
//}


//前后指针法
// prev上一个小于基准值的位置
// cur 下一个小于基准值的位置
// 当cur找到一个小于基准值的位置
// 判断这区间是否连续 就是看中间还有没有元素
// 如果连续 区间内都是不大于基准值 更新这两个值
// 如果不连续 先让cur和prev的下一个值交换 然后更新cur 持续这样
// 直至cur走完 然后比较prev和基准值的值 进行交换 更新了基准值的位置
//走完一次
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
	int mid = getMid(arr, begin, end);
	Swap(arr, mid, begin);

	int prev = begin;
	int cur = cur + 1;
	int key = arr[begin];
	while (arr <= end)
	{
		//cur走到位置，判断是否连续
		if (arr[cur] < key && ++prev != cur)
		{
			Swap(arr, prev, cur);
		}
		++cur;
	}
	Swap(arr, begin, prev);
	return prev;
}

void quickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	int div = partion(arr, begin, end);

	quickSort(arr, begin, div - 1);
	quickSort(arr, div + 1, end);
}



