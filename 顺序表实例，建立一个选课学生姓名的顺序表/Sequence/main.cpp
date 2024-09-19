#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define OK 1				//成功
#define ERROR 0				//失败
#define OVERFLOW -1			//溢出
#define ElemType string		//数据元素类型
#define Status int			//函数返回值类型

#define MAXSIZE 100			//顺序表的最大长度
typedef struct SqList {
	ElemType* e;			//储存空间的基地址
	int length;				//当前长度
}SqList;

int main() {
	Status InitList(SqList & L);						//基本操作1：初始化（构造一个空的线性表L）
	Status CreateList(SqList & L);						//基本操作2：创建（把学生名单输入线性表L）
	Status GetElem(SqList & L, int i, ElemType & e);	//基本操作3：取值（ 根据给定的序号，获取该序号的学生姓名）
	Status LocateElem(SqList L, ElemType e);			//基本操作4：查找（ 根据给定学生姓名，查找该名学生是否在表中，并返回查找结果）
	Status ListInsert(SqList & L, int i, ElemType & e);	//基本操作5：插入（ 有新增学生姓名，插入选课学生表中，并指定插入位置）
	Status ListDelete(SqList & L, int i);				//基本操作6：删除（ 有学生退选，在选课学生表中将该生名单删除）

	SqList L;
	while (1) {
		cout << "\n《数据结构与算法》选课名单的相应操作：" << endl;
		cout << setw(10) << "1.初始化";	cout << setw(10) << "2.创建";
		cout << setw(10) << "3.取值";	cout << setw(10) << "4.查找";
		cout << endl;
		cout << setw(10) << "5.插入";	cout << setw(10) << "6.删除";
		cout << setw(10) << "7.输出";	cout << setw(10) << "0.退出";
		cout << endl;
		cout << "请输入选择的操作编号：";
		int i;
		cin >> i;
		switch (i)
		{
			case 1:		//初始化顺序表
			{
				if (InitList(L))
					cout << "\n初始化成功！\n\n";
			}
				break;
			case 2:		//创建顺序表
			{
				CreateList(L);
			}
				break;
			case 3:		//输入序号查找姓名
			{
				cout << "请输入取值序号 i :";
				int i;
				ElemType e;
				cin >> i;
				if (GetElem(L, i, e))
					cout << "\n" << L.e[i-1] << endl;
				else
					cout << "\n输入序号不合法！\n";
			}
				break;
			case 4:		//输入姓名查找序号
			{
				cout << "请输入姓名：";
				ElemType e;
				cin >> e;
				if (LocateElem(L, e)) {
					cout << "\n查到" << e << "序号：" << LocateElem(L, e);
				}
				else
					cout << "\n未查到";
			}
				break;
			case 5:		//插入
			{
				ElemType e;
				int i;
				cout << "请输入插入学生姓名：";
				cin >> e;
				cout << "请输入插入位置：";
				cin >> i;
				if (ListInsert(L, i, e)) {
					cout << "\n插入成功\n";
				}
				else {
					cout << "\n插入失败\n";
				}
			}
			break;
			case 6:		//删除
			{
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
			case 7:		//输出
			{
				cout << "\n选课学生名单（共" << L.length << "名）：\n" << endl;
				for (int i = 0; i < L.length; i++) {
					cout << setw(3) << i + 1 << setw(10) << L.e[i] << endl;
				}
					cout << "\n\n";
			}
			break;
			case 0:		//退出
				return 0;
			default:
				break;
		}
	}
}

//基本操作1：初始化（构造一个空的线性表L）
Status InitList(SqList& L) {
	L.e = new ElemType[MAXSIZE];		//为顺序表分配一个大小为MAXSIZE的数组空间
	if (!L.e)
		return ERROR;
	L.length = 0;						//空表长度为0
	return OK;
}

//基本操作2：创建（把学生名单输入线性表L）
Status CreateList(SqList &L) {
	string student_name;
	cout << "请通过键盘输入学生姓名（以空格间隔，回车结束，0退出）：";
	cin >> student_name;

	int i = 0;
	while (student_name != "0") {
		if (L.length == MAXSIZE) {
			cout << "\n出错，超出课程教室容量";
			return ERROR;
		}

		L.e[i++] = student_name;
		L.length++;

		if (cin.get() == '\n') {
			cout << "请继续输入学生姓名：";
		}

		cin >> student_name;
	}

	cout << "创建学生选课名单成功！选课共 " << i << " 名\n\n";
	for (i = 0; i < L.length; i++)
		cout << L.e[i] << "\n";

	return OK;
}

//基本操作3：取值（ 根据给定的序号，获取该序号的学生姓名）
Status GetElem(SqList& L, int i, ElemType& e) {
	if (i<1 || i>L.length)
		return ERROR;
	e = L.e[i - 1];
	return OK;
}

//基本操作4：查找（ 根据给定学生姓名，查找该名学生是否在表中，并返回查找结果）
Status LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.e[i] == e)
			return i+1;
	}
	return 0;
}

//基本操作5：插入（ 有新增学生姓名，插入选课学生表中，并指定插入位置）
Status ListInsert(SqList& L, int i, ElemType& e) {
	if (i<1 || i>L.length + 1)						//i 不合法
		return ERROR;
	if (L.length == MAXSIZE)						//当前储存空间已满
		return ERROR;
	for (int j = L.length - 1; j >= i - 1; j--)
		L.e[j + 1] = L.e[j];						//插入位置及之后的元素后移
	L.e[i - 1] = e;									//新元素 e 放入第 i 个位置
	L.length++;										//表长 +1
	return OK;
}

//基本操作6：删除（ 有学生退选，在选课学生表中将该生名单删除）
Status ListDelete(SqList& L, int i) {
	if (i<1 || i>L.length)						//i 不合法
		return ERROR;
	for (int j = i; j <= L.length; j++)
		L.e[j - 1] = L.e[j];					//被删除元素之后的元素前移
	L.length--;
	return OK;
}