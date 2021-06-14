#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//直接插入排序
//时间复杂度o(n^2)
void insertSort(int* arr, int n)
{
	//假设第一个数据已经有序
	//未插入的数据就是：[1,n]
	for (int i = 1; i < n; ++i)//未插入的地址就是i
	{
		//从有序数据最后一个数据向前遍历 找到第一个比它小的在后面插入
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] >data)//为了保证稳定性 不要写成>=
		{
			//大的数据向后移动
			arr[end + 1] = arr[end];
			--end;

		}
		arr[end + 1] = data;
	}
}

//希尔排序
//当数据有序时，性能会比直接插入慢一些
//时间复杂度介于n^1.3到n^2之间
// 不稳定
//gap同组数据，相邻位置的间隔
//让数据越来越接近有序，减少数据移动的次数，调高拆入排序的性能

void shellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//最后一趟，间隔必须是1
		//一趟希尔排序
		for (int i = gap; i < n; ++i)
		{
			//同一组数据，最后一个有序数据的位置
			int end = i - gap;
			//待插入的数据
			int data = arr[i];
			while (end >= 0 && arr[end] > data)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}

void testShellSort()
{
	int arr[] = { 10, 1,3, 2, 0, 7, 5, 4, 6, 8, 9 };
	printArr(arr, sizeof(arr) / sizeof(arr[0]));
	shellSort(arr, sizeof(arr) / sizeof(arr[0]));;
	printArr(arr, sizeof(arr) / sizeof(arr[0]));
}

void printArr(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test()
{
	int n;
	printf("数据量： \n");
	scanf("%d", &n);
	srand(time(NULL));
	int* arr = (int*)malloc(sizeof(int) * n);
	int* copy1 = (int*)malloc(sizeof(int) * n);
	int* copy2 = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand();
	}

	memcpy(copy1, arr, sizeof(int) * n);
	memcpy(copy2, arr, sizeof(int) * n);

	time_t begin = clock();
	insertSort(copy1, n);
	time_t end = clock();
	printf("insertSort: %d\n", end - begin);

	begin = clock();
	shellSort(copy2, n);
	end = block();
	printf("shellSort: %d\n", end - begin);
}

//选择排序
// 每一次从未排序中的数据找到最小的，放到数据的头部，再继续执行后

void Swap(int* arr, int n1, int n2)
{
	int tmp = arr[n1];
	arr[n1] = arr[n2];
	arr[n2] = tmp;
}

//时间复杂度o(n^2)
//不稳定

void selectSort(int* arr, int n)
{
	//未排序中找最值，放到为排序的起始位置
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		int minIdx = start;
		int i;
		for (i = start + 1; i <= end; ++i)
		{
			if (arr[i] < arr[minIdx])
				minIdx = i;
		}
		Swap(arr, start, minIdx);
		++start;
	}
}

//堆排序

typedef int HDataType;
typedef struct heap
{
	HDataType* _data;
	int _size;
	int _capacity;
}heap;

//向下调整的过程
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
		Swap(n,&arr[0], &arr[end]);
		shiftDown(arr, end, 0);
		--end;
	}
}

