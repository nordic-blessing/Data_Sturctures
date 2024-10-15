#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
using namespace std;

#define OK 1
#define ERROR 0

#define OVERFLOW -1

#define MAXSIZE  5

#define Status int

typedef struct
{
	int Snumber;  //学号
	string name;  //姓名
	string major; //专业
}Student;


typedef struct SqList
{
	Student* e;
	int length;

}SqList;

int main() {
	Status InitList(SqList & L);                     //函数声明，基本操作1：初始化（构造一个空的顺序表L）
	Status CreateList(SqList & L);                   //函数声明，基本操作2：创建（把学生名单输入顺序表L）
	Status GetElem(SqList L, int i, Student & e);
	int LocateElem(SqList L, string e);
	Status ListInsert(SqList & L, int i, Student e);
	Status ListDelete(SqList & L, int i);

	void Choose_num(int& choose);

	SqList L;

	int i = 1;
	char temp;

	Student student_data;

	string name;

	int flag_init = 0;
	int flag_create = 0;

	int choose;
	choose = -1;


	while (choose != 0)
	{
		Choose_num(choose);
		if (!cin){
			cout << "\n输入操作选择编号非数字!请重新输入\n";
			cin.clear();
			while ((temp = getchar()) != '\n');
			choose = -1;
			continue;
		}

		switch (choose)
		{
		case 0: break;
		case 1: //初始化
			if (InitList(L)){
				flag_init = 1; cout << "\n初始化成功!\n\n";
			}
			else
				cout << "\n初始化失败!\n\n";
			break;
		case 2: //创建
			if (!flag_init){
				cout << "\n尚未初始化\n"; break;
			}
			if (flag_create){
				cout << "\n已创建，是否重新创建？若是，请输入Y >";
				char answer;
				cin >> answer;
				if (answer == 'y' || answer == 'Y');
				else break;
			}
			CreateList(L);
			if (L.length)
				flag_create = 1;
			else
				flag_create = 0;
			break;
		case 3:  //取值
			if (!flag_create){
				cout << "尚未建表"; break;
			}
			cout << "请输入取值序号i:";
			{
				int i;
				Student e;
				cin >> i;
				if (GetElem(L, i, e)) {
					cout << left << setw(15) << "学 号" << "\t"
						<< left << setw(15) << "姓 名" << "\t"
						<< left << setw(15) << "专 业" << endl;
					cout << left << setw(15) << e.Snumber << "\t"
						<< left << setw(15) << e.name << "\t"
						<< left << setw(15) << e.major << endl;
					cout << endl;
				}
				else {
					cout << "\n输入序号不存在！\n";
				}
			}
			break;
		case 4:{//查找
			cout << "请输入姓名：";
			Student e;
			cin >> e.name;
			if (LocateElem(L, e.name)) {
				cout << "\n查到 " << e.name << " 序号：" << LocateElem(L, e.name) + 1;
			}
			else
				cout << "\n未查到";
		}
		break;
		case 5:{//插入
			Student e;
			int i;
			cout << "请输入插入位置：";
			cin >> i;
			cout << "请输入 学号  姓名  专业 (空格间隔，回车输入,“0”放弃):\n\n";
			cin >> e.Snumber >> e.name >> e.major;
			if (ListInsert(L, i, e)) {
				cout << "\n插入成功\n";
			}
			else {
				cout << "\n插入失败\n";
			}
		}
			break;
		case 6:{//删除
			int i;
			cout << "请输入要删除姓名的序号：";
			cin >> i;
			if (ListDelete(L, i)) {
				cout << "\n删除成功!\n";
			}
			else {
				cout << "\n表中无此序号！\n";
			}
		}
			break;
		case 7:   //输出
			if (!flag_create) { cout << "\n尚未建表\n"; break; }
			cout << "\n选课学生名单(共" << L.length << "名):\n";
			cout << left << setw(15) << "学 号" << "\t"
				<< left << setw(15) << "姓 名" << "\t"
				<< left << setw(15) << "专 业" << endl;
			for (i = 0; i < L.length; i++){
				cout << left << setw(15) << L.e[i].Snumber << "\t"
					<< left << setw(15) << L.e[i].name << "\t"
					<< left << setw(15) << L.e[i].major << endl;
			}
			break;
		default:  cout << "\n输入编号错误!\n ";
		}
	}

	return 0;
}

