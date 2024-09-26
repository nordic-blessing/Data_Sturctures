#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -1

#define Status int
#define ElemType Student

typedef struct {
	int Snumber;	//学号
	string name;	//姓名
	string major;	//专业
}Student;

typedef struct LNode {
	Student data;
	struct LNode* next;
}LNode, * LinkList;

/**
* CreateLList_H		前插法创建单链表
* @param L			单链表L
* @param n			链表最大长度
* @return			Status
*/
Status CreateList_H(LinkList& L, int n) {
	L = new LNode;
	if (!L)
		return ERROR;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		LNode* p;

		cout << "前插法创建单链表 \n\n";
		cout << "请输入 学号 姓名 专业 （空格间隔，回车输入，0退出）：\n\n";

		while (n) {
			p = new LNode;
			if (!p)
				return ERROR;

			cin >> p->data.Snumber;
			if (!cin) {
				cout << "学号输入错误，请重新输入\n";
				cin.clear();
				cin.ignore(500, '\n');
				continue;
			}
			if (p->data.Snumber == 0)
				break;

			cin >> p->data.name;
			if (!cin) {
				cout << "姓名输入错误，请重新输入\n";
				cin.clear();
				cin.ignore(500, '\n');
				continue;
			}
			if (p->data.name == "0")
				break;

			cin >> p->data.major;
			if (!cin) {
				cout << "专业输入错误，请重新出入\n";
				cin.clear();
				cin.ignore(500, '\n');
				continue;
			}
			if (p->data.major == "0")
				break;

			p->next = L->next;
			L->next = p;

			n--;
		}
		if (!n)
			cout << "\n建表完成！\n";
		else
			cout << "\n退出，未完成建表！\n";
		return OK;
	}
}

/**
* CreateList_R		后插法创建单链表
* @param L			单链表L
* @param n			链表的最大长度
* @return			Status
*/
Status CreateList_R(LinkList& L, int n) {
	L = new LNode;
	if (!L)
		return ERROR;
	L->next = NULL;

	LNode* p, * r;
	r = L;

	cout << "后插法创建单链表 \n\n";
	cout << "请输入 学号 姓名 专业 （空格间隔，回车输入，0退出）：\n\n";

	while (n) {
		p = new LNode;
		if (!p)
			return ERROR;

		cin >> p->data.Snumber;
		if (!cin) {
			cout << "学号输入错误，请重新输入\n";
			cin.clear();
			cin.ignore(500, '\n');
			continue;
		}
		if (p->data.Snumber == 0)
			break;

		cin >> p->data.name;
		if (!cin) {
			cout << "姓名输入错误，请重新输入\n";
			cin.clear();
			cin.ignore(500, '\n');
			continue;
		}
		if (p->data.name == "0")
			break;

		cin >> p->data.major;
		if (!cin) {
			cout << "学号输入错误，请重新出入\n";
			cin.clear();
			cin.ignore(500, '\n');
			continue;
		}
		if (p->data.major == "0")
			break;

		p->next = NULL;
		r->next = p;
		r = p;

		n--;
	}
	if (!n)
		cout << "建表完成！\n";
	else
		cout << "\n退出，未完成建表！\n";
	return OK;
}

/**
* GetElem		单链表的取值
* @param L		单链表L
* @param i		位置序号
* @param e		储存目标结点信息
* @return		Status
*/
Status GetElem(LinkList L, int i, ElemType& e) {
	LNode* p;
	p = L->next;
	int j = 1;

	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;

	e = p->data;

	return OK;
}

/**
* LocateElem		单链表按值查找
* @param L			单链表L
* @param e			给定值
* #return LNode*	储存目标信息的结点指针
*/
LNode* LocateElem(LinkList L, string e) {
	LNode* p;
	p = L->next;

	while (p && p->data.name != e)
		p = p->next;

	return p;
}

/**
* ListInsert	单链表的插入
* @param L		单链表L
* @param i		插入位置
* @param e		插入结点信息
* @return Status
*/
Status ListInsert(LinkList& L, int i, ElemType e) {
	LNode* p, * s;
	int j = 0;
	p = L;

	while (p && (j < i - 1)) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) {
		cout << "error\n";
		return ERROR;
	}

	s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;

	return OK;
}

/**
* ListDelete	单链表结点的删除
* @param L		单链表L
* @param i		被删除结点的序号
* @return Status
*/
Status ListDelete(LinkList& L, int i) {
	LNode* p, * q;
	int j = 0;
	p = L;

	while ((p->next) && (j < i - 1)) {
		p = p->next;
		j++;
	}
	if (!(p->next) || (j > i - 1))
		return ERROR;

	q = p->next;
	p->next = q->next;
	delete q;

	return OK;
}

/**
* Choose_num		//提示并选择输入操作编号
* @param choose		操作编号
* @return void
*/
void Choose_num(int& choose){
	cout << "\n《数据结构与算法》选课名单的相应操作:\n";
	cout << " 1.创建（头插法） 2.创建（尾插法）  3.取值 \n"
		<< " 4.查找    5.插入   6.删除  7.输出  0.退出\n";
	cout << "\n请输入选择的操作编号: ";

	cin >> choose;
}

