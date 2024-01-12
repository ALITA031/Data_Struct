#include"SCList.h"
void InitSCList(List *list)
{
	PNode s=(PNode)malloc(sizeof(Node));
	assert(s!=NULL);
	list->first=list->last=s;
	s->next=s;
	list->size=0;
}
