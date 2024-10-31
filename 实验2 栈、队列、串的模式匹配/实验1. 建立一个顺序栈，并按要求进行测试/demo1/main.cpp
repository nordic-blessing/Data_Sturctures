/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author ������
 * \date   October 2024
 *********************************************************************/
#include"main.h"

int main() {
	cout << "˳��ջ��ʵ��\n\n";

	SqStack s;
	int choose, flag = 0;
	SElemType j, e, t;
	char i;

	choose = -1;
	while (choose != 0) {
		cout << "1.��ʼ��" << endl;
		cout << "2.��ջ" << endl;
		cout << "3.��ջ" << endl;
		cout << "4.ȡջ��Ԫ��" << endl;
		cout << "5.���ջ������Ԫ��" << endl;
		cout << "0.�˳�" << endl;
		cout << "�����������ţ�";
		cin >> choose;
		switch (choose) {
		case 0:
			break;
		case 1:
			if (InitStack(s)) {
				flag = 1;
				cout << "�ɹ���ջ���г�ʼ��\n\n";
			}
			else {
				cout << "��ʼ��ʧ��\n\n";
			}
			break;
		case 2:
			if (flag) {
				cout << "�������վԪ�أ���#��������\n";
				cin >> j;
				while (j != '#') {
					Push(s, j);
					cout << "Ԫ��" << j << "����ջ\n";
					cin >> j;
				}
				cout << endl;
				if (PrintStack(s));
				else
					return ERROR;
				cout << endl;
			}
			else
				cout << "ջδ��ʼ���������²���\n\n";
			break;
		case 3:
			if (flag) {
				if (Pop(s, t))
					cout << "������Ԫ��Ϊ��" << t << endl;
				else
					cout << "ջ��" << endl;
				cout << endl;
			}
			else
				cout << "ջδ��ʼ���������²���\n\n";
			break;
		case 4:
			if (flag) {
				if (t = GetTop(s))
					cout << "ջ����Ԫ��Ϊ��" << t << endl;
				else
					cout << "ջ��" << endl;
				cout << endl;
			}
			else
				cout << "ջδ��ʼ���������²���\n\n";
			break;
		case 5:
			if (flag) {
				if (PrintStack(s));
				else
					return ERROR;
			}
			else
				cout << "ջδ��ʼ���������²���\n\n";
			break;
		default:
			break;
		}
		cout << "���������������...\n";
		_getch();
		system("cls");
	}
}
