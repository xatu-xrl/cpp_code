#include<stdio.h>
#include<string.h>

//�鲢
//���������кϲ� begin end end+1  end2

//beigin  mid     end 
void merge(int* arr, int begin, int mid, int end, int* tmp)//tmp�����ռ�
{
	//��������
	//������[ begin1 mid ]  [ mid + 1  end]
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	int idx = begin;

	//�ϲ���������
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])//С�ڵ��ھ����ȶ���
			tmp[idx++] = arr[begin1++];
		else
			tmp[idx++] = arr[begin2++];
	}
	//�ж��Ƿ���δ�ϲ���Ԫ�� ���ǵ���������� ��������治�ô���
	if (begin1 <= end1)
		memcpy(tmp + idx, arr + begin1, sizeof(int) * (end1 - begin1 + 1));
	if(begin2 <= end)
		memcpy(tmp + idx, arr + begin2, sizeof(int) * (end2 - begin2 + 1));

	//�ϲ���Ԫ�ؿ���ԭʼ�����Ӧ������
	memcpy(arr + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void _mergeSort(int* arr, int begin, int end, int* tmp)
{
	if(begin >= end)
		return;
	int mid = begin + (end - begin) / 2;

	//�ϲ�������
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr,  mid + 1, end, tmp);

	//�ϲ����������������
	merge(arr, begin, mid, end, tmp);
}

void mergeSort(int* arr, int n)
{
	//���븨���ռ�
	int* tmp = (int*)malloc(sizeof(int) * n);
	_mergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}




//�ǵݹ�д��  �Լ��������� 

//Ҫ�ϲ��ĵ�һ������
// begin:idx
// end:idx + step - 1
// Ҫ�ϲ��ĵڶ�������
// begin:idx + step
// end:idx + 2*step - 1
// 
// idx += 2*step
// 
//step * = 2

void mergeSortNoR(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	//�Ե����ϵĹ���
	int step = 1;
	while (step < n)
	{
		for (int idx = 0; idx < n; idx += 2 * step)
		{
			//�ҵ��������ϲ�������������
			//[begin, mid] [mid + 1, end]
			int begin = idx;
			int mid = idx + step - 1;
			//�ж��Ƿ���ڵڶ��������� �����������
			if (mid >= n - 1)
				//�����ڵڶ���������
				continue;
			int end = idx + 2 * step - 1;
			//�жϵڶ������������Ƿ�Խ��
			if (end > n)
				end = n - 1;
			merge(arr, begin, mid, end, tmp);
		}

		//���²���
		step *= 2;
	}
}

//�ǱȽ�����
//�ռ临�Ӷ� ��
void countSort(int* arr, int n)
{
	//���ҵ���ֵ
	int max, min;
	min = max = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[min];
	}
	//���㷶Χ ��ʡ�ռ�
	int range = max - min + 1;
	int* countArr = (int*)calloc(range, sizeof(int));//��ɳ�ʼ��

	//����
	for (int i = 0; i < n; ++i)
	{
		countArr[arr[i] - min]++;
	}

	//���� ��������
	int idx = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArr[i]--)
		{
			arr[idx++] = i + min;
		}
	}
}