int main() {
	LinkList L, p;
	L = NULL;

	int i, n;
	char temp;

	Student student_data;
	string name;

	int flag_create = 0;
	
	int choose = -1;

	while (choose != 0) {
		Choose_num(choose);

		if (!cin) {
			cout << "\n输入操作选择编号非数字!请重新输入\n";
			cin.clear();
			cin.ignore(500, '\n');
			choose = -1;
			continue;
		}
		switch (choose){
		case 0:
			break;
		case 1:		//前插法创建单链表
			if (flag_create){
				cout << "\n已创建，是否重新创建？若是，请输入Y >";
				char answer;
				cin >> answer;
				if (answer == 'y' || answer == 'Y');
				else
					break;
			}
			cout << "\n输入创建入表的学生数量n=";
			cin >> n;
			if (!n) {
				cout << "\n输入学生数量不能为0\n";
				break;
			}
			if (CreateList_H(L, n))
				if (L->next)
					flag_create = 1;
			break;
		case 2:		//后插法创建单链表
			if (flag_create) {
				cout << "\n已创建，是否重新创建？若是，请输入Y >";
				char answer;
				cin >> answer;
				if (answer == 'y' || answer == 'Y');
				else
					break;
			}
			cout << "\n输入创建入表的学生数量n=";
			cin >> n;
			if (!n) {
				cout << "\n输入学生数量不能为0\n";
				break;
			}
			if (CreateList_R(L, n))
				if (L->next)
					flag_create = 1;
			break;
		case 3:
			if (!flag_create){
				cout << "\n尚未建表\n";
				break;
			}
			cout << "请输入取值序号i：";
			cin >> i;
			if (GetElem(L, i, student_data)){
				cout << "\n查到第" << i << "名学生的信息：\n";
				cout << left << setw(15) << "学 号" << "\t"
					<< left << setw(15) << "姓 名" << "\t"
					<< left << setw(15) << "专 业" << endl;
				cout << left << setw(15) << student_data.Snumber << "\t"
					<< left << setw(15) << student_data.name << "\t"
					<< left << setw(15) << student_data.major << endl;
			}
			else
				cout << "\n输入序号不存在!\n";
			break;
		case 4:
			if (!flag_create) {
				cout << "\n尚未建表\n";
				break;
			}
			cout << "请输入姓名：";
			cin >> name;
			p = LocateElem(L, name);
			if (p) {
				cout << "\n查到 " << name << "信息：" << endl;
				cout << left << setw(15) << "学 号" << "\t"
					<< left << setw(15) << "姓 名" << "\t"
					<< left << setw(15) << "专 业" << endl;
				cout << left << setw(15) << p->data.Snumber << "\t"
					<< left << setw(15) << p->data.name << "\t"
					<< left << setw(15) << p->data.major << "\t";
			}
			else
				cout << "未查到\n\n";
			break;
		case 5:
			if (!flag_create) {
				cout << "\n尚未建表\n";
				break;
			}
			cout << "\n请输入插入位置：";
			cin >> i;
			cout << "\n请输入 学号 姓名 专业（空格间隔，回车输入，0放弃）:\n\n";
			do {
				n = 1;

				cin >> student_data.Snumber;
				if (!cin) {
					cout << "学号输入错误，请重新输入\n";
					cin.clear();
					cin.ignore(500, '\n');
					continue;
				}
				if (student_data.Snumber == 0)
					break;

				cin >> student_data.name;
				if (!cin) {
					cout << "姓名输入错误，请重新输入\n";
					cin.clear();
					cin.ignore(500, '\n');
					continue;
				}
				if (student_data.name == "0")
					break;

				cin >> student_data.major;
				if (!cin) {
					cout << "专业输入错误，请重新出入\n";
					cin.clear();
					cin.ignore(500, '\n');
					continue;
				}
				if (student_data.major == "0")
					break;

				n = 0;
			} while (n);

			if(ListInsert(L, i, student_data))
				cout<<"\n插入成功\n";
			break;
		case 6:
			if (!flag_create) {
				cout << "\n尚未建表\n";
				break;
			}
			cout << "\n请输入要删除姓名的序号：\n";
			cin >> i;
			if (ListDelete(L, i))
				cout << "删除成功！\n";
			break;
		case 7:
			if (!flag_create) { cout << "\n尚未建表\n"; break; }

			cout << "\n" << left << setw(15) << "学 号" << "\t"
				<< left << setw(15) << "姓 名" << "\t"
				<< left << setw(15) << "专 业\n" << endl;

			for (p = L->next, n = 0; p != NULL; p = p->next)  //依次输出单链表各个结点的数据域信息
			{
				cout << left << setw(15) << p->data.Snumber << "\t"        //输出学号
					<< left << setw(15) << p->data.name << "\t"   //输出姓名
					<< left << setw(15) << p->data.major << endl; //输出专业
				n++;
			}
			cout << "\n选课学生名单输出完毕(共" << n << "名)\n";
			break;
		default:
			break;
		}
	}
}