#ifndef _SEQLIST_H
#define _SEQLIST_H

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define SEQLIST_INIT_SIZE 100

typedef int ElemType;

typedef struct SeqList
{
	ElemType *base;
	int capacity;
	int size;

}SeqList;

void InitSeqList(SeqList *list);

void push_back(SeqList *list,ElemType x);

void show_list(SeqList list);

void push_front(SeqList *list,ElemType x);

void pop_back(SeqList *list);

void pop_front(SeqList *list);

void insert_pos(SeqList *list,ElemType x,int pos);

int find(SeqList list,ElemType x);

int length(SeqList list);

void delete_pos(SeqList *list,int pos);

#endif //_SEQLIST_H
