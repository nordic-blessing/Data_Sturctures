/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author 李宇瑞
 * \date   November 2024
 *********************************************************************/
#include"main.h"

int main() {
	while (1) {
		HuffmanTree HT;
		int n;
		cout << "请输入叶子结点的个数：\n";
		cin >> n;
		CreateHuffmanTree(HT, n);
		cout << "哈夫曼树创建完成！\n" << endl;
		cout << "先序遍历结果为：" << endl;
		PreOrderTraverse_HT(HT, 2 * n - 1);
		cout << "\n先序遍历完成\n";
		cout << endl;
		cout << "按任意键继续操作...\n";
		_getch();
		system("cls");
	}
}
