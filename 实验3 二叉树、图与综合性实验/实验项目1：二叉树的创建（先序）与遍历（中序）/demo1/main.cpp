/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author 李宇瑞
 * \date   October 2024
 *********************************************************************/
#include"main.h"

int main() {
	while (1) {
		cout << "二叉树的创建（先序）与遍历（中序）\n" << endl;
		cout << "按先序顺序输入二叉树各结点的值（一个字符，#表示空树）：" << endl;
		BiTree T;
		CreateBiTree(T);
		cout << "建树完成\n" << endl;
		cout << "先序遍历的结果：" << endl;
		PreOrderTraverse(T);
		cout << "\n先序遍历完成\n";
		cout << "中序遍历的结果：" << endl;
		InOrderTraverse(T);
		cout << "\n中序遍历完成\n";
		cout << "后序遍历的结果:" << endl;
		PostOrderTraverse(T);
		cout << "\n后序遍历完成\n";
		cout << endl;
		cout << "按任意键继续操作...\n";
		_getch();
		system("cls");
	}
}
