/*****************************************************************//**
 * \file   graph.cpp
 * \brief  
 * 
 * \author 李宇瑞
 * \date   November 2024
 *********************************************************************/
#include"graph.h"

/**
 * 确定顶点u在图G中的位置.
 * @param G
 * @param u
 * @return 
 */
int Locate_Vex(AMGraph G, VerTexType u) {
	for (int i = 0; i < G.vexnum; i++)
		if (u == G.vexs[i])
			return i;
	return -1;
}

/**
 * 采用邻接矩阵表示法，创建无向图·.
 * @param G
 * @return 
 */
int CreateUDN(AMGraph& G) {
	cout << "请输入总顶点数：";
	cin >> G.vexnum;
	cout << "请输入总边数：";
	cin >> G.arcnum;
	cout << "\n输入顶点的名称，如A" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		cout << "请输入第" << i + 1 << "个点的名称：";
		cin >> G.vexs[i];
	}
	for (int i = 0; i < G.vexnum; i++)				//初始化邻接矩阵、边的权值
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = 0;
	cout << "\n输入边依附的顶点，如A B" << endl;
	for (int k = 0; k < G.arcnum; k++) {
		char v1, v2;
		cout << "请输入第" << k + 1 << "条边依附的顶点：";
		cin >> v1 >> v2;
		int i = Locate_Vex(G, v1);	int j = Locate_Vex(G, v2);
		G.arcs[i][j] = 1;
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

/**
 * 输出邻接矩阵.
 * @param G
 * @return 
 */
int showUDN(AMGraph G) {
	cout << "生成邻接矩阵为：" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++)
			cout << setw(9) << left << G.arcs[i][j];
		cout << endl;
	}
	return OK;
}


/**
 * 深度优先搜索遍历连通图，采用邻接矩阵表示图.
 * @param G
 * @param v
 */
bool visited[MVNum];
void DFS_AM(AMGraph G, int v) {
	cout << G.vexs[v] << " ";
	visited[v] = true;
	for (int w = 0; w < G.vexnum; w++) {
		if ((G.arcs[v][w] != 0) && (!visited[w]))
			DFS_AM(G, w);
	}
}
