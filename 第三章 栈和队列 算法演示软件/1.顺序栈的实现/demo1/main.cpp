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
* 顺序栈初始化
* @param &S		操作栈
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
* 顺序栈入栈
* @param &S		操作栈
* @param e		新元素
* @return Status
*/
Status Push(SqStack& S, SElemType e) {
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}

/*
* 顺序栈出栈
* @param &S		操作栈
* @param &e		出栈元素
* @return Status
*/
Status 

