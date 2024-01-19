#ifndef __LINK_QUEEN_H__
#define __LINK_QUEEN_H__

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define ElemType int

typedef struct queue_node
{
	ElemType data;
	struct queue_node* next;
} queue_node;

typedef struct link_queue
{
	queue_node* front;
	queue_node* tail;
	int size;
} link_queue;

void init_queue(link_queue* q);

void en_queue(link_queue* q,ElemType x);

queue_node* buy_node(ElemType x);

void show(link_queue* q);

void de_queue(link_queue* q);

void get_head(link_queue* q,ElemType* x);

int length(link_queue* q);

void clear_queue(link_queue* q);

void destory_queue(link_queue* q);

#endif //__LINK_QUEEN_H__
