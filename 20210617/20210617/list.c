#include "list.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//��ʼ��һ���յ�˳���
void initseqList(seqList* sl)
{
	if (sl == NULL)
		return;
	sl->_data = NULL;
	sl->_size = 0;
	sl->_capacity = 0;
}
//β��
void seqListpushBack(seqList* sl, SLDataType val)
{
	//if (sl == NULL);
	//   return;
	//seqListCheckCapacit(sl);//����������Է�������
	//sl->_data[sl->_size] = val;
	//sl->_size++;
	seqListInsert(sl, sl->_size, val);
}
//β��ɾ��
void seqListpopBack(seqList* sl)
{
	/*if (sl == NULL)
		return;
	if (sl->_size > 0)
		sl->_size--;*/
	seqListErase(sl, sl->_size - 1);
}

void seqListCheckCapacity(seqList* sl)
{
	if (sl->_size == sl->_capacity)
	{
		int newCapacity = sl->_capacity == 0 ? 1 : 2 * sl->_capacity;
		SLDataType* tmp = (SLDataType*)malloc(newCapacity * sizeof(SLDataType));//һ����1.5 ��2

	//���ݿ������µĿռ�
		memcpy(tmp, sl->_data, sizeof(SLDataType) * sl->_size);
		free(sl->_data);
		sl->_data = tmp;

		/*sl->_data = (SLDataType*)realloc(sl->_data, newCapacity *sizeof(SLDataType));*/
		sl->_capacity = newCapacity;
	}
}


void seqListPrint(seqList* sl)
{
	if (sl == NULL)
		return;
	for (int i = 0; i < sl->_data[i]; i++)
	{
		printf("%d ", sl->_data[i]);
	}
	printf("\n");
}

SLDataType seqListAt(seqList* sl, int pos)
{
	return sl->_data[pos];
}

int seqListEmpty(seqList* sl)
{
	if (sl == NULL || sl->_size == 0)
		return 1;
	else
		return 0;
}

int seqListSize(seqList* sl)
{
	if (sl == NULL)
		return 0;
	else
		return sl->_size;
}
//ͷ������ Ҫ����Ԫ�ص��ƶ� �ƶ���ʱ���ܸ��Ǻ����Ԫ�� ҲҪע���ƶ�Ԫ�صķ��򣨴Ӻ���ǰ�ƶ���
void seqListPushFront(seqList* sl, SLDataType val)
{
	//if (sl == NULL)
	//	return;
	////����ͼ������
	//seqListCheckCapacity(sl);
	////����Ԫ�ص��ƶ�
	//int end = sl->_size;
	//while (end > 0)
	//{
	//	sl->_data[end] = sl->_data[end - 1];
	//	--end;
	//}

	////����
	//sl->_data[0] = val;
	//sl->_size++;
	seqListInsert(sl, 0, val);
}
//ͷ��ɾ��
//Ԫ�ش�ǰ����ƶ�
void seqListPopFront(seqList* sl)
{
	//if (sl == NULL || sl->_size == 0)
	//	return;
	////��ǰ���
	//int start = 1;
	//while (start < sl->_size)
	//{
	//	sl->_data[start - 1] = sl->_data[start];//����
	//	++start;
	//}
	////����size
	//sl->_size--;
	seqListErase(sl, 0);
}

//Ҳ����ʵ��ͷ���β��
void seqListInsert(seqList* sl, int pos, SLDataType val)
{
	if (sl == NULL)
		return;
	seqListCheckCapacity(sl);//����ʱ����
	//�жϷ�Χ
	if (pos >= 0 && pos <= sl->_size)
	{
		int end = sl->_size;
		while (end > pos)
		{
			sl->_data[end] = sl->_data[end - 1];
			--end;
		}
		//��������
		sl->_data[pos] = val;
		++sl->_size;
	}
}
//ɾ������ط�������
void seqListErase(seqList* sl, int pos)
{
	if (sl == NULL || sl->_size == 0)
		return;
	if (0 <= pos && pos < sl->_size)
	{
		//�ƶ�Ԫ�أ�pos,size)
		int start = pos + 1;
		while (start < sl->_size)
		{
			sl->_data[start - 1] = sl->_data[start];
			++start;
		}
		--sl->_size;
	}
}

//����������ֵ
int seqListFind(seqList* sl, SLDataType val)
{

}

//�������һ��Ԫ��
SLDataType seqListBack(seqList* sl)
{
	return sl->_data[sl->_size - 1];
}

//����
void seqListDestroy(seqList* sl)
{
	if (sl == NULL && sl->_data != NULL)
	{
		free(sl->_data);
		sl->_data = NULL;
	}
}
void test()
{
	seqList* psl = (seqList*)malloc(sizeof(seqList));
	initseqList(psl);
	seqListDestroy(psl);
	free(psl);
}
