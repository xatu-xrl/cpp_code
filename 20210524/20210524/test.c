#include<stdio.h>
//数组相关面试题
//1
//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

//使用额外数组的方法
//int removeElement(int* nums, int numsSize, int val)//空间复杂度是o(n)
//{
//	int* newArr = (int*)malloc(sizeof(int) * numsSize);
//	int idx = 0;//新的数据存放的位置
//	for (int i = 0; i < numsSize; ++i)
//	{
//		if (nums[i] != val)
//		{
//			newArr[idx++] = nums[i];
//		}
//	}
//	memcpy(nums, newArr, sizeof(int) * idx);
//	free(newArr);
//	return idx;
//}
//所以用后面覆盖就可了，不用新申请一块内存去保存

int removeElement(int* nums, int numsSize, int val)
{
	int i = 0;
	int idx = 0;
	for (; i < numsSize; ++i)
	{
		if (nums[i] != val)
		{
			nums[idx++] = nums[i];
		}
	}
	return idx;
}

//2
//给你一个有序数组 nums ，请你原地删除重复出现的元素，使每个元素只出现一次返回删除后数组的新长度。
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成

int removeDuplicates(int* nums, int numsSize) 
{
	if (numsSize <= 1)
		return  numsSize;
	int i = 0, j = 0, idx = 0;
	while (j < numsSize)
	{
		nums[idx++] = nums[i];
		//判断是否重复
		if (nums[i] == nums[j])
		{
			while(j < numsSize && nums[i] == nums[j])
			{
				++j;
				i = j;
				++j;
			}
		}
		else
		{
			++j;
			++i;
		}
	}
	if (i < numsSize)
	{
		nums[idx++] = nums[i];//保存最后一个数据
	}
	return idx;
}
//3
//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
//
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。

//开辟一个新的空间
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//	int* nums3 = (int*)malloc(sizeof(int) * (m + n));
//	int i = 0, j = 0, idx = 0;
//	//同时遍历
//	while (i < m && j < n)//m n 表示有效元素 不要用数组大小
//	{
//		if (nums1[i] < nums2[j])
//		{
//			nums3[idx++] = nums1[i++];
//		}
//		else
//		{
//			nums3[idx++] = nums2[j++];
//		}
//	}
//	//剩余拷贝
//	if (i < m)
//		memcpy(nums3 + idx, nums1 + i, sizeof(int) * (m - i));
//	if (j < n)
//		memcpy(nums3 + idx, nums2 + j, sizeof(int) * (n - j));
//	//合并好的元素放进一个
//	memcpy(nums1, nums3, sizeof(int) * (m + n));
//	free(nums3);
//}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int i = m - 1, j = n - 1, idx = m + n - 1;
	//从后向前插入
	while (nums1[i] >= nums2[j])
	{
		if (nums1[i] >= nums2[j])
		{
			nums1[idx--] == nums1[i--];
		}
		else
		{
			nums1[idx--] = nums2[j--];
		}
		//如果nums2有剩余 拷贝
		if (j >= 0)
		{
			memcpy(nums1, nums2,sizeof(int) * (j + 1));
		}
	}
}
//逆序数组
void reverse(int* nums, int start, int end)
{
	while (start < end)
	{
		nums[start] = nums[start] ^ nums[end];
		nums[end] = nums[start] ^ nums[end];
		nums[start] = nums[start] ^ nums[end];
		++start;
		--end;
	}
}
void rotate(int* nums, int numsSize, int k)
{
	k%=numsSize;//防止k大于数组发生越界
	reverse(nums, 0, numsSize - k - 1);
	reverse(nums, numsSize - k, numsSize - 1);
	reverse(nums, 0, numsSize - 1);
}

//5
// 
//对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
//给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。
int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	//计算整数k的位数
	int len = 0;
	int num = K;
	while (num)
	{
		len++;
		num /= 10;
	}
	//申请一个数组
	int arrLen = len > ASize ? len + 1 : ASize + 1;
	int* arr = (int*)malloc(sizeof(int) * arrLen);
	int idx = 0;
	//进位
	int step = 0;
	int end = ASize - 1;
	while (end >= 0 || K > 0)
	{
		//逐位相加 ：上一步进位 + 相想对应的值
		int curSum = step;
		//累加对应的值
		if(end>=0)
		curSum += A[end];
		if (K > 0)
			curSum -= K % 10;
		//判断是否有进位
		if (curSum > 9)
		{
			step = 1;
			//10 ~ 19
			curSum -= 10;
		}
		else
			step = 0;
		//保存当前的值。逆序粗放
		arr[idx++] = curSum;

		end--;
		K /= 10;
	}
	//最高位进位
	if (step == 1)
		arr[idx++] = 1;
	//顺序逆转
	int start = 0;
	end = idx - 1;
	while (start < end)
	{
		int tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;
		end--;
	}
	//保存数组的长度
	*returnSize = idx;
	return arr;
}

