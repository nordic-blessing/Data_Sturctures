#include <stdio.h>

//ʵ�ָ����ĳ�����������

//���������ݽṹ
typedef struct Complex
{
	float e1; // ʵ��
	float e2; // �鲿

}COMPLEX;  //�����Ľṹ����ȡ��ΪCOMPLEX
//�Ժ������COMPLEX�����������ͣ�ʹ�÷�ʽ���� int,char,float,double�ȣ�

// ��������
COMPLEX CreatComplex(float data1, float data2);  //����һ������
float GetReal(COMPLEX C);                        //���ظ���C��ʵ��
float GetImag(COMPLEX C);                       //���ظ���C���鲿
COMPLEX Add(COMPLEX C1, COMPLEX C2);            //������������C1��C2�ĺ�


int main(void)
{
	float data1 = -2.0, data2 = 3.0;    //�����1������������
	float data3 = 5.0, data4 = -8.5;    //�����2������������


	COMPLEX C1 = CreatComplex(data1, data2);   //���츴��C1
	COMPLEX C2 = CreatComplex(data3, data4);   //���츴��C2
	COMPLEX C3;                                //���츴��C3(�ο���int i;   i=add(x1,x2);)
	C3 = Add(C1, C2);

	printf("����C1��ʵ��Ϊ��%3.1f,  ����C1���鲿Ϊ��%3.1f\n", GetReal(C1), GetImag(C1));
	printf("����C1=%3.1f%+3.1fi\n\n", GetReal(C1), GetImag(C1));

	printf("����C2��ʵ��Ϊ��%3.1f,  ����C2���鲿Ϊ��%3.1f\n", GetReal(C2), GetImag(C2));
	printf("����C2=%3.1f%+3.1fi\n\n", GetReal(C2), GetImag(C2));


	printf("����C3=C1+C2��ʵ��Ϊ��%3.1f���鲿Ϊ��%3.1f\n", C3.e1, C3.e2);
	printf("����C3=%3.1f%+3.1fi\n\n", C3.e1, C3.e2);

	return 0;
}


COMPLEX CreatComplex(float data1, float data2)
{
	COMPLEX C;
	C.e1 = data1;   //ʵ��
	C.e2 = data2;  //�鲿
	return C;
}
float GetReal(COMPLEX C)
{
	return C.e1;
}

float GetImag(COMPLEX C)
{
	return C.e2;
}

COMPLEX Add(COMPLEX C1, COMPLEX C2)
{
	COMPLEX sum;

	sum.e1 = C1.e1 + C2.e1;
	sum.e2 = C1.e2 + C2.e2;

	return sum;
}
