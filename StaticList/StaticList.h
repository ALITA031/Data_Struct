#ifndef __STATICLIST_H__
#define __STATICLIST_H__

#include<stdio.h>
#include<malloc.h>
#include<assert.h>


#define MAX_SIZE 20
#define ElemType char

typedef struct ListNode
{
	ElemType data;
	int cur;
} ListNode;

typedef ListNode StaticList[MAX_SIZE];

void InitSList(ListNode list[]);

int Malloc_SL(ListNode list[]);

void ShowSList(ListNode list[]);

void Insert(ListNode list[],char x);

void Delete(ListNode list[]);

















#endif//__STATICLIST_H__
