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
	if(list->size>=list->capacity&&!inc(list))
	{
		printf("The Space Is Full!,%d cant push_back\n",x);
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
	if(list->size>=SEQLIST_INIT_SIZE&&!inc(list))
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
	if(list->size>=list->capacity&&!inc(list))
	{
		printf("The Space Is Full,Cant Insert!\n");
		return;
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


void delete_pos(SeqList *list,int pos)
{
	if(pos<0||pos>=list->size)
		{
			printf("Error!\n");
			return ;
		}
	for(int i=pos;i<list->size;++i)
		{
			list->base[i]=list->base[i+1];
		}
	--list->size;
}


void delete_val(SeqList *list,ElemType x)
{
	int pos=find(*list,x);
	if(pos==-1)
	{
		printf("Error!\n");
		return ;	
	}	
	delete_pos(list,pos);
}

void sort(SeqList *list)
{
	if(list->size==0)
	{
		printf("Error!\n");
	return ;	
	}
	for(int i=list->size;i>0;--i)
	{
		for(int j=0;j<i-1;++j)
		{
			if(list->base[j]>list->base[j+1])
			{
				ElemType tmp=list->base[j];
				list->base[j]=list->base[j+1];
				list->base[j+1]=tmp;
			}
		}
	}
}

void reverse(SeqList *list)
{
	if(list->size==0)
	{
		printf("Error!\n");
		return ;
	}
	for(int i=0;i<list->size/2;i++)	
	{
		ElemType tmp=list->base[i];
		list->base[i]=list->base[list->size-1-i];
		list->base[list->size-1-i]=tmp;
	}
}

void clear(SeqList *list)
{
	list->size=0;
}

void destory(SeqList *list)
{
	clear(list);
	free(list);
}


bool inc(SeqList *list)
{
	ElemType *newbase=(ElemType *)realloc(list->base,sizeof(list->capacity+INC_SIZE));
	if(newbase==NULL)
	{
		printf("The Space is Full,Cant Inc\n");
		return false;
	}
	list->base=newbase;
	list->capacity=SEQLIST_INIT_SIZE+INC_SIZE;
	return true;
}

void merge(SeqList *list,SeqList *list1,SeqList *list2)
{
	list->capacity=list1->capacity+list2->capacity;
	list->base=(ElemType *)malloc(sizeof(ElemType)*list->capacity);
	assert(list->base!=NULL);
	int indx=0;
	int indx1=0;
	int indx2=0;

	while(indx1<list1->size&&indx2<list2->size)
	{
		if(list1->base[indx1]<list2->base[indx2])
			list->base[indx++]=list1->base[indx1++];
		else
			list->base[indx++]=list2->base[indx2++];
	}


	while(indx1<list1->size)
	{
		list->base[indx++]=list1->base[indx1++];
	}

	while(indx2<list2->size)
	{
		list->base[indx++]=list2->base[indx2++];
	}
	list->size=list1->size+list2->size;
}

