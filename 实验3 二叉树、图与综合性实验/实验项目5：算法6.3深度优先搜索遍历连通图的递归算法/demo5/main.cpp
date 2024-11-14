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
		char start;
		CreateUDN(G);
		cout << endl;
		showUDN(G);
		cout << endl;
		cout << "请输入遍历图的起始点：";
		cin >> start;
		DFS_AM(G, Locate_Vex(G,start));
		cout << endl;
		cout << "按任意键继续操作..." << endl;
		_getch();
		system("cls");
	}
}
