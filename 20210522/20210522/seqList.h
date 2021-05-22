#pragma once
//˳���
//˳�������һ�������ַ�����Ĵ洢��Ԫ���δ洢����Ԫ�ص����Խṹ��һ������²�������洢��������
//��������ݵ���ɾ��ġ�
//˳���һ����Է�Ϊ��
//1. ��̬˳���ʹ�ö�������洢��
//2. ��̬˳���ʹ�ö�̬���ٵ�����洢��
//��̬
typedef int SLDataType;
#define N 100
struct seqList2
{
	SLDataType _data[N];//��������
	int _size;//��Ч����
};

//��̬
typedef struct seqList
{
	SLDataType* _data;//����ָ��
	int _size;//��Ч����
	int _capacity;//����Ŀռ�
}seqList;

//��ʼ��˳���
void initseqList(seqList* sl);
//����
//ĩβ����,���һ����Ч���ݵ�ĩβ�����µ�����
void seqListpushBack(seqList* sl, SLDataType val);
//β��ɾ��
void seqListpopBack(seqList* sl);
//�������
void seqListCheckCapacity(seqList* sl);
//��ӡ˳���
void seqListPrint(seqList* sl);
//����
SLDataType seqListAt(seqList* sl, int pos);
//�ж��ǲ��ǿյ�˳���
int seqListEmpty(seqList* sl);

int seqListSize(seqList* sl);
//ͷ������
void seqListPushFront(seqList* sl, SLDataType val);
//ͷ��ɾ��
void seqListPopFront(seqList* sl);
//�������
void seqListInsert(seqList* sl, int pos, SLDataType val);
//����ɾ��
void seqListErase(seqList* sl, int pos);
//����������ֵ
int seqListFind(seqList* sl, SLDataType val);
//����
void seqListDestroy(seqList* sl);