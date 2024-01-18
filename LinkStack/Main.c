#include"LinkStack.h"
int main()
{
	LinkStack s;
	InitLinkStack(&s);
	for(int i=1;i<5;i++)
		Push(&s,i);
	Show(s);
	Pop(&s);
	Show(s);
	return 0;
}
