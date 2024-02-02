#ifndef __SPARSE_MATRIX_H__
#define __SPARSE_MATRIX_H__

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<memory.h>
#include<stdlib.h>

#define ElemType int
#define MAXSIZE 100

typedef struct triple
{
	int i,j;
	ElemType val;
} triple;

typedef struct smatrix
{
	int row,col;
	int nzero;
	triple data[MAXSIZE];
}smatrix;

void init_matrix(smatrix* sm);

void creat_matrix(smatrix *sm);

void print_matrix(smatrix* sm);

void copy_matrix(smatrix* sm,smatrix* sm1);

void add_matrix(smatrix* sm,smatrix* sm1,smatrix* t);

void sub_matrix(smatrix* sm,smatrix* sm1,smatrix* t);

void creat_matrix1(smatrix* sm);

void transpose_matrix(smatrix* sm,smatrix* t);

void fast_transpose_matrix(smatrix* sm,smatrix* t);




















#endif //__SPARSE_MATRIX_H__
