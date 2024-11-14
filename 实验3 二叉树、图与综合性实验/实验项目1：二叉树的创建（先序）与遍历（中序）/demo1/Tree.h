/*****************************************************************//**
 * \file   Tree.h
 * \brief  
 * 
 * \author 李宇瑞
 * \date   October 2024
 *********************************************************************/
#ifndef __TREE_H__
#define __TREE_H__

#include"main.h"

#define TElemType	char


//============二叉树的顺序存储结构============//
#define MAXSIZE		100
typedef TElemType	SqBiTree[MAXSIZE];

//============二叉树的链式存储结构============//
typedef struct BiTNode{
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

//==============二叉树的相关操作==============//
void CreateBiTree(BiTree &T);
void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);
void Copy(BiTree T, BiTree& NewT);
int Depth(BiTree T);
int NodeCount(BiTree T);

#endif // !__TREE_H__
