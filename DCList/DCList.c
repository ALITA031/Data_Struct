#include"DCList.h"

PNode buy_node(ElemType x)
{
	PNode s=(PNode)malloc(sizeof(Node));
	assert(s!=NULL);
	s->next=s->prio=NULL;
	s->data=x;
	return s;
}

void InitDCList(List *list)
{
	PNode s=(PNode)malloc(sizeof(Node));
	assert(s!=NULL);
	s->data=0;
	list->last=list->first=s;
	list->last->next=list->first;
	list->last->prio=list->last;
	list->size=0;
}

void push_back(List *list,ElemType x)
{
	PNode s=buy_node(x);
	list->first->prio=list->last;
	list->last->next=s;
	s->next=list->first;
	s->prio=list->last;
	list->last=s;
	list->size++;
}

void show_list(List *list)
{
	PNode p=list->first->next;
	while(p!=list->first)
	{
		printf("%d->",p->data);
		p=p->next;
	}
	printf("First.\n");
}

void push_front(List *list,ElemType x)
{
	/*PNode s=buy_node(x);
	if(list->size==0)
	{
		list->first->next=s;
		s->next=list->first;
		s->prio=list->first;
		list->last=s;
		list->first->prio=s;
	}
	else
	{
		s->next=list->first->next;
		s->next->prio=s;
		s->prio=list->first;
		list->first->next=s;
	}
	list->size++;	
    */
	PNode s=buy_node(x);
	s->next=list->first->next;
	s->next->prio=s;
	s->prio=list->first;
	list->first->next=s;
	if(list->first==list->last)
		list->last=s;
	list->size++;
}

void pop_back(List *list)
{
/*	if(list->first==list->last)
	{
		printf("Error!\n");
		return ;	
	}
	if(list->size==1)
	{
		free(list->last);
		list->first->next=list->first;
		list->first->prio=list->first;
		list->last=list->first;
		list->size--;
		return ;
	}
	else
	{
		PNode p=list->last;
		list->last=p->prio;
		
		p->prio->next=p->next;
		list->first->prio=p->prio;
		free(p);
		list->size--;
	}
*/
	if(list->size==0)
	{
		printf("Error!\n");
		return ;
	}

	PNode p=list->last;
	list->last=p->prio;

	p->prio->next=p->next;
	p->next->prio=p->prio;
	free(p);
	list->size--;
}

void pop_front(List *list)
{
	if(list->size==0)
	{
		printf("Error!\n");
		return ;
	}
	
	PNode p=list->first->next;
	p->next->prio=p->prio;
	p->prio->next=p->next;
	if(list->size==1)
		list->last=list->first;
	free(p);
	list->size--;
}

void insert_val(List *list, ElemType x)
{
	PNode p=list->first;
	while(p->next!=list->last&&p->next->data<x)
		p=p->next;
	if(p->next==list->last&&p->next->data<x)//BE CAREFULL!
		push_back(list,x);
	else
	{
		PNode s=buy_node(x);
		s->next=p->next;
		s->next->prio=s;
		p->next=s;
		list->size++;
	}
}

PNode find(List *list,ElemType x)
{
	if(list->size==0)
	return NULL;	
	PNode p=list->first->next;
	while(p!=list->first&&p->data!=x)
		p=p->next;
	if(p==list->first)
		return NULL;
	return p;
}

size_t length(List *list)
{
	return list->size;
}

void delete_val(List *list,ElemType x)
{
	if(list->size==0)
	{
		printf("Error!\n");
		return ;
	}
	PNode p=find(list,x);
	if(p==NULL)
	{
		printf("Error!\n");
		return ;
	}
	if(p==list->last)
		pop_back(list);
	else
	{
		p->next->prio=p->prio;
		p->prio->next=p->next;
		free(p);
		list->size--;
	}
}

void sort(List *list)
{
	if(list->size==0||list->size==1)
		return ;
	PNode s=list->first->next;
	PNode q=s->next;
	list->last->next=NULL;
	list->last=s;
	list->last->next=list->first;
	list->first->prio=list->last;
	
	PNode tmp=list->first;
	while(q!=NULL)
	{
		s=q;
		q=q->next;
		while(tmp->next!=list->last&&tmp->next->data<s->data)
			tmp=tmp->next;
		if(tmp->next==list->last&&tmp->next->data<s->data)
		{
			s->next=list->last->next;
			s->next->prio=s;
			s->prio=list->last;
			list->last->next=s;
			list->last=s;	
		}
		else
		{
			s->next=tmp->next;
			s->next->prio=s;
			s->prio=tmp;
			tmp->next=s;
		}		
		tmp=list->first;	
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
	q->prio=NULL;
	list->last->next=list->first;
	list->first->prio=p;

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
		return ;
	PNode p=list->first->next;
	while(p!=list->first)
	{
		p->next->prio=list->first;	
		list->first->next=p->next;
		free(p);
		p=list->first->next;
	}
	list->last=list->first;
	list->size=0;
}

void destory(List *list)
{
	clear(list);
	free(list);
}










































