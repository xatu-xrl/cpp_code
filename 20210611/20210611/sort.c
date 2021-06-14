#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//ֱ�Ӳ�������
//ʱ�临�Ӷ�o(n^2)
void insertSort(int* arr, int n)
{
	//�����һ�������Ѿ�����
	//δ��������ݾ��ǣ�[1,n]
	for (int i = 1; i < n; ++i)//δ����ĵ�ַ����i
	{
		//�������������һ��������ǰ���� �ҵ���һ������С���ں������
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] >data)//Ϊ�˱�֤�ȶ��� ��Ҫд��>=
		{
			//�����������ƶ�
			arr[end + 1] = arr[end];
			--end;

		}
		arr[end + 1] = data;
	}
}

//ϣ������
//����������ʱ�����ܻ��ֱ�Ӳ�����һЩ
//ʱ�临�ӶȽ���n^1.3��n^2֮��
// ���ȶ�
//gapͬ�����ݣ�����λ�õļ��
//������Խ��Խ�ӽ����򣬼��������ƶ��Ĵ��������߲������������

void shellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//���һ�ˣ����������1
		//һ��ϣ������
		for (int i = gap; i < n; ++i)
		{
			//ͬһ�����ݣ����һ���������ݵ�λ��
			int end = i - gap;
			//�����������
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
	printf("�������� \n");
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

//ѡ������
// ÿһ�δ�δ�����е������ҵ���С�ģ��ŵ����ݵ�ͷ�����ټ���ִ�к�

void Swap(int* arr, int n1, int n2)
{
	int tmp = arr[n1];
	arr[n1] = arr[n2];
	arr[n2] = tmp;
}

//ʱ�临�Ӷ�o(n^2)
//���ȶ�

void selectSort(int* arr, int n)
{
	//δ����������ֵ���ŵ�Ϊ�������ʼλ��
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

//������

typedef int HDataType;
typedef struct heap
{
	HDataType* _data;
	int _size;
	int _capacity;
}heap;

//���µ����Ĺ���
void shiftDown(int* arr, int n, int curPos)//�����ָ�� ��С ��ǰ��Ҫ������λ��
{
	//�����Һ���������С��
	//����λ�� 2*curse + 1 ��Ŵ�0��ʼ
	//�ڱȽϺ���Ҫ��ֵ���бȽ�
	int child = 2 * curPos + 1;
	while (child < n)//�����Ǵ��ڵ�
	{
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		if (arr[child < arr[curPos]])
		{
			int tmp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = tmp;
			//����ִ�дӵ�ǰ������λ�ý��в���
			curPos = child;
			child = 2 * curPos + 1;
		}
		else
			break;
	}
}

//�������� ��������ôд
void test()
{
	int arr[] = { 20,17,4,16,5,3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//����o��n��
	for (int i = (n - 2 / 2); i >= 0; --i)
	{
		shiftDown(arr, n, i);
	}
	//������o��logn��
	int end = n - 1;
	while (end > 0)
	{
		//ɾ���Ĺ���
		Swap(n,&arr[0], &arr[end]);
		shiftDown(arr, end, 0);
		--end;
	}
}

