#include <iostream>
using namespace std;

void reverse(int a[], int n);

int main() {
	
	const int N = 5;
	int a[N];
	int i;
	cout << "������" << N << "�����֣�" << endl;
	for (i = 0; i < N; i++) {
		cin >> a[i];
	}

	cout << endl;

	reverse(a, N);

	cout << "���������Ľ����" << endl;
	for (i = 0; i < N; i++) {
		cout << a[i] << " ";
	}

	return 0;
}

void reverse(int a[], int n) {
	int i, temp, m;
	m = n / 2;
	for (i = 0; i < m; i++)
	{
		temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
	}
}