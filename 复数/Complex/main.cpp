#include <stdio.h>

//实现复数的抽象数据类型

//复数的数据结构
typedef struct Complex
{
	float e1; // 实部
	float e2; // 虚部

}COMPLEX;  //复数的结构类型取名为COMPLEX
//以后可以用COMPLEX定义数据类型（使用方式类似 int,char,float,double等）

// 函数声明
COMPLEX CreatComplex(float data1, float data2);  //构造一个复数
float GetReal(COMPLEX C);                        //返回复数C的实部
float GetImag(COMPLEX C);                       //返回复数C的虚部
COMPLEX Add(COMPLEX C1, COMPLEX C2);            //返回两个复数C1和C2的和


int main(void)
{
	float data1 = -2.0, data2 = 3.0;    //构造第1个复数的数据
	float data3 = 5.0, data4 = -8.5;    //构造第2个复数的数据


	COMPLEX C1 = CreatComplex(data1, data2);   //构造复数C1
	COMPLEX C2 = CreatComplex(data3, data4);   //构造复数C2
	COMPLEX C3;                                //构造复数C3(参考：int i;   i=add(x1,x2);)
	C3 = Add(C1, C2);

	printf("复数C1的实部为：%3.1f,  复数C1的虚部为：%3.1f\n", GetReal(C1), GetImag(C1));
	printf("复数C1=%3.1f%+3.1fi\n\n", GetReal(C1), GetImag(C1));

	printf("复数C2的实部为：%3.1f,  复数C2的虚部为：%3.1f\n", GetReal(C2), GetImag(C2));
	printf("复数C2=%3.1f%+3.1fi\n\n", GetReal(C2), GetImag(C2));


	printf("复数C3=C1+C2的实部为：%3.1f，虚部为：%3.1f\n", C3.e1, C3.e2);
	printf("复数C3=%3.1f%+3.1fi\n\n", C3.e1, C3.e2);

	return 0;
}


COMPLEX CreatComplex(float data1, float data2)
{
	COMPLEX C;
	C.e1 = data1;   //实部
	C.e2 = data2;  //虚部
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
