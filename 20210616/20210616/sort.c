#include<stdio.h>

//�ڿӷ���������

//void Swap(int* arr, int n1, int n2)
//{
//	int tmp = arr[n1];
//	arr[n1] = arr[n2];
//	arr[n2] = tmp;
//}
//
////����ȡ�� ��ȡ��׼ֵ
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
////���ػ�׼ֵ��λ�� 
//int partion(int* arr, int begin, int end)
//{
//	int mid = getMid(arr, begin, end);
//	Swap(arr, begin, end);
//
//	//��һ��ֵ��Ϊ��׼ֵ����һ��λ�þ��ǵ�һ����
//	int key = arr[begin];
//	while (begin < end)
//	{
//		//�Ӻ���ǰ��С��
//		while (begin < end && arr[end] >= key)
//			--end;
//
//		//���
//		arr[begin] = arr[end];
//
//		//��ǰ����Ҵ��
//		while (begin < end && arr[begin] <= key)
//			++begin;
//		//���
//		arr[end] = arr[begin];
//	}
//	//����ʱ ���ֵ����Ϊ��׼ֵ
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


//ǰ��ָ�뷨
// prev��һ��С�ڻ�׼ֵ��λ��
// cur ��һ��С�ڻ�׼ֵ��λ��
// ��cur�ҵ�һ��С�ڻ�׼ֵ��λ��
// �ж��������Ƿ����� ���ǿ��м仹��û��Ԫ��
// ������� �����ڶ��ǲ����ڻ�׼ֵ ����������ֵ
// ��������� ����cur��prev����һ��ֵ���� Ȼ�����cur ��������
// ֱ��cur���� Ȼ��Ƚ�prev�ͻ�׼ֵ��ֵ ���н��� �����˻�׼ֵ��λ��
//����һ��
void Swap(int* arr, int n1, int n2)
{
	int tmp = arr[n1];
	arr[n1] = arr[n2];
	arr[n2] = tmp;
}

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
	int mid = getMid(arr, begin, end);
	Swap(arr, mid, begin);

	int prev = begin;
	int cur = cur + 1;
	int key = arr[begin];
	while (arr <= end)
	{
		//cur�ߵ�λ�ã��ж��Ƿ�����
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



