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

void CreateHuffmanTree(HuffmanTree& HT, int n);
void PreOrderTraverse_HT(HuffmanTree HT, int i);

#endif // !__HUFFMAN_H__

