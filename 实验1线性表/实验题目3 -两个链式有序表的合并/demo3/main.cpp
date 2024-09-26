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
* �����ʼ��
* @param &L		��������
* @return void
*/
void InitList_L(LinkList& L) {
	L = new LNode;
	L->next = NULL;
}

/*
* ������������Ԫ��
* @param &L				��������
* @param &filename		�ļ���ַ
* @return void
*/
void input(LinkList& L, string& filename) {
	LNode* p, * r;
	r = L;
	while (1) {
		cout << "������ǵݼ����Ա�" << st << "�������ļ�·�������ƣ���D:\\���ݽṹʵ��-�Զ���\\List" << st << ".txt����" << endl;
		cin >> filename;

		fstream file;
		file.open(filename);
		if (!file) {
			cout << "δ�ҵ�����ļ����޷��򿪣�" << endl;
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
* ������������е�Ԫ��
* @param L		��������
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
* ����ϲ���������ļ�
* @param L				��������
* @param &filename		�ļ�����
*/
void save_LinkList(LinkList L, string& filename){
	filename = filename.replace(filename.length() - 5, 5, "C.txt");
	fstream file;
	file.open(filename, ios::out); 
	if (!file)
	{
		cout << "\n�޷����ļ�";
		exit(0);
	}
	file << "�ϲ���ĵ������������: ";
	LNode* p = L->next;
	while (p)
	{
		file << p->data << " ";
		p = p->next;
	}
	file.close();
	cout << "\n�ϲ������ʽ���������" << filename << endl;
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

	InitList_L(La); //La��Ĵ���
	input(La, filename); //������������La����������
	output(La);

	InitList_L(Lb); //Lb��Ĵ���	
	input(Lb, filename); //������������La����������
	output(Lb);

	InitList_L(Lc);
	MergeList_L(La, Lb, Lc); //��������La��Lb���кϲ�

	cout << "�ǵݼ�������A��B�ϲ���ķǵݼ�������CΪ��\n"; //����ϲ���ĵ�����Lc
	output(Lc);
	save_LinkList(Lc, filename);  //����ϲ���������ļ�

	system("pause");

	return 0;
}