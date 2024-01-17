#include"SeqStack.h"
int main()
{
	ElemType x=-1;
	SeqStack s;
	InitStack(&s);
	for(int i=1;i<=6;i++)
	{
		Push(&s,i);
	}
	Show(&s);
	printf("The length is %d.\n",Length(&s));
	GetTop(&s,&x);
	printf("%d is top.\n",x);
	Pop(&s);
	Show(&s);
	Clear(&s);
	Show(&s);
	Destory(&s);
	



























	return 0;
}
