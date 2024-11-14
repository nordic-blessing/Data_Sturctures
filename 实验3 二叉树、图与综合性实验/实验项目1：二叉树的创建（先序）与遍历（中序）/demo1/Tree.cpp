/*****************************************************************//**
 * \file   Tree.cpp
 * \brief  
 * 
 * \author 李宇瑞
 * \date   October 2024
 *********************************************************************/
#include"Tree.h"

/**
 * 先序遍历顺序创建二叉链表表示二叉树.
 * @param T
 */
void CreateBiTree(BiTree& T) {
	TElemType ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else {
		T = new BiTNode;
		T->data = ch;
		cout << "递归调用CreateBiTree(T->lchild)，建" << T->data << "左子树" << endl;
		CreateBiTree(T->lchild);
		cout << "递归调用CreateBiTree(T->rchild)，建" << T->data << "右子树" << endl;
		CreateBiTree(T->rchild);
	}
}

/**
 * 先序遍历二叉树.
 * @param T
 */
void PreOrderTraverse(BiTree T) {
	if (T) {
		cout << T->data;			//访问根结点
		PreOrderTraverse(T->lchild);//先序遍历左子树
		PreOrderTraverse(T->rchild);//先序遍历右子树
	}
}

/**
 * 中序遍历二叉树.
 * @param T
 */
void InOrderTraverse(BiTree T) {
	if (T) {
		InOrderTraverse(T->lchild);	//中序遍历左子树
		cout << T->data;			//访问根结点
		InOrderTraverse(T->rchild);	//中序遍历右子树
	}
}

/**
 * 后序遍历二叉树.
 * @param T
 */
void PostOrderTraverse(BiTree T) {
	if (T) {
		PostOrderTraverse(T->lchild);//后序遍历左子树
		PostOrderTraverse(T->rchild);//后序遍历右子树
		cout << T->data;			//访问根结点
	}
}

/**
 * 复制二叉树.
 * @param T
 * @param NewT
 */
void Copy(BiTree T, BiTree& NewT) {
	if (T == NULL) {
		NewT = NULL;
		return;
	}else {
		NewT = new BiTNode;
		NewT->data = T->data;
		Copy(T->lchild, NewT->lchild);
		Copy(T->rchild, NewT->rchild);
	}
}

/**
 * 计算二叉树的深度.
 * @param T
 * @return 返回二叉树的深度
 */
int Depth(BiTree T) {
	if (T == NULL)
		return 0;
	else {
		int m = Depth(T->lchild);
		int n = Depth(T->rchild);
		if (m > n)
			return (m + 1);
		else
			return (n + 1);
	}
}

/**
 * 统计二叉树中结点的个数.
 * @param T
 * @return 返回结点个数
 */
int NodeCount(BiTree T) {
	if (T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}
