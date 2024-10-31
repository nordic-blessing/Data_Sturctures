/*****************************************************************//**
 * \file   Index.h
 * \brief  
 * 
 * \author ������
 * \date   October 2024
 *********************************************************************/
#ifndef __INDEX_H__
#define __INDEX_H__

#include"main.h"

//���Ķ���˳��洢�ṹ
#define MAXLEN	255
typedef struct {
	char ch[MAXLEN + 1];
	int length;
}SString;

//���Ķ�ʽ�洢�ṹ
typedef struct {
	char* ch;
	int length;
}HString;

//������ʽ�洢�ṹ
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
