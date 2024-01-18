#include"SeqStack.h"

void InitStack(SeqStack *s)
{
	s->base=(ElemType *)malloc(sizeof(ElemType));
	assert(s!=NULL);
	s->capacity=STACK_INIT_SIZE;
	s->top=0;
}

int IsFull(SeqStack *s)
{
	if(s->top<s->capacity)
		return 0;
	return 1;
}

int IsEmpty(SeqStack *s)
{
	if(s->top==0)
		return 1;
	return 0;
}


void Push(SeqStack *s,ElemType x)
{
	if(IsFull(s))
	{
		printf("FULL!\n");
		return ;
	}
	s->base[s->top++]=x;
}

void Show(SeqStack *s)
{
	for(int i=s->top-1;i>=0;--i)
	{
		printf("%d->",s->base[i]);
	}
	printf("base.\n");
}

void Pop(SeqStack *s)
{
	if(IsEmpty(s))
	{
		printf("IsEmpty.\n");
		return;
	}
	s->top--;
}

int GetTop(SeqStack *s,ElemType *x)
{
	if(IsEmpty(s))
	{
		printf("IsEmpty.\n");
		return 0;
	}
	*x=s->base[s->top-1];
	return 1;
}

int Length(SeqStack*s)
{
	return s->top;
}

void Clear(SeqStack *s)
{
	s->top=0;
}

void Destory(SeqStack *s)
{
	free(s->base);
	s->base=NULL;
	s->top=0;
}

int Inc(SeqStack *s)
{
	ElemType *newbase=(ElemType *)realloc(s->base,sizeof(ElemType)*(s->capacity+STACK_INC_SIZE));
	if(newbase==NULL)
	{
		printf("Can not realloc.\n");
		return 0;
	}
	s->base=newbase;
	s->capacity=s->capacity+STACK_INC_SIZE;
	return 1;
}
