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
		AMGraph G;
		CreateUDN(G);
		cout << endl;
		showUDN(G);
		cout << endl;
		cout << "按任意键继续操作..." << endl;
		_getch();
		system("cls");
	}
}
