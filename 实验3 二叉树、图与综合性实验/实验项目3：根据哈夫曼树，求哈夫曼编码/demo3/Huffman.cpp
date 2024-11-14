/*****************************************************************//**
 * \file   Huffman.cpp
 * \brief  
 * 
 * \author 李宇瑞
 * \date   November 2024
 *********************************************************************/
#include"Huffman.h"

/**
 * 在HT[k]中选择两个双亲域为0且权值最小的结点，返回他们在HT中的序号s1 s2.
 * @param HT
 * @param len
 * @param s1
 * @param s2
 */
void Select(HuffmanTree HT, int len, int &s1, int &s2) {
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
 * 构造哈夫曼树.
 * @param HT
 * @param n
 */
void CreateHuffmanTree(HuffmanTree& HT, int n) {
	//初始化
	if (n <= 1)
		return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (int i = 1; i <= m; i++) {
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	//创建HuffmanTree
	cout << "请输入叶子结点的权值：" << endl;
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
 * 先序遍历HuffmanTree.
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
