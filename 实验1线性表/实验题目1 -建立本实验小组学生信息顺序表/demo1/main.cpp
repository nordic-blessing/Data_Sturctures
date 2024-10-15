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
	int Snumber;  //ѧ��
	string name;  //����
	string major; //רҵ
}Student;


typedef struct SqList
{
	Student* e;
	int length;

}SqList;

int main() {
	Status InitList(SqList & L);                     //������������������1����ʼ��������һ���յ�˳���L��
	Status CreateList(SqList & L);                   //������������������2����������ѧ����������˳���L��
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
			cout << "\n�������ѡ���ŷ�����!����������\n";
			cin.clear();
			while ((temp = getchar()) != '\n');
			choose = -1;
			continue;
		}

		switch (choose)
		{
		case 0: break;
		case 1: //��ʼ��
			if (InitList(L)){
				flag_init = 1; cout << "\n��ʼ���ɹ�!\n\n";
			}
			else
				cout << "\n��ʼ��ʧ��!\n\n";
			break;
		case 2: //����
			if (!flag_init){
				cout << "\n��δ��ʼ��\n"; break;
			}
			if (flag_create){
				cout << "\n�Ѵ������Ƿ����´��������ǣ�������Y >";
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
		case 3:  //ȡֵ
			if (!flag_create){
				cout << "��δ����"; break;
			}
			cout << "������ȡֵ���i:";
			{
				int i;
				Student e;
				cin >> i;
				if (GetElem(L, i, e)) {
					cout << left << setw(15) << "ѧ ��" << "\t"
						<< left << setw(15) << "�� ��" << "\t"
						<< left << setw(15) << "ר ҵ" << endl;
					cout << left << setw(15) << e.Snumber << "\t"
						<< left << setw(15) << e.name << "\t"
						<< left << setw(15) << e.major << endl;
					cout << endl;
				}
				else {
					cout << "\n������Ų����ڣ�\n";
				}
			}
			break;
		case 4:{//����
			cout << "������������";
			Student e;
			cin >> e.name;
			if (LocateElem(L, e.name)) {
				cout << "\n�鵽 " << e.name << " ��ţ�" << LocateElem(L, e.name) + 1;
			}
			else
				cout << "\nδ�鵽";
		}
		break;
		case 5:{//����
			Student e;
			int i;
			cout << "���������λ�ã�";
			cin >> i;
			cout << "������ ѧ��  ����  רҵ (�ո������س�����,��0������):\n\n";
			cin >> e.Snumber >> e.name >> e.major;
			if (ListInsert(L, i, e)) {
				cout << "\n����ɹ�\n";
			}
			else {
				cout << "\n����ʧ��\n";
			}
		}
			break;
		case 6:{//ɾ��
			int i;
			cout << "������Ҫɾ����������ţ�";
			cin >> i;
			if (ListDelete(L, i)) {
				cout << "\nɾ���ɹ�!\n";
			}
			else {
				cout << "\n�����޴���ţ�\n";
			}
		}
			break;
		case 7:   //���
			if (!flag_create) { cout << "\n��δ����\n"; break; }
			cout << "\nѡ��ѧ������(��" << L.length << "��):\n";
			cout << left << setw(15) << "ѧ ��" << "\t"
				<< left << setw(15) << "�� ��" << "\t"
				<< left << setw(15) << "ר ҵ" << endl;
			for (i = 0; i < L.length; i++){
				cout << left << setw(15) << L.e[i].Snumber << "\t"
					<< left << setw(15) << L.e[i].name << "\t"
					<< left << setw(15) << L.e[i].major << endl;
			}
			break;
		default:  cout << "\n�����Ŵ���!\n ";
		}
	}

	return 0;
}

void Choose_num(int& choose){
	cout << "\n�����ݽṹ���㷨��ѡ����������Ӧ����:\n";
	cout << " 1.��ʼ�� 2.����  3.ȡֵ  4.����\n"
		<< " 5.����   6.ɾ��  7.���  0.�˳�\n";
	cout << "\n������ѡ��Ĳ������: ";

	cin >> choose;
}

/**
* ��ʼ��˳���
* @param &L
*/
Status InitList(SqList& L){
	L.e = new Student[MAXSIZE];
	if (!L.e) return ERROR;
	L.length = 0;
	return OK;
}

/**
* ��������ѧ��������������Ա�
* @param &L
*/
Status CreateList(SqList& L){
	L.length = 0;
	int i = 0;
	cout << "������ ѧ��  ����  רҵ (�ո������س�����, 0�˳�):\n\n";
	while (1)
	{
		if (L.length == MAXSIZE){
			cout << "\n�γ̽�����������!���ܼ������롣"; return ERROR;
		}
		cin >> L.e[i].Snumber;
		if (!cin)
		{
			cout << "\nѧ�������������������\n";
			cin.clear();
			cin.ignore(500, '\n');
			continue;
		}
		if (L.e[i].Snumber == 0) break;
		cin >> L.e[i].name;
		if (!cin){
			cout << "\n���������������������\n";
			cin.clear();
			cin.ignore(500, '\n');
			continue;
		}
		if (L.e[i].name == "0")
			break;

		cin >> L.e[i].major;
		if (!cin){
			cout << "\nרҵ�����������������\n";
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
		cout << "\n�������!\n";
	else
		cout << "\n�˳�����\n";
	return OK;
}

/**
* ȡֵ�����ݸ�������ţ���ȡ����ŵ�ѧ����Ϣ
* @param L		˳���
* @param i		�������
* @param &e		�洢���ҵ���Ϣ
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
* ���ң����ݸ���ѧ�����������Ҹ���ѧ���Ƿ��ڱ��У������ز��ҽ��
* @param L		˳���
* @param name	��������
* @return int	Ŀ��Ԫ�ص����
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
* ���룬������ѧ����Ϣ�������ָ��λ��
* @param &L		˳���
* @param i		����λ��
* @param e		����Ԫ����Ϣ
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
* ɾ�����ڱ��н�������Ϣɾ��
* @param &L		˳���
* @param i		�������
*/
Status ListDelete(SqList& L, int i) {
	if ((i < 1) || (i > L.length))
		return ERROR;
	for (int j = i; j <= L.length; j++)
		L.e[j - 1] = L.e[j];
	L.length--;
	return OK;
}
