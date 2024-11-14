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
 * ����ڽӾ���.
 * @param G
 * @return 
 */
int showUDN(AMGraph G) {
	cout << "�����ڽӾ���Ϊ��" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++)
			cout << setw(9) << left << G.arcs[i][j];
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
