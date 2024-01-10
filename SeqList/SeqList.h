#ifndef _SEQLIST_H
#define _SEQLIST_H

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>

#define SEQLIST_INIT_SIZE 10
#define INC_SIZE 2 

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

void delete_val(SeqList *list,ElemType x);

void sort(SeqList *list);

void reverse(SeqList *list);

void clear(SeqList *list);

void destory(SeqList *list);

bool inc(SeqList *list);

void merge(SeqList *list,SeqList *list1,SeqList *list2);



















#endif //_SEQLIST_H
