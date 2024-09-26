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
	int Snumber;	//ѧ��
	string name;	//����
	string major;	//רҵ
}Student;

typedef struct LNode {
	Student data;
	struct LNode* next;
}LNode, * LinkList;

/**
* CreateLList_H		ǰ�巨����������
* @param L			������L
* @param n			������󳤶�
* @return			Status
*/
Status CreateList_H(LinkList& L, int n) {
	L = new LNode;
	if (!L)
		return ERROR;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		LNode* p;

		cout << "ǰ�巨���������� \n\n";
		cout << "������ ѧ�� ���� רҵ ���ո������س����룬0�˳�����\n\n";

		while (n) {
			p = new LNode;
			if (!p)
				return ERROR;

			cin >> p->data.Snumber;
			if (!cin) {
				cout << "ѧ�������������������\n";
				cin.clear();
				cin.ignore(500, '\n');
				continue;
			}
			if (p->data.Snumber == 0)
				break;

			cin >> p->data.name;
			if (!cin) {
				cout << "���������������������\n";
				cin.clear();
				cin.ignore(500, '\n');
				continue;
			}
			if (p->data.name == "0")
				break;

			cin >> p->data.major;
			if (!cin) {
				cout << "רҵ������������³���\n";
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
			cout << "\n������ɣ�\n";
		else
			cout << "\n�˳���δ��ɽ���\n";
		return OK;
	}
}

/**
* CreateList_R		��巨����������
* @param L			������L
* @param n			�������󳤶�
* @return			Status
*/
Status CreateList_R(LinkList& L, int n) {
	L = new LNode;
	if (!L)
		return ERROR;
	L->next = NULL;

	LNode* p, * r;
	r = L;

	cout << "��巨���������� \n\n";
	cout << "������ ѧ�� ���� רҵ ���ո������س����룬0�˳�����\n\n";

	while (n) {
		p = new LNode;
		if (!p)
			return ERROR;

		cin >> p->data.Snumber;
		if (!cin) {
			cout << "ѧ�������������������\n";
			cin.clear();
			cin.ignore(500, '\n');
			continue;
		}
		if (p->data.Snumber == 0)
			break;

		cin >> p->data.name;
		if (!cin) {
			cout << "���������������������\n";
			cin.clear();
			cin.ignore(500, '\n');
			continue;
		}
		if (p->data.name == "0")
			break;

		cin >> p->data.major;
		if (!cin) {
			cout << "ѧ��������������³���\n";
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
		cout << "������ɣ�\n";
	else
		cout << "\n�˳���δ��ɽ���\n";
	return OK;
}

/**
* GetElem		�������ȡֵ
* @param L		������L
* @param i		λ�����
* @param e		����Ŀ������Ϣ
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
* LocateElem		������ֵ����
* @param L			������L
* @param e			����ֵ
* #return LNode*	����Ŀ����Ϣ�Ľ��ָ��
*/
LNode* LocateElem(LinkList L, string e) {
	LNode* p;
	p = L->next;

	while (p && p->data.name != e)
		p = p->next;

	return p;
}

/**
* ListInsert	������Ĳ���
* @param L		������L
* @param i		����λ��
* @param e		��������Ϣ
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
* ListDelete	���������ɾ��
* @param L		������L
* @param i		��ɾ���������
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
* Choose_num		//��ʾ��ѡ������������
* @param choose		�������
* @return void
*/
void Choose_num(int& choose){
	cout << "\n�����ݽṹ���㷨��ѡ����������Ӧ����:\n";
	cout << " 1.������ͷ�巨�� 2.������β�巨��  3.ȡֵ \n"
		<< " 4.����    5.����   6.ɾ��  7.���  0.�˳�\n";
	cout << "\n������ѡ��Ĳ������: ";

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
			cout << "\n�������ѡ���ŷ�����!����������\n";
			cin.clear();
			cin.ignore(500, '\n');
			choose = -1;
			continue;
		}
		switch (choose){
		case 0:
			break;
		case 1:		//ǰ�巨����������
			if (flag_create){
				cout << "\n�Ѵ������Ƿ����´��������ǣ�������Y >";
				char answer;
				cin >> answer;
				if (answer == 'y' || answer == 'Y');
				else
					break;
			}
			cout << "\n���봴������ѧ������n=";
			cin >> n;
			if (!n) {
				cout << "\n����ѧ����������Ϊ0\n";
				break;
			}
			if (CreateList_H(L, n))
				if (L->next)
					flag_create = 1;
			break;
		case 2:		//��巨����������
			if (flag_create) {
				cout << "\n�Ѵ������Ƿ����´��������ǣ�������Y >";
				char answer;
				cin >> answer;
				if (answer == 'y' || answer == 'Y');
				else
					break;
			}
			cout << "\n���봴������ѧ������n=";
			cin >> n;
			if (!n) {
				cout << "\n����ѧ����������Ϊ0\n";
				break;
			}
			if (CreateList_R(L, n))
				if (L->next)
					flag_create = 1;
			break;
		case 3:
			if (!flag_create){
				cout << "\n��δ����\n";
				break;
			}
			cout << "������ȡֵ���i��";
			cin >> i;
			if (GetElem(L, i, student_data)){
				cout << "\n�鵽��" << i << "��ѧ������Ϣ��\n";
				cout << left << setw(15) << "ѧ ��" << "\t"
					<< left << setw(15) << "�� ��" << "\t"
					<< left << setw(15) << "ר ҵ" << endl;
				cout << left << setw(15) << student_data.Snumber << "\t"
					<< left << setw(15) << student_data.name << "\t"
					<< left << setw(15) << student_data.major << endl;
			}
			else
				cout << "\n������Ų�����!\n";
			break;
		case 4:
			if (!flag_create) {
				cout << "\n��δ����\n";
				break;
			}
			cout << "������������";
			cin >> name;
			p = LocateElem(L, name);
			if (p) {
				cout << "\n�鵽 " << name << "��Ϣ��" << endl;
				cout << left << setw(15) << "ѧ ��" << "\t"
					<< left << setw(15) << "�� ��" << "\t"
					<< left << setw(15) << "ר ҵ" << endl;
				cout << left << setw(15) << p->data.Snumber << "\t"
					<< left << setw(15) << p->data.name << "\t"
					<< left << setw(15) << p->data.major << "\t";
			}
			else
				cout << "δ�鵽\n\n";
			break;
		case 5:
			if (!flag_create) {
				cout << "\n��δ����\n";
				break;
			}
			cout << "\n���������λ�ã�";
			cin >> i;
			cout << "\n������ ѧ�� ���� רҵ���ո������س����룬0������:\n\n";
			do {
				n = 1;

				cin >> student_data.Snumber;
				if (!cin) {
					cout << "ѧ�������������������\n";
					cin.clear();
					cin.ignore(500, '\n');
					continue;
				}
				if (student_data.Snumber == 0)
					break;

				cin >> student_data.name;
				if (!cin) {
					cout << "���������������������\n";
					cin.clear();
					cin.ignore(500, '\n');
					continue;
				}
				if (student_data.name == "0")
					break;

				cin >> student_data.major;
				if (!cin) {
					cout << "רҵ������������³���\n";
					cin.clear();
					cin.ignore(500, '\n');
					continue;
				}
				if (student_data.major == "0")
					break;

				n = 0;
			} while (n);

			if(ListInsert(L, i, student_data))
				cout<<"\n����ɹ�\n";
			break;
		case 6:
			if (!flag_create) {
				cout << "\n��δ����\n";
				break;
			}
			cout << "\n������Ҫɾ����������ţ�\n";
			cin >> i;
			if (ListDelete(L, i))
				cout << "ɾ���ɹ���\n";
			break;
		case 7:
			if (!flag_create) { cout << "\n��δ����\n"; break; }

			cout << "\n" << left << setw(15) << "ѧ ��" << "\t"
				<< left << setw(15) << "�� ��" << "\t"
				<< left << setw(15) << "ר ҵ\n" << endl;

			for (p = L->next, n = 0; p != NULL; p = p->next)  //����������������������������Ϣ
			{
				cout << left << setw(15) << p->data.Snumber << "\t"        //���ѧ��
					<< left << setw(15) << p->data.name << "\t"   //�������
					<< left << setw(15) << p->data.major << endl; //���רҵ
				n++;
			}
			cout << "\nѡ��ѧ������������(��" << n << "��)\n";
			break;
		default:
			break;
		}
	}
}