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
			cout << "��������㣺";
			cin >> start;
			ShortestPath_DIJ(G, Locate_Vex(G, start));
			cout << endl;
			while (1) {
				cout << "�������յ㣺";
				cin >> final;
				int i = show_ShortestPath(G, Locate_Vex(G, final));
				cout << endl;
				if (i != -1)
					cout << "���·���ľ���Ϊ��" << i << endl;
				else
					cout << "�����ڸ�·��" << endl;
			}
		}
		cout << "���������������..." << endl;
		_getch();
		system("cls");
	}
}
