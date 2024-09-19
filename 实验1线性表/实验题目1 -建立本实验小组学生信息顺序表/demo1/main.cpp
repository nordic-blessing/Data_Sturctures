#include<iostream>
#include<string>        //���ڶ����ַ������ͱ���
#include<iomanip>       //���ڿ��������ʽ��Ŀǰ��ʱ���ò���
#include<cctype>
using namespace std;

/*******�����Ǻ궨��***************************/

#define OK 1         //�������״̬��,��ʾ��������ִ�гɹ�
#define ERROR 0      //�������״̬��,��ʾ��������ִ��ʧ��
					 //�����bool�ͱ���(ȡֵ:true,false)�����Բ��ú궨��OK��ERROR,����������̲ı���һ�£�������

#define OVERFLOW -1  //�������״̬��,��ʾ����ִ��ʱ���
					//��ע��VS��OVERFLOW�Ѿ����˺궨��,�������ض��壬��������Ϊ����̲ı���һ�£�

//#define ElemType Student //����Ԫ�����ͣ�����ʵ����Ҫȷ��������ΪStudent�ͣ��ں���������


#define MAXSIZE  5  //˳������󳤶ȣ�Ӧ����ʵ����Ҫȷ����ֵ��

#define Status int   //Status�Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬����(�ɸ���ʵ����Ҫѡ��Status������������ͣ�����Ϊint��)

/****************StatusҲ�������·�ʽ����***************************************/
//typedef int Status; //Status�Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬����(�ɸ���ʵ����Ҫѡ��Status������������ͣ�����Ϊint��)

/********���壨��ƣ����ݴ洢�ṹ����********************/
typedef struct
{
	int Snumber;  //ѧ��
	string name;  //����
	string major; //רҵ
}Student;


typedef struct SqList //��typedef�����Ͷ��壩�����������ݴ洢�ṹ(��һ���ṹ�壬�����Զ������ｫ��ȡ��ΪSqList,��˳����Ӣ����д)
{
	Student* e;      //eΪStudent������Ԫ�ش洢��ַָ�룬�������Student�ͽṹ������*e�Ļ���ַ
	int length;      //˳����е�ʵ�ʽ����������ʵ��ѡ��ѧ��������0 =< length =< MAXSIZE ��

}SqList;   //�Ժ������SqList��Ϊ���Զ������͵�������,��������������罫x����ΪSqList���ͣ�Sqlist x; x�ͳ�Ϊ�˽ṹ�����͵ı���



/******************************************/

