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


#endif //_SEQLIST_H
