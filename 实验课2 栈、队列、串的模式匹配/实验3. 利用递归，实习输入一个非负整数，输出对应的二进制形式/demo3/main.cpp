#include"iostream"
#include"conio.h"
using namespace std;

void conversion(int N) {
	if (N == NULL)
		return;
	conversion(N / 2);
	cout << N % 2;
}

int main() {
	int n;
	while (1) {
		cout << "������Ǹ�ʮ����������";
		cin >> n;
		if (n >= 0)
			conversion(n);
		else
			cout << "������Ǹ�ʮ����������\n";
		cout << endl;
		cout << "���������������...";
		_getch();
		system("cls");
	}
}