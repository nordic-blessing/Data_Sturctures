/*****************************************************************//**
 * \file   Index.h
 * \brief  
 * 
 * \author 李宇瑞
 * \date   October 2024
 *********************************************************************/
#ifndef __INDEX_H__
#define __INDEX_H__

#include"main.h"

//串的定长顺序存储结构
#define MAXLEN	255
typedef struct {
	char ch[MAXLEN + 1];
	int length;
}SString;

//串的堆式存储结构
typedef struct {
	char* ch;
	int length;
}HString;

//串的链式存储结构
#define CHUNKSIZE	80
typedef struct Chunk {
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;
typedef struct {
	Chunk* head, * tail;
	int length;
}LString;

int StrAssign(char* chars, SString& T);
int Index_BF(SString S, SString T, int pos);

void get_next(SString T, int next[]);
void get_nextval(SString T, int next[]);
int Index_KMP(SString S, SString T, int pos, int mode);

#endif // !__Index_H__
