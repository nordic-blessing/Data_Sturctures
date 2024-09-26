#include<iostream>
#include<fstream>
#include<string>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*LinkList;

char st = 'A';
string filename;

/*
* 链表初始化
* @param &L		操作链表
* @return void
*/
void InitList_L(LinkList& L) {
	L = new LNode;
	L->next = NULL;
}

/*
* 向链表中输入元素
* @param &L				操作链表
* @param &filename		文件地址
* @return void
*/
void input(LinkList& L, string& filename) {
	LNode* p, * r;
	r = L;
	while (1) {
		cout << "请输入非递减线性表" << st << "的数据文件路径和名称（如D:\\数据结构实验-自动化\\List" << st << ".txt）：" << endl;
		cin >> filename;

		fstream file;
		file.open(filename);
		if (!file) {
			cout << "未找到相关文件，无法打开！" << endl;
			continue;
		}
		while (!file.eof()) {
			p = new LNode;
			file >> p->data;
			p->next = NULL;
			r->next = p;
			r = p;
		}
		file.close();
		st++;
		break;
	}
}

/*
* 依次输出链表中的元素
* @param L		操作链表
* @return void
*/
void output(LinkList L) {
	int i = 0;
	LNode* p;
	p = L->next;
	while (p) {
		if (i)
			cout << ",";
		cout << p->data;
		p = p->next;
		i = 1;
	}
	cout << endl;
}

/*
* 保存合并后的链表文件
* @param L				操作链表
* @param &filename		文件名称
*/
void save_LinkList(LinkList L, string& filename){
	filename = filename.replace(filename.length() - 5, 5, "C.txt");
	fstream file;
	file.open(filename, ios::out); 
	if (!file)
	{
		cout << "\n无法打开文件";
		exit(0);
	}
	file << "合并后的单链有序表数据: ";
	LNode* p = L->next;
	while (p)
	{
		file << p->data << " ";
		p = p->next;
	}
	file.close();
	cout << "\n合并后的链式有序表保存在" << filename << endl;
}

/*
* 
*/
void MergeList_L(LinkList& LA, LinkList& LB, LinkList& LC) {
	LNode* pa, * pb, * pc;
	pa = LA->next;
	pb = LB->next;
	LC = LA;
	pc = LC;
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	delete LB;
}

int main() {

	LinkList La, Lb, Lc;

	InitList_L(La); //La表的创建
	input(La, filename); //依次往单链表La里输入数据
	output(La);

	InitList_L(Lb); //Lb表的创建	
	input(Lb, filename); //依次往单链表La里输入数据
	output(Lb);

	InitList_L(Lc);
	MergeList_L(La, Lb, Lc); //将单链表La和Lb进行合并

	cout << "非递减单链表A，B合并后的非递减单链表C为：\n"; //输出合并后的单链表Lc
	output(Lc);
	save_LinkList(Lc, filename);  //保存合并后的链表文件

	system("pause");

	return 0;
}