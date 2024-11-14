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
Status LocateVex(AMGraph G, VerTexType u) {
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
	cout << "\n���붥������ƣ���V1" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		cout << "�������" << i + 1 << "��������ƣ�";
		cin >> G.vexs[i];
	}
	for (int i = 0; i < G.vexnum; i++)				//��ʼ���ڽӾ��󡢱ߵ�Ȩֵ
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = INT16_MAX;
	cout << "\n����������Ķ��㼰Ȩֵ����V1 V2 3" << endl;
	for (int k = 0; k < G.arcnum; k++) {
		char v1, v2;
		int w;
		cout << "�������" << k + 1 << "���������Ķ��㼰Ȩֵ��";
		cin >> v1 >> v2 >> w;
		int i = LocateVex(G, v1);	int j = LocateVex(G, v2);
		G.arcs[i][j] = w;
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
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++)
			cout << setw(9) << left << G.arcs[i][j];
		cout << endl;
	}
	return OK;
}
