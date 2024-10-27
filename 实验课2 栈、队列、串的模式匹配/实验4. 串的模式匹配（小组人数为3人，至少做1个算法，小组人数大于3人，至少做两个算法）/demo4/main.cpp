/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author 李宇瑞
 * \date   October 2024
 *********************************************************************/
#include"main.h"

int main() {
	while (1) {
		int mode_num = -1;
		SString s, t;
		char s_char[MAXLEN];
		char t_char[MAXLEN];
		cout << "请输入主串：";
		cin >> s_char;
		StrAssign(s_char, s);
		cout << "请输入模式串：";
		cin >> t_char;
		StrAssign(t_char, t);
		cout << "选择匹配模式（0:BF,1:KMP_next,2:KMP_nextval）:";
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
		cout << "按任意键继续操作...";
		_getch();
		system("cls");
	}
}
