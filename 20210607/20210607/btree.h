#pragma once
typedef char DataType;
//��������㣺������
typedef struct BNode
{
	struct BNode* _left;
	struct BNOde* _right;
	DataType _data;
}Node;