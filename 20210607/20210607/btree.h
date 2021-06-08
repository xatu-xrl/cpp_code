#pragma once
typedef char DataType;
//二叉树结点：二叉链
typedef struct BNode
{
	struct BNode* _left;
	struct BNOde* _right;
	DataType _data;
}Node;