#ifndef __DCLIST_H__
#define __DCLIST_H__

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define ElemType int

typedef struct Node
{
	ElemType data;
	struct Node*next;
	struct Node*prio;
} Node,*PNode;

typedef struct List
{
	PNode first;
	PNode last;
	size_t size;
} List;

PNode buy_node(ElemType x);

void InitDCList(List *list);

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

#endif //__DCLIST_H__
