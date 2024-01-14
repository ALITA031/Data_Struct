#include"DList.h"

PNode buy_node(ElemType x)
{
	PNode s=(PNode)malloc(sizeof(Node));
	assert(s!=NULL);
	s->next=s->prio=NULL;
	s->data=x;
	return s;
}


void InitDList(List *list)
{
	PNode s=(PNode)malloc(sizeof(Node));
	assert(s!=NULL);
	s->data=0;
	s->next=s->prio=NULL;
	list->last=list->first=s;
	list->size=0;
}

void push_back(List *list,ElemType x)
{
	PNode s=buy_node(x);
	list->last->next=s;
	s->prio=list->last;
	list->last=s;
	list->size++;
}

void show_list(List *list)
{
	PNode p=list->first->next;
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	}
	printf("Nul.\n");
}

void push_front(List *list,ElemType x)
{
	PNode s=buy_node(x);
	if(list->first==list->last)
	{
		s->prio=list->first;
		list->first->next=s;
		list->last=s;	
	}
	else
	{
		s->next=list->first->next;
		s->prio=list->first;
		s->next->prio=s;
		list->first->next=s;	
	}
	list->size++;
}

void pop_back(List *list)
{
	if(list->size==0)
	{
		printf("Error! \n");
		return ;	
	}
	PNode p=list->first;
	while(p->next!=list->last)
	{
		p=p->next;	
	}
	p->next=p->next->next;
	free(list->last);
	list->last=p;
	list->size--;
}

void pop_front(List *list)
{
	if(list->size==0)
	{
		printf("Error! \n");
		return ;	
	}
	if(list->size==1)
	{
		list->first->next=NULL;
		free(list->last);
		list->last=list->first;
	}
	else
	{
		PNode tmp=list->first->next;
		list->first->next=tmp->next;
		tmp->next->prio=list->first;
	}
	list->size--;
}

void insert_val(List *list,ElemType x)
{
	PNode p=list->first;
	PNode s=buy_node(x);
	while(p->next!=NULL&&p->next->data<x)
	{
		p=p->next;
	}
	
	if(p->next==NULL)
	{
		list->last->next=s;
		s->prio=list->last;
		list->last=s;
	}
	else
	{
		s->next=p->next;
		s->next->prio=s;
		s->prio=p;
		p->next=s;
	}
	list->size++;
}

PNode find(List *list,ElemType key)
{
	PNode p=list->first->next;
	while(p!=NULL&&p->data!=key)
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
	PNode p=find(list,x);
	if(p==NULL)
	{
		printf("Error !\n");
		return ;	
	}
	if(p==list->last)
	{
		p->prio->next=NULL;
		list->last=p->prio;	
	}
	else
	{
		p->next->prio=p->prio;
		p->prio->next=p->next;	
	}
	free(p);
	list->size--;
}

void sort(List *list)
{
	if(list->size==1||list->size==0)
	{
		return ;
	}
	PNode p=list->first->next;
	PNode q=p->next;
	list->last=p;
	p->next=NULL;
	q->prio=NULL;
	PNode tmp;
	while(q!=NULL)
	{
		p=q;
		q=q->next;
		tmp=list->first;
		while(tmp->next!=NULL&&tmp->next->data<p->data)
		{	
			tmp=tmp->next;
		}
		if(tmp->next==NULL)
		{
			p->next=NULL;
			p->prio=list->last;
			list->last->next=p;
			list->last=p;
		}

		p->next=tmp->next;
		p->next->prio=p;
		p->prio=tmp;
		tmp->next=p;		
	}
}

	void reverse(List *list)
{
		if(list->size==1||list->size==0)
		{
			return ;
		}	
		PNode p=list->first->next;
		PNode q=p->next;
		
		list->last=p;
		list->last->next=NULL;
		q->prio=NULL;
		
		while(q!=NULL)
		{
			p=q;
			q=q->next;
			p->next=list->first->next;
			p->next->prio=p;
			p->prio=list->first;
			list->first->next=p;
		}
}

void clear(List *list)
{
	if(list->size==0)
	{
		return ;
	}
	PNode p=list->first->next;
	while(p!=NULL)
	{
		if(p==list->last)
		{
			list->last=list->first;
			list->last->next=NULL;
		}
		else
		{
			p->next->prio=list->first;
			list->first->next=p->next;	
		}
		p=p->next;
	
	}
	
	free(p);
	list->size=0;
}

void destory(List *list)
{
	clear(list);
	free(list);

}





