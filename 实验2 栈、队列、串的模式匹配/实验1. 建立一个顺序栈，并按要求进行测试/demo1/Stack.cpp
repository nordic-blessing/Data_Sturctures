/*****************************************************************//**
 * \file   Stack.cpp
 * \brief  
 * 
 * \author 李宇瑞
 * \date   October 2024
 *********************************************************************/
#include "Stack.h"

/**
 * 顺序栈初始化.
 * @param S
 * @return 
 */
Status InitStack(SqStack& S) {
	S.base = new SElemType[MAXSIZE];
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

/**
 * 入栈.
 * @param S
 * @param e
 * @return 
 */
Status Push(SqStack& S, SElemType e) {
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}

/**
 * 出栈.
 * @param S
 * @param e
 * @return 
 */
Status Pop(SqStack& S, SElemType& e) {
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}

/**
 * 取栈顶元素.
 * @param S
 * @return 
 */
SElemType GetTop(SqStack S) {
	if (S.top != S.base)
		return *(S.top - 1);
}
