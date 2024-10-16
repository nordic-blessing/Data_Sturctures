#include"main.h"

/**
 * 输入任意非负十进制数，转换为八进制
 * @param N
 */
void conversion(int N) {
	int e;
	LinkStack S;
	
	if (N >= 0) {
		InitStack(S);
		e = N;
		do{
			Push(S, N % 8);
			N /= 8;
		} while (N);
		while (Pop(S, e)) {
			cout << e;
		}
		cout << endl;
	}
	else
		cout << "请输入非负十进制数 \n";
}

int main() {
	int n;
	while (1) {
		cout << "请输入一个非负十进制数：";
		cin >> n;
		cout << endl;
		conversion(n);
		cout << "\n按任意键继续..." << endl;
		_getch();
		system("cls");
	}
}
