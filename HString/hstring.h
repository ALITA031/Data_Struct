#ifndef __HSTRING_H__
#define __HSTRING_H__

#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>
#include<stdbool.h>

typedef struct hstring
{
	char* ch;
	int length;
} hstring;

void init_string(hstring* s);

void str_assign(hstring* s,char* str);

void print_string(hstring* s);

int str_length(hstring* s);

void str_copy(hstring *s,hstring* t);

bool str_empty(hstring *s);

int str_compare(hstring* s,hstring* t);

void str_concat(hstring* s,hstring* t1,hstring* t2);

void sub_string(hstring* s,hstring* t,int pos,int len);

void str_insert(hstring* s,int pos,hstring* t);

void str_delete(hstring* s,int pos,int len);

void str_clear(hstring* s);

int str_find(hstring* s,hstring* t,int pos);

void str_replace(hstring* s,hstring* t,hstring* v);
























#endif //__HSTRING_H__
