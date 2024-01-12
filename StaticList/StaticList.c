#include"StaticList.h"
void InitSList(ListNode list[])
{
	list[0].cur=-1;
	for(int i=1;i<MAX_SIZE-1;++i)
	{
		list[i].cur=i+1;
	}
	list[MAX_SIZE-1].cur=0;
}
int Malloc_SL(ListNode list[])
{
	int i=list[1].cur;
	if(i!=0)
		list[1].cur=list[i].cur;
	return i;
}

void Insert(ListNode list[],char x)
{
	int i=Malloc_SL(list);
	if(i==0)
	{
		printf("Error!\n");
		return ;
	}
	list[i].data=x;
	if(list[0].cur==-1)
	{
		list[i].cur=-1;
		list[0].cur=i;
	}
	else
	{
		list[i].cur=list[0].cur;
		list[0].cur=i;
	}

}

void ShowSList(ListNode list[])
{
	int i=list[0].cur;
	while(i!=-1)
	{
		printf("%c->",list[i].data);
		i=list[i].cur;
	}
	printf("Nul\n");
}

void Delete(ListNode list[])
{
	int i=list[0].cur;
	if(i==-1)
	{
		printf("Error!\n");
		return ;
	}
	list[0].cur=list[i].cur;
	list[i].cur=list[1].cur;
	list[1].cur=i;
}


