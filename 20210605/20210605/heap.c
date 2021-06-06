#include<stdio.h>
#include<stdlib.h>
//������������
//1. ���涨���ڵ�Ĳ���Ϊ1����һ�÷ǿն������ĵ�i���������2 ^ (i - 1) �����.
//2. ���涨���ڵ�Ĳ���Ϊ1�������Ϊh�Ķ����������������2 ^ h - 1.
//3. ���κ�һ�ö�����, �����Ϊ0��Ҷ������Ϊ n0, ��Ϊ2�ķ�֧������Ϊ n2, ����n0��n2��1
//4. ���涨���ڵ�Ĳ���Ϊ1������n������������������ȣ�h = Log2(n + 1). (ps��Log2(n + 1)��log��2Ϊ
//�ף�n + 1Ϊ����)
//
// 5. ���ھ���n��������ȫ��������������մ������´������ҵ�����˳������нڵ��0��ʼ��ţ����
//�����Ϊi�Ľ���У�
//	1. ��i > 0��iλ�ýڵ��˫����ţ�(i - 1) / 2��i = 0��iΪ���ڵ��ţ���˫�׽ڵ�
//	2. ��2i + 1 < n��������ţ�2i + 1��2i + 1 >= n����������
//	3. ��2i + 2 < n���Һ�����ţ�2i + 2��2i + 2 >= n�������Һ���

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

//����ΪС�� ���µ����Ĺ���
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

//���ϵ���logn�Ĳ���
void shiftUp(int* arr, int n, int cur)
{
	//���ڵ��λ��
	int parent = (cur - 1) / 2;
	while (cur > 0)
	{
		//�Ƚ�
		if (arr[cur] < arr[parent])
		{
			int tmp = arr[cur];
			arr[cur] = arr[parent];
			arr[parent];

			//���µ����ڵ��λ�� �������ϸ���
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
	//�������  β�� ���ϵ���
	checkCapacity(hp);

	hp->_data[hp->_size] = val;
	shiftUp(hp->_data, hp->_size, hp->_size - 1);
	hp->_size++;
}

//С��->��� �����ӽṹ�����Ǵ�� �����������������Ƕ�
//�������ϵ���
//�����һ����Ҷ�ӽ�㿪ʼ���� ���ǵ����ڶ�������һ�� ��n-2��/2
//���µ����Ĵ����ͷ�Ҷ�ӽڵ�ĸ�����ͬ

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

//�Ѷ������һ��Ҷ�ӽ��н���
//β��ɾ��
//��0���µ���
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