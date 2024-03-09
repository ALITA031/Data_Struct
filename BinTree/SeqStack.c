#include"SeqStack.h"

void init_stack(seq_stack *s)
{
	s->base=(Elemtype *)malloc(sizeof(Elemtype));
	assert(s!=NULL);
	s->capacity=STACK_INIT_SIZE;
	s->top=0;
}

int is_full(seq_stack *s)
{
	if(s->top<s->capacity)
		return 0;
	return 1;
}

int is_empty(seq_stack *s)
{
	if(s->top==0)
		return 1;
	return 0;
}


void push(seq_stack *s,Elemtype x)
{
	if(is_full(s))
	{
		printf("FULL!\n");
		return ;
	}
	s->base[s->top++]=x;
}

void show_(seq_stack *s)
{
	for(int i=s->top-1;i>=0;--i)
	{
		printf("%p->",s->base[i]);
	}
	printf("base.\n");
}

void pop(seq_stack *s)
{
	if(is_empty(s))
	{
		printf("IsEmpty.\n");
		return;
	}
	s->top--;
}

int get_top(seq_stack *s,Elemtype *x)
{
	if(is_empty(s))
	{
		printf("IsEmpty.\n");
		return 0;
	}
	*x=s->base[s->top-1];
	return 1;
}

int length_(seq_stack*s)
{
	return s->top;
}

void clear_(seq_stack *s)
{
	s->top=0;
}

void destory_(seq_stack *s)
{
	free(s->base);
	s->base=NULL;
	s->top=0;
}

int inc_(seq_stack *s)
{
	Elemtype *newbase=(Elemtype *)realloc(s->base,sizeof(Elemtype)*(s->capacity+STACK_INC_SIZE));
	if(newbase==NULL)
	{
		printf("Can not realloc.\n");
		return 0;
	}
	s->base=newbase;
	s->capacity=s->capacity+STACK_INC_SIZE;
	return 1;
}
