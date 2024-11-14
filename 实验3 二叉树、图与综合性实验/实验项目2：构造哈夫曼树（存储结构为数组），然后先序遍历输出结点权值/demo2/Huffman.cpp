/*****************************************************************//**
 * \file   Huffman.cpp
 * \brief
 *
 * \author ������
 * \date   November 2024
 *********************************************************************/
#include"Huffman.h"

 /**
  * ��HT[k]��ѡ������˫����Ϊ0��Ȩֵ��С�Ľ�㣬����������HT�е����s1 s2.
  * @param HT
  * @param len
  * @param s1
  * @param s2
  */
void Select(HuffmanTree HT, int len, int& s1, int& s2) {
	int i;
	int min = INT_MAX;
	for (i = 1; i <= len; i++) {
		if (HT[i].weight < min && HT[i].parent == 0) {
			min = HT[i].weight;
			s1 = i;
		}
	}
	int temp = HT[s1].weight;
	HT[s1].weight = INT_MAX;
	min = INT_MAX;
	for (i = 1; i <= len; i++) {
		if (HT[i].weight < min && HT[i].parent == 0) {
			min = HT[i].weight;
			s2 = i;
		}
	}
	HT[s1].weight = temp;
}

/**
 * �����������.
 * @param HT
 * @param n
 */
void CreateHuffmanTree(HuffmanTree& HT, int n) {
	//��ʼ��
	if (n <= 1)
		return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (int i = 1; i <= m; i++) {
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	//����HuffmanTree
	cout << "������Ҷ�ӽ���Ȩֵ��" << endl;
	for (int i = 1; i <= n; i++)
		cin >> HT[i].weight;
	int s1, s2;
	for (int i = n + 1; i <= m; i++) {
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;	HT[s2].parent = i;
		HT[i].lchild = s1;	HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

/**
 * �������HuffmanTree.
 * @param HT
 * @param i
 */
void PreOrderTraverse_HT(HuffmanTree HT, int i) {
	if (i == 0)
		return;
	else {
		cout << HT[i].weight << " ";
		PreOrderTraverse_HT(HT, HT[i].lchild);
		PreOrderTraverse_HT(HT, HT[i].rchild);
	}
}

/**
 * ����HuffmanTree��n���ַ���
 * Huffman���룬���洢��HC.
 * @param HT	��������
 * @param HC	����������
 * @param n		�ַ�����
 */
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n) {
	HC = new char * [n + 1];			//���䶯̬�洢�ռ�
	char* cd = new char[n];
	cd[n - 1] = '\0';					//���������
	for (int i = 1; i <= n; i++) {
		int start = n - 1;				//start���ڼ�¼������cd�д��λ�ã���ʼ��ָ������������λ��
		int c = i;						//c���ڼ�¼��Ҷ�ӽ�����ϻ��ݵ�������������Ľ���±�
		int f = HT[i].parent;			//f���ڼ�¼i��˫�׽����±�
		while (f != 0) {
			start--;
			if (HT[f].lchild == c)
				cd[start] = '0';		//c��f��lchild������Ϊ0
			else
				cd[start] = '1';		//c��f��rchild��������1
			c = f;						//����c f���������ϻ���
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];	//Ϊ��i���ַ��������洢�ռ�
		strcpy(HC[i], &cd[start]);		//copy����洢��HC
	}
	delete cd;							//�ͷ�cd
}

/**
 * ���Huffman������.
 * @param HT
 * @param HC
 */
void show_HuffmanCode(HuffmanTree HT, HuffmanCode HC) {
	int n = _msize(HC) / sizeof(HC[0]) - 1;
	cout << left << setw(6) << "ԭ��" << "HuffmanCode" << endl;
	for (int i = 1; i <= n; i++) {
		cout << left << setw(6) << HT[i].weight << HC[i] << endl;
	}
}
