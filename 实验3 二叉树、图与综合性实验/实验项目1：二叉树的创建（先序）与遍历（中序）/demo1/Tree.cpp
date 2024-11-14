/*****************************************************************//**
 * \file   Tree.cpp
 * \brief  
 * 
 * \author ������
 * \date   October 2024
 *********************************************************************/
#include"Tree.h"

/**
 * �������˳�򴴽����������ʾ������.
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
		cout << "�ݹ����CreateBiTree(T->lchild)����" << T->data << "������" << endl;
		CreateBiTree(T->lchild);
		cout << "�ݹ����CreateBiTree(T->rchild)����" << T->data << "������" << endl;
		CreateBiTree(T->rchild);
	}
}

/**
 * �������������.
 * @param T
 */
void PreOrderTraverse(BiTree T) {
	if (T) {
		cout << T->data;			//���ʸ����
		PreOrderTraverse(T->lchild);//�������������
		PreOrderTraverse(T->rchild);//�������������
	}
}

/**
 * �������������.
 * @param T
 */
void InOrderTraverse(BiTree T) {
	if (T) {
		InOrderTraverse(T->lchild);	//�������������
		cout << T->data;			//���ʸ����
		InOrderTraverse(T->rchild);	//�������������
	}
}

/**
 * �������������.
 * @param T
 */
void PostOrderTraverse(BiTree T) {
	if (T) {
		PostOrderTraverse(T->lchild);//�������������
		PostOrderTraverse(T->rchild);//�������������
		cout << T->data;			//���ʸ����
	}
}

/**
 * ���ƶ�����.
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
 * ��������������.
 * @param T
 * @return ���ض����������
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
 * ͳ�ƶ������н��ĸ���.
 * @param T
 * @return ���ؽ�����
 */
int NodeCount(BiTree T) {
	if (T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}
