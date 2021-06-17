//�ǵݹ�Ŀ���
//ֱ��
//���ֲ����� ���Եõ�����
//���Զ���һ���ṹ�� ����˳��� ����ջ ���� ���� ֻҪ�����ֵ����䱣�����������˾���

//˳���ʵ��
#include"list.h"

//����ȡ�� ��ȡ��׼ֵ
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
	//��ȡ��׼ֵ��λ��
	int mid = getMid(arr, begin, end);
	//����λ����ԱȽϾ��е�λ��
	Swap(arr, begin, mid);
	//ѡ���׼ֵ
	int key = arr[begin];
	int start = begin;

	while (begin < end)//ֱ��������������
	{
		//�Ӻ���ǰ��С��
		while (begin < end && arr[end] >= key)
			--end;

		//�Ҵ��
		while (begin < end && arr[begin] <= key)
			++begin;

		//����
		Swap(arr, begin, end);
	}
	//����ʱ������׼ֵ������λ�õ�����
	Swap(arr, start, begin);
	return begin;
}

void quickSortNoR(int* arr, int n)
{
	//����һ��˳������ִ����ֵ�����
	seqList sq;
	initseqList(&sq);
	//������������
	//�ȷ����ٷ���  [0, n - 1]
	seqListpushBack(&sq, n - 1);
	seqListpushBack(&sq, 0);

	//����˳���������������
	while (!seqListEmpty(&sq))
	{
		//ȡ��һ������
		int left = seqListBack(&sq);
		seqListpopBack(&sq);
		int right = seqListBack(&sq);
		seqListpopBack(&sq);

		//��������[left,right]
		int div = partion(arr, left, right);


		//���������µ�����
		//[left,div - 1] Ϊ�µ��´λ���   ˵������������Ԫ��
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

//����
void quickSortNoR2(int* arr, int n)
{
	Queue q;
	initQueue(&q);

	//��������
	quequePush(&q, 0);
	quequePush(&q, n - 1);

	//��������
	while (!queueEmpty(&q))
	{
		int left = queueFront(&q);
		queuePop(&q);
		int right = queueFront(&q);
		queuePop(&q);

		//��������[left,right]
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