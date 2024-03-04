#include"link_queue.h"

queue_node* buy_node(elemType x)
{
	queue_node* s=(queue_node*)malloc(sizeof(queue_node));
	assert(s!=NULL);
	s->next=NULL;
	s->data=x;
	return s;
}
void init_queue(link_queue* q)
{
	q->front=q->tail=(queue_node*)malloc(sizeof(queue_node));
	assert(q->tail!=NULL);
	q->size=0;
	q->front->next=NULL;
	q->front->data=0;
}

void en_queue(link_queue* q,elemType x)
{
	queue_node* s=buy_node(x);
	q->tail->next=s;
	q->tail=s;
	q->size+=1;
}

void show(link_queue* q)
{
	queue_node* s=q->front->next;
	while(s!=NULL)
	{
		printf("%p->",s->data);
		s=s->next;
	}
	printf("tail.\n");
}

void de_queue(link_queue* q)
{
	queue_node* p=q->front->next;
	if(p==NULL)
	{
		printf("Cant de_queue\b");
		return ;
	}
	q->front->next=p->next;
	free(p);
	q->size--;
	if(q->front->next==NULL)
		q->tail=q->front;
}

void get_head(link_queue* q,elemType* x)
{
	if(q->front->next==NULL)
	{
		printf("cant get_head.\n");
		return;
	}

	*x=q->front->next->data;
}

int length(link_queue* q)
{
	return q->size;
}


void clear_queue(link_queue* q)
{
	queue_node* p=q->front->next;
	while(p!=NULL)
	{
		q->front->next=p->next;
		free(p);
		p=q->front->next;
	}
	q->tail=q->front;
	q->size=0;
}

void destory_queue(link_queue* q)
{
	clear_queue(q);
	free(q->front);
	q->front=q->tail=NULL;
}