int main() {
	//����Ļ���������
	Status InitList(SqList & L);                     //������������������1����ʼ��������һ���յ�˳���L��
	Status CreateList(SqList & L);                   //������������������2����������ѧ����������˳���L��
	Status GetElem(SqList L, int i, Student & e);
	int LocateElem(SqList L, string e);
	Status ListInsert(SqList & L, int i, Student e);
	Status ListDelete(SqList & L, int i);


	//======================================================================================
	void Choose_num(int& choose); //������������ʾ��ѡ������������

	SqList L;            //����һ������L��LΪSqList���ͣ���L��һ��SqList�ͽṹ��������ڲ������������ͱ�����Ա��e��length��



	int i = 1;   //������
	char temp;  //��ʱ�����ַ�����,��������������

	Student student_data;  //����Student���͵Ľṹ�����student_data	

	string name;         //���������ַ�������(���ڲ��Ҳ�����������Ҫ���ҵ�ѧ������)

	int flag_init = 0;   //˳����ʼ����־��0:δ��ʼ��,1:�ѳ�ʼ��
	int flag_create = 0; //˳�������־ 0:δ������1:�Ѵ���

	int choose;          //�����������ѡ����
	choose = -1;         //��ʼ��ѡ��ı��Ϊ-1��ʵ���޴˱�ţ�


	while (choose != 0)
	{

		Choose_num(choose);  //��ʾ��ѡ������������

		if (!cin)            //�ж������Ƿ�Ϊ����
		{
			cout << "\n�������ѡ���ŷ�����!����������\n";
			cin.clear();  //��������������־		  
			while ((temp = getchar()) != '\n');  //�����뵽������������һ��һ��Ĩȥ��ֱ�����з�Ϊֹ,Ҳ����cin.ignore(a,'\n')
			choose = -1;
			continue;
		}


		switch (choose)
		{
		case 0: break;  //�˳�

		case 1: //��ʼ��
			if (InitList(L)) // ����һ���յ�˳���L����ʼ��˳���
			{
				flag_init = 1; cout << "\n��ʼ���ɹ�!\n\n";
			} //���ó�ʼ���ɹ���־
			else
				cout << "\n��ʼ��ʧ��!\n\n";
			break;

		case 2: //����
			if (!flag_init) { cout << "\n��δ��ʼ��\n"; break; }
			if (flag_create) {
				cout << "\n�Ѵ������Ƿ����´��������ǣ�������Y >";
				char answer;
				cin >> answer;
				if (answer == 'y' || answer == 'Y');
				else break;
			}
			CreateList(L);   //��ѧ�����������˳���L������˳���
			if (L.length)
				flag_create = 1; //�����ɹ���־
			else
				flag_create = 0;
			break;

		case 3:  //ȡֵ
			if (!flag_create) { cout << "��δ����"; break; }
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

		case 4:   //����
		{
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

			break;

		case 5:   //����
		{
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

		case 6:   //ɾ��			     
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

		case 7:   //���
			if (!flag_create) { cout << "\n��δ����\n"; break; }
			cout << "\nѡ��ѧ������(��" << L.length << "��):\n";
			cout << left << setw(15) << "ѧ ��" << "\t"
				<< left << setw(15) << "�� ��" << "\t"
				<< left << setw(15) << "ר ҵ" << endl;

			for (i = 0; i < L.length; i++)
			{
				cout << left << setw(15) << L.e[i].Snumber << "\t"
					<< left << setw(15) << L.e[i].name << "\t"
					<< left << setw(15) << L.e[i].major << endl;
			}
			break;


		default:  cout << "\n�����Ŵ���!\n ";

		}//switch

	}//while

	return 0;
}//main
/***********************/
/***********************/
void Choose_num(int& choose)  //��ʾ��ѡ������������
{
	cout << "\n�����ݽṹ���㷨��ѡ����������Ӧ����:\n";
	cout << " 1.��ʼ�� 2.����  3.ȡֵ  4.����\n"
		<< " 5.����   6.ɾ��  7.���  0.�˳�\n";
	cout << "\n������ѡ��Ĳ������: ";

	cin >> choose;   //����ѡ��Ļ����������	
}


/************�����ǹ����������õĻ�����������(ʵ�����Ա�����������Ͷ���ĸ��ֻ�������)***********************/
/*************************************************************************************************************/
//��������1����ʼ��������һ���յ�˳���
Status InitList(SqList& L)  //�Զ���ĺ�����ʵ�ֳ������������ж���Ĳ�������ʼ�����ɲο��̲�P21
{  // ����һ���յ����Ա�L��L���������ж��壬 "&"����˼�����������ã������ڲ��ı�L��ֵ��������������������������ı���Ȼ��Ч           
   //Lǰ���������&���˺����ڲ��ı�L�������˺�����ͻ���Ч����ͬѧ����ҵ�˻��㲻�����㣬Ҫ�����������мǡ�

	L.e = new Student[MAXSIZE]; //Ϊ˳������һ����СΪMAXSIZE��������100��������ռ�,������ʼ��ַ������L�ĳ�Աe(e��ָ���ͱ�������ֵ�ǵ�ַ)
	if (!L.e) return ERROR;     //����ʧ�ܣ������ڴ�ռ䲻�㣩�����ؽ��״̬��ERROR,��Status=ERROR(��Status=0)
	L.length = 0;              //����ɹ���Ŀǰ��û�д���ѧ�����ݣ�ѧ��������ʼ��Ϊ0
	return OK;                 //���ط���ɹ�״̬�룬��Status=OK(��Status=1)
}

/***********************************************************************************************************/

//��������2����������ѧ��������������Ա�
Status CreateList(SqList& L)  //��ѧ�����������˳���L
{
	//  int student_number;//��������ѧ�ű���
   //string student_name;  //����������������
   //string student_major; //��������רҵ����



	L.length = 0; //��˼����û���������Ĳ���
	int i = 0; //���������i����¼ѧ����Ϣ�洢λ�ã���ʼ��Ϊ0����ʼλ�ã���1��ѧ����Ϣ����ڡ�λ��0��,��i��ѧ����Ϣ�����λ��"i-1"���мǣ�

	cout << "������ ѧ��  ����  רҵ (�ո������س�����, 0�˳�):\n\n";

	while (1)
	{
		if (L.length == MAXSIZE) { cout << "\n�γ̽�����������!���ܼ������롣"; return ERROR; }   //��return ERROR;���ɸ�Ϊ��exit(OVERFLOW);��

		//����:ѧ�š�������רҵ
		cin >> L.e[i].Snumber;
		if (!cin)
		{
			cout << "\nѧ�������������������\n";
			cin.clear();  //��������������־		  
			cin.ignore(500, '\n');  //�����뵽������������һ��һ��Ĩȥ��ֱ�����з�Ϊֹ		  
			continue;
		}
		if (L.e[i].Snumber == 0) break; //=0 means �˳�	

		cin >> L.e[i].name;
		if (!cin)
		{
			cout << "\n���������������������\n";
			cin.clear();  //��������������־		  
			cin.ignore(500, '\n');  //�����뵽������������һ��һ��Ĩȥ��ֱ�����з�Ϊֹ		  
			continue;
		}
		if (L.e[i].name == "0") break; //="0" means �˳�

		cin >> L.e[i].major;
		if (!cin)
		{
			cout << "\nרҵ�����������������\n";
			cin.clear();  //��������������־		  
			cin.ignore(500, '\n');  //�����뵽������������һ��һ��Ĩȥ��ֱ�����з�Ϊֹ		  
			continue;
		}
		if (L.e[i].major == "0") break; //="0" means �˳�		   

		L.length++;  //˳����ȼ�1����ʵ��ѡ��ѧ��������1��
		i++;         //e�����±��1           

	}
	if (L.length)
		cout << "\n�������!\n";
	else
		cout << "\n�˳�����\n";
	return OK;
}

/**************����Ϊ��˳�����δʵ�ֵĻ�������****************************************************/
/************************************************************************************************/
//��������3��ȡֵ�� ���ݸ�������ţ���ȡ����ŵ�ѧ����Ϣ��
//���ͬѧ����ʵ����д������Ӧ�޸�������,��ĳ������µ��ô˺���
Status GetElem(SqList L, int i, Student & e) {
	if (i<1 || i>L.length)
		return ERROR;
	e.name = L.e[i - 1].name;
	e.major = L.e[i - 1].major;
	e.Snumber = L.e[i - 1].Snumber;
	return OK;
}

/************************************************************************************************/
//��������4�����ң� ���ݸ���ѧ�����������Ҹ���ѧ���Ƿ��ڱ��У������ز��ҽ����
//���ͬѧ����ʵ����д������Ӧ�޸�������,��ĳ������µ��ô˺���
int LocateElem(SqList L, string name) {
	int i;
	for (i = 0; i < L.length; i++) {
		if (L.e[i].name == name)
			return i+1;
		return 0;
	}
}


/************************************************************************************************/
//��������5�����루������ѧ����Ϣ�������ָ��λ�ã�
//���ͬѧ����ʵ����д������Ӧ�޸�������,��ĳ������µ��ô˺���
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


/************************************************************************************************/
//��������6��ɾ���� �ڱ��н�������Ϣɾ����
//���ͬѧ����ʵ����д������Ӧ�޸�������,��ĳ������µ��ô˺���
Status ListDelete(SqList& L, int i) {
	if ((i < 1) || (i > L.length))
		return ERROR;
	for (int j = i; j <= L.length; j++)
		L.e[j - 1] = L.e[j];
	L.length--;
	return OK;
}





/*****************************/