void Choose_num(int& choose){
	cout << "\n《数据结构与算法》选课名单的相应操作:\n";
	cout << " 1.初始化 2.创建  3.取值  4.查找\n"
		<< " 5.插入   6.删除  7.输出  0.退出\n";
	cout << "\n请输入选择的操作编号: ";

	cin >> choose;
}

/**
* 初始化顺序表
* @param &L
*/
Status InitList(SqList& L){
	L.e = new Student[MAXSIZE];
	if (!L.e) return ERROR;
	L.length = 0;
	return OK;
}

/**
* 创建（把学生名单输入此线性表）
* @param &L
*/
Status CreateList(SqList& L){
	L.length = 0;
	int i = 0;
	cout << "请输入 学号  姓名  专业 (空格间隔，回车输入, 0退出):\n\n";
	while (1)
	{
		if (L.length == MAXSIZE){
			cout << "\n课程教室容量已满!不能继续输入。"; return ERROR;
		}
		cin >> L.e[i].Snumber;
		if (!cin)
		{
			cout << "\n学号输入错误，请重新输入\n";
			cin.clear();
			cin.ignore(500, '\n');
			continue;
		}
		if (L.e[i].Snumber == 0) break;
		cin >> L.e[i].name;
		if (!cin){
			cout << "\n姓名输入错误，请重新输入\n";
			cin.clear();
			cin.ignore(500, '\n');
			continue;
		}
		if (L.e[i].name == "0")
			break;

		cin >> L.e[i].major;
		if (!cin){
			cout << "\n专业输入错误，请重新输入\n";
			cin.clear();
			cin.ignore(500, '\n');
			continue;
		}
		if (L.e[i].major == "0")
			break;
		L.length++;
		i++;
	}
	if (L.length)
		cout << "\n建表完成!\n";
	else
		cout << "\n退出建表\n";
	return OK;
}

/**
* 取值，根据给定的序号，获取该序号的学生信息
* @param L		顺序表
* @param i		输入序号
* @param &e		存储查找的信息
*/
Status GetElem(SqList L, int i, Student & e) {
	if (i<1 || i>L.length)
		return ERROR;
	e.name = L.e[i - 1].name;
	e.major = L.e[i - 1].major;
	e.Snumber = L.e[i - 1].Snumber;
	return OK;
}

/**
* 查找，根据给定学生姓名，查找该名学生是否在表中，并返回查找结果
* @param L		顺序表
* @param name	输入姓名
* @return int	目标元素的序号
*/
int LocateElem(SqList L, string name) {
	int i;
	for (i = 0; i < L.length; i++) {
		if (L.e[i].name == name)
			return i+1;
		return 0;
	}
}

/**
* 插入，将新增学生信息插入表中指定位置
* @param &L		顺序表
* @param i		输入位置
* @param e		输入元素信息
*/
Status ListInsert(SqList& L, int i, Student e) {
	if ((i < i) || (i > L.length + 1))
		return ERROR;
	if (L.length == MAXSIZE)
		return OVERFLOW;
	for (int j = L.length - 1; j >= i - 1; j--)
		L.e[j + 1] = L.e[j];
	L.e[i - 1] = e;
	L.length++;
	return OK;
}

/**
* 删除，在表中将该生信息删除
* @param &L		顺序表
* @param i		输入序号
*/
Status ListDelete(SqList& L, int i) {
	if ((i < 1) || (i > L.length))
		return ERROR;
	for (int j = i; j <= L.length; j++)
		L.e[j - 1] = L.e[j];
	L.length--;
	return OK;
}
