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
		AMGraph G;
		char start;
		CreateUDN(G);
		cout << endl;
		showUDN(G);
		cout << endl;
		cout << "���������ͼ����ʼ�㣺";
		cin >> start;
		DFS_AM(G, Locate_Vex(G,start));
		cout << endl;
		cout << "���������������..." << endl;
		_getch();
		system("cls");
	}
}
