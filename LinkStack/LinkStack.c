#include"LinkStack.h"

StackNode* buy_node(ElemType x)
{
	StackNode* s=(StackNode*)malloc(sizeof(StackNode));
	assert(s!=NULL);
	s->next=NULL;
	s->data=x;
	return s;
}

void InitLinkStack(LinkStack* s)
{
	*s=NULL;
}

void Push(LinkStack* s,ElemType x)
{
	if(*s==NULL)
	{
		*s=buy_node(x);
		return ;
	}
	StackNode *p=buy_node(x);
	p->next=*s;
	*s=p;
}


void Show(LinkStack s)
{
	StackNode* p=s;
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	}
	printf("top.\n");
}

void Pop(LinkStack *s)
{
	if(*s==NULL)
		return;
	StackNode* p=*s;
	*s=(*s)->next;
	free(p);
	p=NULL;
}
