#ifndef __BINTREE_H__
#define __BINTREE_H__

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define ElemType char

typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode* left_child;
	struct BinTreeNode* right_child;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode* root;
	ElemType ref_val;
}BinTree;

void init_bintree(BinTree* bt,ElemType ref);

void create_bintree(BinTree* bt,BinTreeNode** t);
//void create_bintree(BinTree* bt,BinTreeNode** t,ElemType* str);

void pre_order(BinTreeNode* t);

void in_order(BinTreeNode* t);

void post_order(BinTreeNode* t);

void level_order(BinTree* bt);

int size(BinTreeNode* t);
void size_(BinTreeNode* t,int *cnt);

int height(BinTreeNode* t);

BinTreeNode* search(BinTreeNode* t,ElemType key);
BinTreeNode* search_level_order(BinTreeNode* t,ElemType key);

BinTreeNode* parent(BinTreeNode* b,BinTreeNode* key);

BinTreeNode* left(BinTreeNode* b);

BinTreeNode* right(BinTreeNode* b);

int empty(BinTree* bt);

void copy(BinTreeNode* bt,BinTreeNode** x);

void clear(BinTreeNode** t);




























#endif //__BINTREE_H__
