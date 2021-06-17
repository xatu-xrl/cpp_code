typedef int SLDataType;
#define N 100
struct seqList
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

//访问最后一个元素
SLDataType seqListBack(seqList* sl);

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