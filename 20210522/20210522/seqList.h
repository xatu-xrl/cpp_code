#pragma once
//顺序表
//顺序表是用一段物理地址连续的存储单元依次存储数据元素的线性结构，一般情况下采用数组存储。在数组
//上完成数据的增删查改。
//顺序表一般可以分为：
//1. 静态顺序表：使用定长数组存储。
//2. 动态顺序表：使用动态开辟的数组存储。
//静态
typedef int SLDataType;
#define N 100
struct seqList2
{
	SLDataType _data[N];//定长数组
	int _size;//有效个数
};

//动态
typedef struct seqList
{
	SLDataType* _data;//数组指针
	int _size;//有效个数
	int _capacity;//数组的空间
}seqList;

//初始化顺序表
void initseqList(seqList* sl);
//插入
//末尾插入,最后一个有效数据的末尾插入新的数据
void seqListpushBack(seqList* sl, SLDataType val);
//尾部删除
void seqListpopBack(seqList* sl);
//检查容量
void seqListCheckCapacity(seqList* sl);
//打印顺序表
void seqListPrint(seqList* sl);
//访问
SLDataType seqListAt(seqList* sl, int pos);
//判断是不是空的顺序表
int seqListEmpty(seqList* sl);

int seqListSize(seqList* sl);
//头部插入
void seqListPushFront(seqList* sl, SLDataType val);
//头部删除
void seqListPopFront(seqList* sl);
//任意插入
void seqListInsert(seqList* sl, int pos, SLDataType val);
//任意删除
void seqListErase(seqList* sl, int pos);
//查找任意数值
int seqListFind(seqList* sl, SLDataType val);
//销毁
void seqListDestroy(seqList* sl);