#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include"BinTree.h"

#define Elemtype BinTreeNode*

#define STACK_INIT_SIZE 1000
#define STACK_INC_SIZE 1000

typedef struct seq_stack
{
	Elemtype *base;
	int capacity;
	int top;
} seq_stack;

void init_stack(seq_stack *s);

void push(seq_stack *s,Elemtype x);

int is_full(seq_stack *s);

int is_empty(seq_stack *s);

void show_(seq_stack *s);

void pop(seq_stack *s);

int get_top(seq_stack *s,Elemtype *x);

void clear_(seq_stack *s);

void destory_(seq_stack *s);

int length_(seq_stack *s);

//int Inc(seq_stack *s);


































#endif //__SEQSTACK_H__
