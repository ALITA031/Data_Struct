#include"SList.h"

void InitList(List *list)
{
	list->first=list->last=(PNode)malloc(sizeof(Node));
	assert(list->first!=NULL);
	list->size=0;
}
