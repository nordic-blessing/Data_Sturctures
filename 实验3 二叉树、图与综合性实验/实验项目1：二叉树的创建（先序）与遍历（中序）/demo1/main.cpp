/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author ������
 * \date   October 2024
 *********************************************************************/
#include"main.h"

int main() {
	while (1) {
		cout << "�������Ĵ��������������������\n" << endl;
		cout << "������˳�����������������ֵ��һ���ַ���#��ʾ��������" << endl;
		BiTree T;
		CreateBiTree(T);
		cout << "�������\n" << endl;
		cout << "��������Ľ����" << endl;
		PreOrderTraverse(T);
		cout << "\n����������\n";
		cout << "��������Ľ����" << endl;
		InOrderTraverse(T);
		cout << "\n����������\n";
		cout << "��������Ľ��:" << endl;
		PostOrderTraverse(T);
		cout << "\n����������\n";
		cout << endl;
		cout << "���������������...\n";
		_getch();
		system("cls");
	}
}
