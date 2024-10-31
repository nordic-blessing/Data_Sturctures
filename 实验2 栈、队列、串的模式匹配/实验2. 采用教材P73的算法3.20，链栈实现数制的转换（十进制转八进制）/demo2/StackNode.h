/*****************************************************************//**
 * \file   StackNode.h
 * \brief  
 * 
 * \author ¿Ó”Ó»
 * \date   October 2024
 *********************************************************************/
#ifndef __STACKNODE_H__
#define __STACKNODE_H__

#include"main.h"

#define ElemType	int
#define SElemType	int
#define Status		int

typedef struct StackNode {
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

Status InitStack(LinkStack& S);
Status Push(LinkStack& S, SElemType e);
Status Pop(LinkStack& S, SElemType& e);
SElemType GetTop(LinkStack S);

#endif // !__STACKNODE_H__
