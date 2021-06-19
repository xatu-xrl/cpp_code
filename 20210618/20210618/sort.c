#include<stdio.h>
#include<string.h>

//归并
//相邻子序列合并 begin end end+1  end2

//beigin  mid     end 
void merge(int* arr, int begin, int mid, int end, int* tmp)//tmp辅助空间
{
	//递增排序
	//子区间[ begin1 mid ]  [ mid + 1  end]
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	int idx = begin;

	//合并有序序列
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])//小于等于就是稳定的
			tmp[idx++] = arr[begin1++];
		else
			tmp[idx++] = arr[begin2++];
	}
	//判断是否有未合并的元素 就是当奇数的情况 放在最后面不用处理
	if (begin1 <= end1)
		memcpy(tmp + idx, arr + begin1, sizeof(int) * (end1 - begin1 + 1));
	if(begin2 <= end)
		memcpy(tmp + idx, arr + begin2, sizeof(int) * (end2 - begin2 + 1));

	//合并的元素拷到原始数组对应区间中
	memcpy(arr + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void _mergeSort(int* arr, int begin, int end, int* tmp)
{
	if(begin >= end)
		return;
	int mid = begin + (end - begin) / 2;

	//合并子序列
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr,  mid + 1, end, tmp);

	//合并两个有序的子序列
	merge(arr, begin, mid, end, tmp);
}

void mergeSort(int* arr, int n)
{
	//申请辅助空间
	int* tmp = (int*)malloc(sizeof(int) * n);
	_mergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}




//非递归写法  自己划分区间 

//要合并的第一个序列
// begin:idx
// end:idx + step - 1
// 要合并的第二个序列
// begin:idx + step
// end:idx + 2*step - 1
// 
// idx += 2*step
// 
//step * = 2

void mergeSortNoR(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	//自底向上的过程
	int step = 1;
	while (step < n)
	{
		for (int idx = 0; idx < n; idx += 2 * step)
		{
			//找到两个带合并的子序列区间
			//[begin, mid] [mid + 1, end]
			int begin = idx;
			int mid = idx + step - 1;
			//判断是否存在第二个子序列 就是奇数情况
			if (mid >= n - 1)
				//不存在第二个子序列
				continue;
			int end = idx + 2 * step - 1;
			//判断第二个字子序列是否越界
			if (end > n)
				end = n - 1;
			merge(arr, begin, mid, end, tmp);
		}

		//更新步长
		step *= 2;
	}
}

//非比较排序
//空间复杂度 高
void countSort(int* arr, int n)
{
	//先找到最值
	int max, min;
	min = max = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[min];
	}
	//计算范围 节省空间
	int range = max - min + 1;
	int* countArr = (int*)calloc(range, sizeof(int));//完成初始化

	//计数
	for (int i = 0; i < n; ++i)
	{
		countArr[arr[i] - min]++;
	}

	//遍历 计数数组
	int idx = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArr[i]--)
		{
			arr[idx++] = i + min;
		}
	}
}