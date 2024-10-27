/*****************************************************************//**
 * \file   StackNode.cpp
 * \brief  
 * 
 * \author ÀîÓîÈğ
 * \date   October 2024
 *********************************************************************/
#include"StackNode.h"

/**
 * Á´Õ»µÄ³õÊ¼»¯.
 * @param S
 * @return 
 */
Status InitStack(LinkStack& S) {
	S = NULL;
	return OK;
}

/**
 * ÈëÕ».
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
 * ³öÕ».
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
 * È¡Õ»¶¥ÔªËØ.
 * @param S
 * @return 
 */
SElemType GetTop(LinkStack S) {
	if (S != NULL)
		return S->data;
}
