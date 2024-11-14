#include"main.h"

int main() {
	while (1) {
		AMGraph G;
		char start,final;
		CreateDN(G);
		cout << endl;
		showUDN(G);
		cout << endl;
		while (1) {
			cout << "请输入起点：";
			cin >> start;
			ShortestPath_DIJ(G, Locate_Vex(G, start));
			cout << endl;
			while (1) {
				cout << "请输入终点：";
				cin >> final;
				int i = show_ShortestPath(G, Locate_Vex(G, final));
				cout << endl;
				if (i != -1)
					cout << "最短路径的距离为：" << i << endl;
				else
					cout << "不存在该路线" << endl;
			}
		}
		cout << "按任意键继续操作..." << endl;
		_getch();
		system("cls");
	}
}
