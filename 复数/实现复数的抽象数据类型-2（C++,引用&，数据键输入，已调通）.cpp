
//实现复数的抽象数据类型
#include<iostream>
using namespace std;

//复数的数据结构
typedef struct Complex
{
	float e1; // 实部
	float e2; // 虚部

}COMPLEX;  //复数的结构类型取名为COMPLEX
           //以后可以用COMPLEX定义数据类型（使用方式类似 int,char,float,double等）


int main(void)
{
	// 函数声明
	void CreatComplex(COMPLEX &C, float data1, float data2);  //构造一个复数(与教材的ADT一致)
	float GetReal(COMPLEX C);                        //返回复数C的实部
	float GetImag(COMPLEX C);                       //返回复数C的虚部
	COMPLEX Add(COMPLEX C1, COMPLEX C2);            //返回两个复数C1和C2之和
		
	COMPLEX C1;    //C1为COMPLEX类型
	COMPLEX C2;    //C2为COMPLEX类型
		
	float data1, data2;    //输入实部数据：data1，输入虚部数据：data2，
	
	cout << "请输入构造复数的实部和虚部数据：";
	cin >> data1 >> data2;
	CreatComplex(C1, data1, data2);   //构造复数C1
	cout << "复数C1的实部为:" << GetReal(C1) << ", 复数C1的虚部为：" << GetImag(C1) << endl;
	cout << "复数C1=" << GetReal(C1) << showpos << GetImag(C1) << noshowpos << "i\n" << endl;

	cout << "请输入构造复数的实部和虚部数据：";
	cin >> data1 >> data2;	
    CreatComplex( C2,data1, data2);   //构造复数C2
	cout << "复数C2的实部为:" << GetReal(C2) << ", 复数C2的虚部为：" << GetImag(C2) << endl;
	cout << "复数C2=" << GetReal(C2) << showpos << GetImag(C2) << noshowpos << "i\n" << endl;

	
	COMPLEX C3;                       //构造复数C3(参考：int i;   i=add(x1,x2);)
	C3 = Add(C1, C2);
	cout << "复数C3=C1+C2的实部为：" << C3.e1 << "，虚部为：" << C3.e2 << endl;
	cout << "复数C3=" << C3.e1 << showpos << C3.e2 << noshowpos << "i" << endl;
	
	return 0;
}


void CreatComplex(COMPLEX &C, float data1, float data2)   //构造一个复数C,其实部和虚部分别被赋予参数data1,data2
{
	
	C.e1 = data1;   //实部
	C.e2 = data2;  //虚部
	
}
float GetReal(COMPLEX C)      //复数C已存在，返回复数C的实部值
{
	float real = C.e1;
	return real;
}

float GetImag(COMPLEX C)     //复数C已存在，返回复数C的虚部值
{
	float image = C.e2;
	return image;
}

COMPLEX Add(COMPLEX C1, COMPLEX C2)     //返回两个复数C1和C2之和
{
	COMPLEX sum;
	float C1_e1, C2_e1;
	float C1_e2, C2_e2;

	C1_e1 = C1.e1;
	C2_e1 = C2.e1;

	C1_e2 = C1.e2;
	C2_e2 = C2.e2;

	sum.e1 = C1_e1 + C2_e1;
	sum.e2 = C1_e2 + C2_e2;

	return sum;
}
