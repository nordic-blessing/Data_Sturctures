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
		CreateUDN(G);
		cout << endl;
		showUDN(G);
		cout << endl;
		cout << "���������������..." << endl;
		_getch();
		system("cls");
	}
}
