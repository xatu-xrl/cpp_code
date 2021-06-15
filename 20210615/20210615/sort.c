#include<stdio.h>
//��������
//�������� ����
//horae ѡһ����׼ֵ��һ���ǵ�һ����Ҳ����ѡ�м�λ�� ��ֹ���� ���ܼ����˻� ��ʣ��Ԫ���п�ʼ���� һ�������ܽ���˳��
// ����ǵݼ�˳��Ļ�  1.�Ӻ���ǰ�Ҵ��  2.
//1.�Ӻ���ǰ�ҵ���һ��С�ڻ�׼ֵ������
//2.��ǰ�����ҵ���һ�����ڻ�׼ֵ������
//3.��������ֵ
//4.������ ��������
//5.������λ�úͻ�׼ֵ����

//��������  ���ػ�������֮�� ��׼ֵ���ڵ�λ��

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

//���ȶ�������
//��������ʱ�����ܻᵼ��ջ��� on^2
void quickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//�ҵ��˻�׼ֵ���ڵ�λ��
	int div = partion(arr, begin, end);
	//���������ֽ��п�������
	//[beigin, div - 1]
	//[div + 1, end]
	quickSort(arr, begin, div);
	quickSort(arr, div + 1, end);

}