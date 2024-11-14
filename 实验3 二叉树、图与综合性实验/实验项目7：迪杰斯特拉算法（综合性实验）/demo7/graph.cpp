/*****************************************************************//**
 * \file   graph.cpp
 * \brief  
 * 
 * \author ������
 * \date   November 2024
 *********************************************************************/
#include"graph.h"

/**
 * ȷ������u��ͼG�е�λ��.
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
 * �����ڽӾ����ʾ������������ͼ��.
 * @param G
 * @return 
 */
int CreateUDN(AMGraph& G) {
	cout << "�������ܶ�������";
	cin >> G.vexnum;
	cout << "�������ܱ�����";
	cin >> G.arcnum;
	cout << "\n���붥������ƣ���A" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		cout << "�������" << i + 1 << "��������ƣ�";
		cin >> G.vexs[i];
	}
	for (int i = 0; i < G.vexnum; i++)				//��ʼ���ڽӾ��󡢱ߵ�Ȩֵ
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = 0;
	cout << "\n����������Ķ��㣬��A B" << endl;
	for (int k = 0; k < G.arcnum; k++) {
		char v1, v2;
		cout << "�������" << k + 1 << "���������Ķ��㣺";
		cin >> v1 >> v2;
		int i = Locate_Vex(G, v1);	int j = Locate_Vex(G, v2);
		G.arcs[i][j] = 1;
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

/**
 * �����ڽӾ����ʾ������������ͼ.
 * @param G
 * @return 
 */
int CreateDN(AMGraph& G) {
	cout << "�������ܶ�������";
	cin >> G.vexnum;
	cout << "�������ܱ�����";
	cin >> G.arcnum;
	cout << "\n���붥������ƣ���A" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		cout << "�������" << i + 1 << "��������ƣ�";
		cin >> G.vexs[i];
	}
	for (int i = 0; i < G.vexnum; i++)				//��ʼ���ڽӾ��󡢱ߵ�Ȩֵ
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = INT16_MAX;
			if (i == j)
				G.arcs[i][j] = 0;
		}
	cout << "\n����������Ķ����Լ�Ȩֵ����A B weight" << endl;
	for (int k = 0; k < G.arcnum; k++) {
		VerTexType v1, v2;
		ArcType weight;
		cout << "�������" << k + 1 << "���������Ķ��㣺";
		cin >> v1 >> v2 >> weight;
		int i = Locate_Vex(G, v1);	int j = Locate_Vex(G, v2);
		G.arcs[i][j] = weight;
	}
	return OK;
}

/**
 * ����ڽӾ���.
 * @param G
 * @return 
 */
int showUDN(AMGraph G) {
	cout << "�����ڽӾ���Ϊ��" << endl;
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
 * �����������������ͨͼ�������ڽӾ����ʾͼ.
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
 * ��Dijkstra�㷨�����·��.
 * @param G
 * @param v0	���
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
 * ������·���������ȷ����.
 * @param v		Ŀ���
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
