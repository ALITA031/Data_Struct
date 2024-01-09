#include"SeqList.h"

void InitSeqList(SeqList *list)
{
	list->base=(ElemType*)malloc(sizeof(ElemType)*SEQLIST_INIT_SIZE);
	assert(list->base!=NULL);
	list->capacity=SEQLIST_INIT_SIZE;
	list->size=0;
}

void push_back(SeqList *list,ElemType x)
{
	if(list->size>=list->capacity)
	{
		printf("The Space Is Full!\n");
		return ;	
	}
	list->base[list->size]=x;
	++(list->size);
}

void show_list(SeqList list)
{
	for(int i=0;i<list.size;++i)
	{
		printf("%d ",list.base[i]);	
	}
	printf("\n");
}

void push_front(SeqList *list,ElemType x)
{
	if(list->size>=SEQLIST_INIT_SIZE)
	{
		printf("The Space Is Full\n");
		return ;	
	}
	for(int i=list->size;i>0;--i)
	{
		list->base[i]=list->base[i-1];	
	
	}
	list->base[0]=x;
	++list->size;

}

void pop_back(SeqList *list)
{
	if(list->size<=0)
	{
		printf("Error\n");
		return;
	}
	--list->size;

}

void pop_front(SeqList *list)
{
	if(list->size<=0)
	{
		printf("Error!\n");
		return ;
	}
	for(int i=0;i<list->size;++i)
	{
		list->base[i]=list->base[i+1];
	}
	--list->size;
}


void insert_pos(SeqList *list,ElemType x,int pos)
{
	if(pos<0||pos>list->size)
	{
		printf("Error!\n");
		return ;	
	}
	for(int i=list->size;i>pos;--i)
	{
		list->base[i]=list->base[i-1];
	
	}
	list->base[pos]=x;
	++list->size;
}


int find(SeqList list,ElemType x)
{
	for(int i=0;i<list.size;++i)
	{
		if(list.base[i]==x)
		return i;	
	}
	return -1;
}


int length(SeqList list)
{
	return list.size;
}
