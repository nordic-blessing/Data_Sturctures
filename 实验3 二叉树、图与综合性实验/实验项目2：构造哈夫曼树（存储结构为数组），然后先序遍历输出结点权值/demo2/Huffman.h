/*****************************************************************//**
 * \file   Huffman.h
 * \brief  
 * 
 * \author 李宇瑞
 * \date   October 2024
 *********************************************************************/
#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include"main.h"

typedef struct {
	int weight;					//结点的权值
	int parent, lchild, rchild;	//结点双亲和左右孩子的下标
}HTNode, * HuffmanTree;

typedef char** HuffmanCode;		//动态分配数组存储哈夫曼编码表

void CreateHuffmanTree(HuffmanTree& HT, int n);
void PreOrderTraverse_HT(HuffmanTree HT, int i);
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n);
void show_HuffmanCode(HuffmanTree HT, HuffmanCode HC);
#endif // !__HUFFMAN_H__
