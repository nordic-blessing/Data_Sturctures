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
		cout << "请输入非负十进制整数：";
		cin >> n;
		if (n >= 0)
			conversion(n);
		else
			cout << "请输入非负十进制整数！\n";
		cout << endl;
		cout << "按任意键继续操作...";
		_getch();
		system("cls");
	}
}