/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author ������
 * \date   October 2024
 *********************************************************************/
#include"main.h"

int main() {
	while (1) {
		int mode_num = -1;
		SString s, t;
		char s_char[MAXLEN];
		char t_char[MAXLEN];
		cout << "������������";
		cin >> s_char;
		StrAssign(s_char, s);
		cout << "������ģʽ����";
		cin >> t_char;
		StrAssign(t_char, t);
		cout << "ѡ��ƥ��ģʽ��0:BF,1:KMP_next,2:KMP_nextval��:";
		cin >> mode_num;
		switch (mode_num)
		{
		case 0:
			cout << Index_BF(s, t, 1) << endl;
			break;
		case 1:
			cout << Index_KMP(s, t, 1, 1) << endl;
			break;
		case 2:
			cout << Index_KMP(s, t, 1, 2) << endl;
			break;
		default:
			break;
		}
		cout << endl;
		cout << "���������������...";
		_getch();
		system("cls");
	}
}
