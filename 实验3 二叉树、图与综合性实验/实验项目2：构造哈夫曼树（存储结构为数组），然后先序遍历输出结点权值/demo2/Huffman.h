/*****************************************************************//**
 * \file   Huffman.h
 * \brief  
 * 
 * \author ������
 * \date   October 2024
 *********************************************************************/
#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include"main.h"

typedef struct {
	int weight;					//����Ȩֵ
	int parent, lchild, rchild;	//���˫�׺����Һ��ӵ��±�
}HTNode, * HuffmanTree;

typedef char** HuffmanCode;		//��̬��������洢�����������

void CreateHuffmanTree(HuffmanTree& HT, int n);
void PreOrderTraverse_HT(HuffmanTree HT, int i);
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n);
void show_HuffmanCode(HuffmanTree HT, HuffmanCode HC);
#endif // !__HUFFMAN_H__
