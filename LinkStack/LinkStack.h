#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define ElemType int

typedef struct StackNode
{
	ElemType data;
	struct StackNode* next;
} StackNode;

typedef StackNode* LinkStack;

void InitLinkStack(LinkStack* s);

StackNode* buy_node(ElemType x);

void Push(LinkStack *s,ElemType x);

void Show(LinkStack s);

void Pop(LinkStack* s);

























#endif //LINKSTACK_H__
