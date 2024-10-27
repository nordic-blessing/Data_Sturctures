/*****************************************************************//**
 * \file   Stack.h
 * \brief  
 * 
 * \author ¿Ó”Ó»
 * \date   October 2024
 *********************************************************************/
#ifndef __STACK_H__
#define __STACK_H__

#include"main.h"

#define MAXSIZE	100

typedef char SElemType;
typedef int Status;

typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

Status InitStack(SqStack& S);
Status Push(SqStack& S, SElemType e);
Status Pop(SqStack& S, SElemType& e);
SElemType GetTop(SqStack S);
Status PrintStack(SqStack S);

#endif // !__STACK_H__
