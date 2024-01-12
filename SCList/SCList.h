#ifndef __SCLIST_H_
#define __SCLIST_H_

#define ElemType int
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node,*PNode;

typedef struct List
{
	PNode first;
	PNode last;
	int size;
}List;

void InitSCList(List *list);

void push_back(List *list,ElemType x);

void show_list(List *list);

void push_front(List *list,ElemType x);

void pop_back(List *list);

void pop_front(List *list);

void insert_val(List *list ,ElemType x);

PNode find(List *list,ElemType x);

size_t length(List *list);

void delete_val(List *list,ElemType x);

void sort(List *list);

void reverse(List *list);

void clear(List *list);

void destory(List *list);







#endif//__SCLIST_H_
