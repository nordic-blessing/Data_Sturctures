/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author 李宇瑞
 * \date   October 2024
 *********************************************************************/
#include"main.h"

int main() {
	cout << "顺序栈的实现\n\n";

	SqStack s;
	int choose, flag = 0;
	SElemType j, e, t;
	char i;

	choose = -1;
	while (choose != 0) {
		cout << "1.初始化" << endl;
		cout << "2.入栈" << endl;
		cout << "3.出栈" << endl;
		cout << "4.取栈顶元素" << endl;
		cout << "5.输出栈内所有元素" << endl;
		cout << "0.退出" << endl;
		cout << "请输入操作编号：";
		cin >> choose;
		switch (choose) {
		case 0:
			break;
		case 1:
			if (InitStack(s)) {
				flag = 1;
				cout << "成功对栈进行初始化\n\n";
			}
			else {
				cout << "初始化失败\n\n";
			}
			break;
		case 2:
			if (flag) {
				cout << "请输入进站元素（以#结束）：\n";
				cin >> j;
				while (j != '#') {
					Push(s, j);
					cout << "元素" << j << "已入栈\n";
					cin >> j;
				}
				cout << endl;
				if (PrintStack(s));
				else
					return ERROR;
				cout << endl;
			}
			else
				cout << "栈未初始化，请重新操作\n\n";
			break;
		case 3:
			if (flag) {
				if (Pop(s, t))
					cout << "弹出的元素为：" << t << endl;
				else
					cout << "栈空" << endl;
				cout << endl;
			}
			else
				cout << "栈未初始化，请重新操作\n\n";
			break;
		case 4:
			if (flag) {
				if (t = GetTop(s))
					cout << "栈顶的元素为：" << t << endl;
				else
					cout << "栈空" << endl;
				cout << endl;
			}
			else
				cout << "栈未初始化，请重新操作\n\n";
			break;
		case 5:
			if (flag) {
				if (PrintStack(s));
				else
					return ERROR;
			}
			else
				cout << "栈未初始化，请重新操作\n\n";
			break;
		default:
			break;
		}
		cout << "按任意键继续操作...\n";
		_getch();
		system("cls");
	}
}
