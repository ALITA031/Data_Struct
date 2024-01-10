#ifndef _SLIST_H_
#define _SLIST_H_

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define ElemType int

typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node,*PNode;

typedef struct List
{
	PNode first;
	PNode last;
	size_t size;

}List;

void InitList(List *list);













































#endif //_SList_H_
