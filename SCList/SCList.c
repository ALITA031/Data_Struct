#include"SCList.h"

PNode buy_node(ElemType x)
{
	PNode s=(PNode)malloc(sizeof(Node));
	assert(s!=NULL);
	s->data=x;
	s->next=NULL;
	return s;
}

void InitSCList(List *list)
{
	PNode s=(PNode)malloc(sizeof(Node));
	assert(s!=NULL);
	list->first=list->last=s;
	s->next=s;
	list->size=0;
}
void push_back(List *list,ElemType x)
{
	PNode s=buy_node(x);

	list->last->next=s;
	s->next=list->first;
	list->last=s;
	++(list->size);
}


void show_list(List *list)
{
	PNode p=list->first->next;
	while(p!=list->first)
	{
		printf("%d->",p->data);
		p=p->next;
	}
	printf("First. \n");
}

void push_front(List *list,ElemType x)
{
	PNode s=buy_node(x);

	s->next=list->first->next;
	list->first->next=s;	
	if(list->first==list->last)
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
	p->next=list->first;
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
	if(list->first->next==list->first)
	{
		list->last=list->first;
	}
	--(list->size);
}
void insert_val(List *list,ElemType x)
{
	PNode s=buy_node(x);

	PNode p=list->first;
	while(p->next!=list->first&&p->next->data<x)
	{
		p=p->next;
	}
	
	if(p->next==list->first)
	{
		s->next=p->next;
		p->next=s;
		list->last=s;
		list->size++;
		return ;
	}

	s->next=p->next;
	p->next=s;
	list->size++;
}
PNode find(List *list,ElemType x)
{
	PNode p=list->first->next;
	while(p!=list->first&&p->data!=x)
	{
		p=p->next;
	}
	return p;
}

size_t length(List *list)
{
	return list->size;
}

void delete_val(List *list,ElemType x)
{
	PNode p=list->first;
	while(p->next!=list->first&&p->next->data!=x)
	{
		p=p->next;
	}
	if(p==list->first&&p->next->data!=x)
	{
		printf("There is no num that you want to delete.\n");
		return ;
	}
	PNode tmp=p->next;
	p->next=p->next->next;
	free(tmp);

	if(p->next==list->first)
		list->last=p;
	list->size--;
}

void sort(List *list)
{
	if(list->size==0||list->size==1)
		return ;

	PNode s=list->first->next;
	PNode q=s->next;
	list->last->next=NULL;
	s->next=list->first;

	while(q!=NULL)
	{
		s=q;
		q=q->next;

		PNode p=list->first;
		
		while(p->next!=list->first&&p->next->data<s->data)
			p=p->next;
		
		if(p->next==list->first)
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
	PNode p=list->first->next;
	PNode q=p->next;
	list->last->next=NULL;
	list->last=p;
	list->last->next=list->first;

	while(q!=NULL)
	{
		p=q;
		q=q->next;

		p->next=list->first->next;
		list->first->next=p;
	}
}

void clear(List *list)
{
	if(list->size==0)
		return ;
	PNode p=list->first->next;
	PNode tmp;
	while(p!=list->first)
	{	
		tmp=p;
		p=p->next;
		free(tmp);
	}
	list->last=list->first;
	list->last->next=list->first;
	list->size=0;
}

void destory(List *list)
{
	clear(list);
	free(list->first);
	list->last=list->first=NULL;
	free(list);	
}
