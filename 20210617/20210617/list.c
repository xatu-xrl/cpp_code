#include "list.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//初始化一个空的顺序表
void initseqList(seqList* sl)
{
	if (sl == NULL)
		return;
	sl->_data = NULL;
	sl->_size = 0;
	sl->_capacity = 0;
}
//尾插
void seqListpushBack(seqList* sl, SLDataType val)
{
	//if (sl == NULL);
	//   return;
	//seqListCheckCapacit(sl);//检查容量可以放数据吗
	//sl->_data[sl->_size] = val;
	//sl->_size++;
	seqListInsert(sl, sl->_size, val);
}
//尾部删除
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
		SLDataType* tmp = (SLDataType*)malloc(newCapacity * sizeof(SLDataType));//一般是1.5 ，2

	//数据拷贝到新的空间
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
//头部插入 要考虑元素的移动 移动的时候不能覆盖后面的元素 也要注意移动元素的方向（从后向前移动）
void seqListPushFront(seqList* sl, SLDataType val)
{
	//if (sl == NULL)
	//	return;
	////插入就检查容量
	//seqListCheckCapacity(sl);
	////进行元素的移动
	//int end = sl->_size;
	//while (end > 0)
	//{
	//	sl->_data[end] = sl->_data[end - 1];
	//	--end;
	//}

	////插入
	//sl->_data[0] = val;
	//sl->_size++;
	seqListInsert(sl, 0, val);
}
//头部删除
//元素从前向后移动
void seqListPopFront(seqList* sl)
{
	//if (sl == NULL || sl->_size == 0)
	//	return;
	////从前向后
	//int start = 1;
	//while (start < sl->_size)
	//{
	//	sl->_data[start - 1] = sl->_data[start];//覆盖
	//	++start;
	//}
	////更新size
	//sl->_size--;
	seqListErase(sl, 0);
}

//也可以实现头插和尾插
void seqListInsert(seqList* sl, int pos, SLDataType val)
{
	if (sl == NULL)
		return;
	seqListCheckCapacity(sl);//插入时增容
	//判断范围
	if (pos >= 0 && pos <= sl->_size)
	{
		int end = sl->_size;
		while (end > pos)
		{
			sl->_data[end] = sl->_data[end - 1];
			--end;
		}
		//插入数据
		sl->_data[pos] = val;
		++sl->_size;
	}
}
//删除任意地方的数据
void seqListErase(seqList* sl, int pos)
{
	if (sl == NULL || sl->_size == 0)
		return;
	if (0 <= pos && pos < sl->_size)
	{
		//移动元素（pos,size)
		int start = pos + 1;
		while (start < sl->_size)
		{
			sl->_data[start - 1] = sl->_data[start];
			++start;
		}
		--sl->_size;
	}
}

//查找任意数值
int seqListFind(seqList* sl, SLDataType val)
{

}

//访问最后一个元素
SLDataType seqListBack(seqList* sl)
{
	return sl->_data[sl->_size - 1];
}

//销毁
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
