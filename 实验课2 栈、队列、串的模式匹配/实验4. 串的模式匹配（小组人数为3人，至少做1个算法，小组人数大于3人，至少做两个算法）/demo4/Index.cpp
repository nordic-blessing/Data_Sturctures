/*****************************************************************//**
 * \file   Index.cpp
 * \brief  
 * 
 * \author 李宇瑞
 * \date   October 2024
 *********************************************************************/
#include"Index.h"

/**
 * 将chars转化为串T.
 * @param chars
 * @param T
 * @return	返回操作状态
 */
int StrAssign(char *chars, SString& T) {
	int i = 0;
	if (strlen(chars) > MAXLEN)
		return ERROR;
	while (chars[i] != '\0') {
		T.ch[i] = *(chars + i);
		i++;
	}
	T.length = i;
	return OK;
}

/**
 * BF算法.
 * @param S
 * @param T
 * @param pos
 * @return		返回模式T在主串S中第pos个字符开始第一次出现的位置。若不存在，返回-1
 */
int Index_BF(SString S, SString T, int pos) {
	int i = pos - 1 ;
	int j = 0;
	while (i < S.length && j < T.length) {
		if (S.ch[i] == T.ch[j]) {
			cout << S.ch[i] << "==" << T.ch[j] << endl;
			i++;
			j++;
			cout << "next T letter" << endl;
		}
		else{
			cout << S.ch[i] << "!=" << T.ch[j] << endl;
			i = i - j + 2;
			j = 0;
			cout << "next S letter" << endl;
		}
	}
	if (j == T.length) {
		cout << "匹配成功：";
		return i - T.length + 1;
	}
	else {
		cout << "匹配失败：" << endl;
		return -1;
	}
}

/**
 * 求T的next函数.
 * @param T
 * @param next
 */
void get_next(SString T, int next[]) {
	int m = 0, n = -1;
	next[0] = -1;	//初始化next[]
	while (m < T.length - 1) {
		if (n == -1 || T.ch[m] == T.ch[n]) {
			m++;
			n++;
			next[m] = n;
		}
		else {
			n = next[n];
		}
	}
}

/**
 * 求T的nextval函数.
 * @param T
 * @param nextval
 */
void get_nextval(SString T, int nextval[]) {
	int m = 0, n = -1;
	nextval[0] = -1;	//初始化nextval[]
	while (m < T.length - 1) {
		if (n == -1 || T.ch[m] == T.ch[n]) {
			m++;
			n++;
			if (T.ch[m] != T.ch[n])
				nextval[m] = n;
			else
				nextval[m] = nextval[n];
		}
		else {
			n = nextval[n];
		}
	}
}

/**
 * KMP算法（next or nextval）.
 * @param S
 * @param T
 * @param pos
 * @param mode		1:next		2:nextval
 * @return		返回模式T在主串S中第pos个字符开始第一次出现的位置。若不存在，返回-1
 */
int Index_KMP(SString S, SString T, int pos, int mode) {
	int i = pos - 1;
	int j = 0;
	int next[MAXLEN] = { 0 };
	switch (mode)
	{
	case 1:
		get_next(T, next);
		break;
	case 2:
		get_nextval(T, next);
		break;
	default:
		break;
	}
	while (i < S.length && j < T.length) {
		if (j==-1||S.ch[i] == T.ch[j]) {
			if (S.ch[i] == T.ch[j] && j != -1)
				cout << S.ch[i] << " == " << T.ch[j] << endl;
			i++;
			j++;
		}
		else {
			cout << S.ch[i] << " != " << T.ch[j] << endl;
			j = next[j];
		}
	}
	if (j == T.length) {
		cout << "匹配成功：";
		return i - T.length + 1;
	}
	else {
		cout << "匹配失败：";
		return -1;
	}
}
