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
		HuffmanCode HC;
		int n;
		cout << "������Ҷ�ӽ��ĸ�����\n";
		cin >> n;
		CreateHuffmanTree(HT, n);
		cout << "��������������ɣ�\n" << endl;
		CreateHuffmanCode(HT, HC, n);
		cout << "������������ɣ�\n" << endl;
		show_HuffmanCode(HT, HC);
		cout << endl;
		cout << "���������������...\n";
		_getch();
		system("cls");
	}
}
