#include"SeqList.h"

void InitSeqList(SeqList *list)
{
	list->base=(ElemType*)malloc(sizeof(ElemType)*SEQLIST_INIT_SIZE);
	assert(list->base!=NULL);
	list->capacity=SEQLIST_INIT_SIZE;
	list->size=0;
}
