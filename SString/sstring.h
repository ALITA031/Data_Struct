#ifndef  __SSTRING_H__
#define __SSTRING_H__

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>

#define MAXSTRLEN 255
#define u_char unsigned char
typedef u_char sstring[MAXSTRLEN+1];

void init_string(sstring s);

void str_assign(sstring s,u_char* x);

void str_copy(sstring s,sstring t);

int str_empty(sstring s);

int str_compare(sstring s,sstring t);

int str_length(sstring s);

void str_concat(sstring s1,sstring s2,sstring t);

void sub_string(sstring s,sstring sub,int pos,int len);

void str_index(sstring s,sstring t,int pos);

void str_replace(sstring s,sstring t,sstring v);

void str_insert(sstring s,int pos,sstring t);

void str_delete(sstring s,int pos,int len);

void str_clear(sstring s);

void print_string(sstring s);
#endif //__SSTRING_H__
