#include"main.h"

/**
 * ��������Ǹ�ʮ��������ת��Ϊ�˽���
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
		cout << "������Ǹ�ʮ������ \n";
}

int main() {
	int n;
	while (1) {
		cout << "������һ���Ǹ�ʮ��������";
		cin >> n;
		cout << endl;
		conversion(n);
		cout << "\n�����������..." << endl;
		_getch();
		system("cls");
	}
}
