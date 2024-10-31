/*****************************************************************//**
 * \file   StackNode.cpp
 * \brief  
 * 
 * \author ������
 * \date   October 2024
 *********************************************************************/
#include"StackNode.h"

/**
 * ��ջ�ĳ�ʼ��.
 * @param S
 * @return 
 */
Status InitStack(LinkStack& S) {
	S = NULL;
	return OK;
}

/**
 * ��ջ.
 * @param S
 * @param e
 * @return 
 */
Status Push(LinkStack& S, SElemType e) {
	StackNode* p;
	p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}

/**
 * ��ջ.
 * @param S
 * @param e
 * @return 
 */
Status Pop(LinkStack& S, SElemType& e) {
	StackNode* p;
	if (S == NULL)
		return ERROR;
	e = S->data;
	p = S;
	S = S->next;
	delete p;
	return OK;
}

/**
 * ȡջ��Ԫ��.
 * @param S
 * @return 
 */
SElemType GetTop(LinkStack S) {
	if (S != NULL)
		return S->data;
}
