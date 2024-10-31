#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define OK 1				//�ɹ�
#define ERROR 0				//ʧ��
#define OVERFLOW -1			//���
#define ElemType string		//����Ԫ������
#define Status int			//��������ֵ����

#define MAXSIZE 100			//˳������󳤶�
typedef struct SqList {
	ElemType* e;			//����ռ�Ļ���ַ
	int length;				//��ǰ����
}SqList;

int main() {
	Status InitList(SqList & L);						//��������1����ʼ��������һ���յ����Ա�L��
	Status CreateList(SqList & L);						//��������2����������ѧ�������������Ա�L��
	Status GetElem(SqList & L, int i, ElemType & e);	//��������3��ȡֵ�� ���ݸ�������ţ���ȡ����ŵ�ѧ��������
	Status LocateElem(SqList L, ElemType e);			//��������4�����ң� ���ݸ���ѧ�����������Ҹ���ѧ���Ƿ��ڱ��У������ز��ҽ����
	Status ListInsert(SqList & L, int i, ElemType & e);	//��������5�����루 ������ѧ������������ѡ��ѧ�����У���ָ������λ�ã�
	Status ListDelete(SqList & L, int i);				//��������6��ɾ���� ��ѧ����ѡ����ѡ��ѧ�����н���������ɾ����

	SqList L;
	while (1) {
		cout << "\n�����ݽṹ���㷨��ѡ����������Ӧ������" << endl;
		cout << setw(10) << "1.��ʼ��";	cout << setw(10) << "2.����";
		cout << setw(10) << "3.ȡֵ";	cout << setw(10) << "4.����";
		cout << endl;
		cout << setw(10) << "5.����";	cout << setw(10) << "6.ɾ��";
		cout << setw(10) << "7.���";	cout << setw(10) << "0.�˳�";
		cout << endl;
		cout << "������ѡ��Ĳ�����ţ�";
		int i;
		cin >> i;
		switch (i)
		{
			case 1:		//��ʼ��˳���
			{
				if (InitList(L))
					cout << "\n��ʼ���ɹ���\n\n";
			}
				break;
			case 2:		//����˳���
			{
				CreateList(L);
			}
				break;
			case 3:		//������Ų�������
			{
				cout << "������ȡֵ��� i :";
				int i;
				ElemType e;
				cin >> i;
				if (GetElem(L, i, e))
					cout << "\n" << L.e[i-1] << endl;
				else
					cout << "\n������Ų��Ϸ���\n";
			}
				break;
			case 4:		//���������������
			{
				cout << "������������";
				ElemType e;
				cin >> e;
				if (LocateElem(L, e)) {
					cout << "\n�鵽" << e << "��ţ�" << LocateElem(L, e);
				}
				else
					cout << "\nδ�鵽";
			}
				break;
			case 5:		//����
			{
				ElemType e;
				int i;
				cout << "���������ѧ��������";
				cin >> e;
				cout << "���������λ�ã�";
				cin >> i;
				if (ListInsert(L, i, e)) {
					cout << "\n����ɹ�\n";
				}
				else {
					cout << "\n����ʧ��\n";
				}
			}
			break;
			case 6:		//ɾ��
			{
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
			case 7:		//���
			{
				cout << "\nѡ��ѧ����������" << L.length << "������\n" << endl;
				for (int i = 0; i < L.length; i++) {
					cout << setw(3) << i + 1 << setw(10) << L.e[i] << endl;
				}
					cout << "\n\n";
			}
			break;
			case 0:		//�˳�
				return 0;
			default:
				break;
		}
	}
}

//��������1����ʼ��������һ���յ����Ա�L��
Status InitList(SqList& L) {
	L.e = new ElemType[MAXSIZE];		//Ϊ˳������һ����СΪMAXSIZE������ռ�
	if (!L.e)
		return ERROR;
	L.length = 0;						//�ձ���Ϊ0
	return OK;
}

//��������2����������ѧ�������������Ա�L��
Status CreateList(SqList &L) {
	string student_name;
	cout << "��ͨ����������ѧ���������Կո������س�������0�˳�����";
	cin >> student_name;

	int i = 0;
	while (student_name != "0") {
		if (L.length == MAXSIZE) {
			cout << "\n���������γ̽�������";
			return ERROR;
		}

		L.e[i++] = student_name;
		L.length++;

		if (cin.get() == '\n') {
			cout << "���������ѧ��������";
		}

		cin >> student_name;
	}

	cout << "����ѧ��ѡ�������ɹ���ѡ�ι� " << i << " ��\n\n";
	for (i = 0; i < L.length; i++)
		cout << L.e[i] << "\n";

	return OK;
}

//��������3��ȡֵ�� ���ݸ�������ţ���ȡ����ŵ�ѧ��������
Status GetElem(SqList& L, int i, ElemType& e) {
	if (i<1 || i>L.length)
		return ERROR;
	e = L.e[i - 1];
	return OK;
}

//��������4�����ң� ���ݸ���ѧ�����������Ҹ���ѧ���Ƿ��ڱ��У������ز��ҽ����
Status LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.e[i] == e)
			return i+1;
	}
	return 0;
}

//��������5�����루 ������ѧ������������ѡ��ѧ�����У���ָ������λ�ã�
Status ListInsert(SqList& L, int i, ElemType& e) {
	if (i<1 || i>L.length + 1)						//i ���Ϸ�
		return ERROR;
	if (L.length == MAXSIZE)						//��ǰ����ռ�����
		return ERROR;
	for (int j = L.length - 1; j >= i - 1; j--)
		L.e[j + 1] = L.e[j];						//����λ�ü�֮���Ԫ�غ���
	L.e[i - 1] = e;									//��Ԫ�� e ����� i ��λ��
	L.length++;										//�� +1
	return OK;
}

//��������6��ɾ���� ��ѧ����ѡ����ѡ��ѧ�����н���������ɾ����
Status ListDelete(SqList& L, int i) {
	if (i<1 || i>L.length)						//i ���Ϸ�
		return ERROR;
	for (int j = i; j <= L.length; j++)
		L.e[j - 1] = L.e[j];					//��ɾ��Ԫ��֮���Ԫ��ǰ��
	L.length--;
	return OK;
}