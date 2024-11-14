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
		HuffmanCode HC;
		int n;
		cout << "请输入叶子结点的个数：\n";
		cin >> n;
		CreateHuffmanTree(HT, n);
		cout << "哈夫曼树创建完成！\n" << endl;
		CreateHuffmanCode(HT, HC, n);
		cout << "哈夫曼编码完成！\n" << endl;
		show_HuffmanCode(HT, HC);
		cout << endl;
		cout << "按任意键继续操作...\n";
		_getch();
		system("cls");
	}
}
