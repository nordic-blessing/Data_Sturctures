/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author ������
 * \date   November 2024
 *********************************************************************/
#include"main.h"

int main() {
	while (1) {
		HuffmanTree HT;
		int n;
		cout << "������Ҷ�ӽ��ĸ�����\n";
		cin >> n;
		CreateHuffmanTree(HT, n);
		cout << "��������������ɣ�\n" << endl;
		cout << "����������Ϊ��" << endl;
		PreOrderTraverse_HT(HT, 2 * n - 1);
		cout << "\n����������\n";
		cout << endl;
		cout << "���������������...\n";
		_getch();
		system("cls");
	}
}
