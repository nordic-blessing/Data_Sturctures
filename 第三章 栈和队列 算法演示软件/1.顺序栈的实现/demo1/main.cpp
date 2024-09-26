#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 100
typedef int Status;
typedef char SElemType;

typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

/*
* ˳��ջ��ʼ��
* @param &S		����ջ
* @return Status
*/
Status InitStack(SqStack& S) {
	S.base = new SElemType[MAXSIZE];
	if (!S.base)
		return OVERFLOW;
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

/*
* ˳��ջ��ջ
* @param &S		����ջ
* @param e		��Ԫ��
* @return Status
*/
Status Push(SqStack& S, SElemType e) {
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}

/*
* ˳��ջ��ջ
* @param &S		����ջ
* @param &e		��ջԪ��
* @return Status
*/
Status 

