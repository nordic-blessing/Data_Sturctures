/*****************************************************************//**
 * \file   Tree.h
 * \brief  
 * 
 * \author ������
 * \date   October 2024
 *********************************************************************/
#ifndef __TREE_H__
#define __TREE_H__

#include"main.h"

#define TElemType	char


//============��������˳��洢�ṹ============//
#define MAXSIZE		100
typedef TElemType	SqBiTree[MAXSIZE];

//============����������ʽ�洢�ṹ============//
typedef struct BiTNode{
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

//==============����������ز���==============//
void CreateBiTree(BiTree &T);
void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);
void Copy(BiTree T, BiTree& NewT);
int Depth(BiTree T);
int NodeCount(BiTree T);

#endif // !__TREE_H__
