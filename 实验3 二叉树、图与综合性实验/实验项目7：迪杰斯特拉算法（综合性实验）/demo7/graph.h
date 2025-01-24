/*****************************************************************//**
 * \file   graph.h
 * \brief  
 * 
 * \author 李宇瑞
 * \date   November 2024
 *********************************************************************/
#ifndef __GRAPH__H__
#define __GRAPH__H__

#include"main.h"

//=================图的邻接矩阵存储表示=================//
#define MVNum	20			//最大顶点数

typedef char VerTexType;	//顶点的数据类型为字符
typedef int ArcType;		//边权值的数据类型为整型
typedef struct {
	VerTexType vexs[MVNum];			//顶点表
	ArcType arcs[MVNum][MVNum];		//邻接矩阵
	int vexnum, arcnum;				//图当前的点数和边数
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
