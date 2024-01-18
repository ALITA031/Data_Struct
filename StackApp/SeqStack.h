#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

#define ElemType int 

#define STACK_INIT_SIZE 50
#define STACK_INC_SIZE 3

typedef struct SeqStack
{
	ElemType *base;
	int capacity;
	int top;
} SeqStack;

void InitStack(SeqStack *s);

void Push(SeqStack *s,ElemType x);

int IsFull(SeqStack *s);

int IsEmpty(SeqStack *s);

void Show(SeqStack *s);

void Pop(SeqStack *s);

int GetTop(SeqStack *s,ElemType *x);

void Clear(SeqStack *s);

void Destory(SeqStack *s);

int Length(SeqStack *s);

//int Inc(SeqStack *s);


































#endif //__SEQSTACK_H__
