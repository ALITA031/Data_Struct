#include"SList.h"

void InitList(List *list)
{
	list->first=list->last=(PNode)malloc(sizeof(Node));
	list->first->next=list->last->next=NULL;
	assert(list->first!=NULL);
	list->size=0;
}

void push_back(List *list,ElemType x)
{
	PNode s=(PNode)malloc(sizeof(Node));
	assert(s!=NULL);
	s->data=x;
	s->next=NULL;

	list->last->next=s;
	list->last=s;
	++(list->size);
}


void show_list(List *list)
{
	PNode p=list->first->next;
	while(p)
	{
		printf("%d->",p->data);
		p=p->next;
	}
	printf("Nul. \n");
}

void push_front(List *list,ElemType x)
{
	PNode s=(PNode)malloc(sizeof(Node));
	assert(s!=NULL);
	s->data=x;
	s->next=list->first->next;
	list->first->next=s;
	
	if(list->size==0)
	{
		list->last=s;
	}
	++(list->size);
}

void pop_back(List *list)
{
	if(list->size==0)
	{
		printf("Error!\n");
		return ;
	}

	PNode p=list->first;
	while(p->next!=list->last)
	{
		p=p->next;
	}
	free(p->next);
	p->next=NULL;
	list->last=p;
	(--list->size);
}
	
void pop_front(List *list)
{
	if(list->size==0)
	{
		printf("Error.\n");
		return ;
	}

	PNode p=list->first->next;
	list->first->next=p->next;
	free(p);
	if(list->first->next==NULL)
	{
		list->last=list->first;
	}
	--(list->size);
}
void insert_val(List *list,ElemType x)
{
	PNode s=(PNode)malloc(sizeof(Node));
	assert(s!=NULL);
	s->data=x;
	s->next=NULL;

	PNode p=list->first;
	while(p->next!=NULL&&p->next->data<x)
	{
		p=p->next;
	}
	
	if(p==NULL)
	{
		push_back(list,x);	
		++(list->size);
		printf("%ld size \n",list->size);
		return ;
	}

	s->next=p->next;
	p->next=s;
}

PNode find(List *list,ElemType x)
{
	PNode p=list->first;
	while(p->next!=NULL&&p->next->data!=x)
	{
		p=p->next;
	}
	return p->next;
}

size_t length(List *list)
{
	return list->size;
}

void delete_val(List *list,ElemType x)
{
	PNode p=list->first;
	while(p->next!=NULL&&p->next->data!=x)
	{
		p=p->next;
	}
	if(p->next==NULL)
	{
		printf("There is no num that you want to delete.\n");
		return ;
	}
	PNode tmp=p->next;
	p->next=p->next->next;
	free(tmp);

	if(p->next==NULL)
		list->last=p;
	--(list->size);
}

void sort(List *list)
{
	if(list->size==0||list->size==1)
		return ;

	PNode s=list->first->next;
	PNode q=s->next;
	s->next=NULL;

	while(q!=NULL)
	{
		s=q;
		q=q->next;

		PNode p=list->first;
		
		while(p->next!=NULL&&p->next->data<s->data)
			p=p->next;
		
		if(p->next==NULL)
		{
			list->last=s;
		}
		s->next=p->next;
		p->next=s;
	}
}

void reverse(List *list)
{
	if(list->size==0||list->size==1)
		return ;
	PNode s=list->first->next;
	PNode q=s->next;
	s->next=NULL;
	list->last=list->first->next;

	while(q!=NULL)
	{
		s=q;
		q=q->next;

		s->next=list->first->next;
		list->first->next=s;
	}
}

void clear(List *list)
{
	if(list->size==0)
		return ;
	PNode p=list->first->next;
	PNode tmp;
	while(p!=NULL)
	{	
		tmp=p;
		p=p->next;
		free(tmp);
	}
	list->first->next=NULL;
	list->last=list->first;
	list->size=0;
}

void destory(List *list)
{
	clear(list);
	free(list->first);
	list->first=list->first=NULL;
	free(list);	
}
