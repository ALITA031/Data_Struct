#ifndef __SEQ_QUEUE_H__
#define __SEQ_QUEUE_H__

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define MAXSIZE 8

#define ElemType int

typedef struct seq_queue
{
	ElemType* base;
	int front;
	int rear;
	int size;
} seq_queue;

void init_queue(seq_queue* q);

void show_queue(seq_queue* q);

void en_queue(seq_queue* q,ElemType x);

void de_queue(seq_queue* q);

int length(seq_queue* q);

void get_head(seq_queue* q,ElemType *x);

void clear_queue(seq_queue* q);

void destory_queue(seq_queue* q);



























#endif //__SEQ_QUEUE_H__
