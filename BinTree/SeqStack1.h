#ifndef __SEQSTACK1_H__
#define __SEQSTACK1_H__

#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include"BinTree.h"


#define STACK_INIT_SIZE 1000
#define STACK_INC_SIZE 1000


enum Tag{L,R};

typedef struct stk_node
{
	BinTreeNode* ptr;
	enum Tag tag;
}stk_node;

#define elemtype stk_node*

typedef struct SeqStack
{
	elemtype *base;
	int capacity;
	int top;
} SeqStack;

void InitStack(SeqStack *s);

void Push(SeqStack *s,elemtype x);

int IsFull(SeqStack *s);

int IsEmpty(SeqStack *s);

void Show(SeqStack *s);

void Pop(SeqStack *s);

int GetTop(SeqStack *s,elemtype *x);

void Clear(SeqStack *s);

void Destory(SeqStack *s);

int Length(SeqStack *s);

//int Inc(SeqStack *s);


































#endif //__SEQSTACK1_H__
