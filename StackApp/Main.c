#include"SeqStack.h"
void convert_8(int val);

int Check(char* str);

void LineEdit();

void Print(SeqStack *s);

int main()
{
//	int val=45565;
//	convert_8(val);
//	char* str="[[()]]";
//	int flag=Check(str);
//	printf("%d\n",flag);
	LineEdit();
	return 0;
}

void convert_8(int val)
{
	int tmp=0;
	SeqStack s;
	InitStack(&s);
	while(val!=0)
	{
		tmp=val%8;
		Push(&s,tmp);
		val/=8;
	}
	Show(&s);
}


int Check(char* str)
{
	SeqStack s;
	InitStack(&s);
	char* tmp=str;
	int i=0;
	int v=0;
	while(tmp[i]!='\0')
	{
		if(tmp[i]=='('||tmp[i]=='[')
		{
			Push(&s,i);
		}
		else if(tmp[i]==')')
		{
			GetTop(&s,&v);
			if(tmp[v]!='(')
				return -1;
			Pop(&s);
		}
		else if(tmp[i]==']')
		{
			GetTop(&s,&v);
			if(tmp[v]!='[')
				return -1;
			Pop(&s);
		}
		++i;
	}
		
	return IsEmpty(&s);
}


void Print(SeqStack* s)
{
	for(int i=0;i<s->top;i++)
		printf("%c",s->base[i]);
}
void LineEdit()
{
	SeqStack s;
	InitStack(&s);
	char ch=getchar();
	while(ch!='$')
	{
		while(ch!='$'&&ch!='\n')
		{
			switch(ch)
			{
				case '#':
					Pop(&s);
					break;
				case '@':
					Clear(&s);
					break;
				default :
					Push(&s,ch);
					break;
			}
			ch=getchar();
		}
		Print(&s);
		ch=getchar();
	}
	Destory(&s);
}

