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
 * 采用邻接矩阵表示法，创建有向图.
 * @param G
 * @return 
 */
int CreateDN(AMGraph& G) {
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
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = INT16_MAX;
			if (i == j)
				G.arcs[i][j] = 0;
		}
	cout << "\n输入边依附的顶点以及权值，如A B weight" << endl;
	for (int k = 0; k < G.arcnum; k++) {
		VerTexType v1, v2;
		ArcType weight;
		cout << "请输入第" << k + 1 << "条边依附的顶点：";
		cin >> v1 >> v2 >> weight;
		int i = Locate_Vex(G, v1);	int j = Locate_Vex(G, v2);
		G.arcs[i][j] = weight;
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
			if (G.arcs[i][j] != INT16_MAX)
				cout << setw(9) << left << G.arcs[i][j];
			else
				cout << setw(9) << left << "Inf";
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

/**
 * 用Dijkstra算法求最短路径.
 * @param G
 * @param v0	起点
 */
bool S[MVNum];
ArcType D[MVNum];
ArcType Path[MVNum];
void ShortestPath_DIJ(AMGraph G, int v0) {
	int n = G.vexnum;
	for (int v = 0; v < n; v++) {
		S[v] = false;
		D[v] = G.arcs[v0][v];
		if (D[v] < INT16_MAX)
			Path[v] = v0;
		else
			Path[v] = -1;
	}
	S[v0] = true;
	D[v0] = 0;

	for (int i = 0; i < n; i++) {
		int min = INT16_MAX;
		int v = v0;
		for (int w = 0; w < n; w++) {
			if (!S[w] && D[w] < INT16_MAX) {
				v = w;
				min = D[w];
			}
		}
		if (v == v0)
			return;
			S[v] = true;
			for (int w = 0; w < n; w++) {
				if (!S[w] && (D[v] + G.arcs[v][w] < D[w])) {
					D[w] = D[v] + G.arcs[v][w];
					Path[w] = v;
				}
			}
	}
}

/**
 * 输出最短路径（起点已确定）.
 * @param v		目标点
 */
int show_ShortestPath(AMGraph G,int v) {
	if (D[v] >= INT16_MAX)
		return -1;
	if (Path[v]) {
		show_ShortestPath(G, Path[v]);
	}
	cout << G.vexs[v] << " ";
	return D[v];
}
