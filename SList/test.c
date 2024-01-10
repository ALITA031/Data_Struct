#include<stdio.h>
#include<assert.h>
#include<malloc.h>

#define ElemType int

typedef struct ListNode
{
	ElemType data;
	struct ListNode *next;
} ListNode;

typedef ListNode * List;

void InitList(List *head)
{
	*head=NULL;
}

void CreateList_front(List *head)
{
	*head=(ListNode *)malloc(sizeof(ListNode));
	assert(*head!=NULL);
	(*head)->data=0;
	(*head)->next=NULL;
		
	for(int i=1;i<=10;i++)
	{
		ListNode *tmp=(ListNode *)malloc(sizeof(ListNode));
		assert(tmp!=NULL);
		tmp->data=i;
		tmp->next=*head;
		*head=tmp;
	}
}





void CreateList_back(List *head)
{
	*head=(List)malloc(sizeof(ListNode));
	assert(*head!=NULL);	
	(*head)->data=0;
	(*head)->next=NULL;
	
	ListNode* rear=*head;
	for(int i=1;i<=10;i++)
	{
		ListNode *tmp=(ListNode*)malloc(sizeof(ListNode));
		assert(tmp!=NULL);
		tmp->data=i;
		tmp->next=NULL;

		rear->next=tmp;
		rear=tmp;
	}
}

void showlist(List head)
{
	ListNode *p=head;
	while(p!=NULL)
	{
		printf("%d-->",p->data);
		p=p->next;
	}
	printf("nul \n");
}
int main()
{
	List mylist1,mylist2;
	InitList(&mylist1);
	InitList(&mylist2);
	CreateList_back(&mylist1);
	CreateList_front(&mylist2);
	showlist(mylist1);
	showlist(mylist2);
	return 0;
}	


