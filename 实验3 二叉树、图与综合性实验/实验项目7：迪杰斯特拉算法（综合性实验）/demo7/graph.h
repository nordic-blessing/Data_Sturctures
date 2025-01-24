/*****************************************************************//**
 * \file   graph.h
 * \brief  
 * 
 * \author ������
 * \date   November 2024
 *********************************************************************/
#ifndef __GRAPH__H__
#define __GRAPH__H__

#include"main.h"

//=================ͼ���ڽӾ���洢��ʾ=================//
#define MVNum	20			//��󶥵���

typedef char VerTexType;	//�������������Ϊ�ַ�
typedef int ArcType;		//��Ȩֵ����������Ϊ����
typedef struct {
	VerTexType vexs[MVNum];			//�����
	ArcType arcs[MVNum][MVNum];		//�ڽӾ���
	int vexnum, arcnum;				//ͼ��ǰ�ĵ����ͱ���
}AMGraph;
//=======================END======================//

int Locate_Vex(AMGraph G, char u);
int CreateUDN(AMGraph& G);
int CreateDN(AMGraph& G);
int showUDN(AMGraph G);
void DFS_AM(AMGraph G, int v);
void ShortestPath_DIJ(AMGraph G, int v0);
int show_ShortestPath(AMGraph G, int v);

#endif // !__GRAPH__H__
