#include"hstring.h"
void init_string(hstring* s)
{
	s->length=0;
	s->ch=NULL;
}

void str_assign(hstring* s,char* str)
{
	int len=strlen(str);

	if(s->ch!=NULL)
		free(s->ch);

	s->ch=(char*)malloc(sizeof(char)*len);
	assert(s->ch!=NULL);
	
	for(int i=0;i<len;i++)
	{
		s->ch[i]=str[i];
	}
	s->ch[len]='\0';
	s->length=len;
}

void print_string(hstring* s)
{
	if(s->ch==NULL)
	{
		printf("s->ch=NULL.\n");
		return ;
	}
	printf("%s",s->ch);
	printf("\n");
}

int str_length(hstring* s)
{
	return s->length;
}

void str_copy(hstring *s,hstring* t)
{
	t->length=s->length;

	if(t->ch!=NULL)
		free(t->ch);

	t->ch=(char*)malloc(sizeof(char)*t->length);
	assert(t->ch!=NULL);

	for(int i=0;i<s->length;i++)
	{
		t->ch[i]=s->ch[i];
	}
	t->ch[t->length]='\0';
}

bool str_empty(hstring *s)
{
	if(s->length==0)
		return true;
	return false;
}

int str_compare(hstring* s,hstring* t)
{
	int i=0;
	while(i<s->length&&i<t->length)
	{
		if(s->ch[i]<t->ch[i])
		{
			printf("s<t\n");
			return -1;
		}
		if(s->ch[i]>t->ch[i])
		{
			printf("s>t\n");
			return 1;
		}
		if(s->ch[i]==t->ch[i])
		{
			i++;
		}
	}
	if(i==s->length&&i==t->length)
	{
		printf("s=t\n");
		return 0;
	}
	if(i<s->length)
	{
		printf("s>t\n");
		return 1;
	}
	if(i<t->length)
	{
		printf("s<t\n");
		return -1;
	}
}

void str_concat(hstring* s,hstring* t1,hstring* t2)
{
	if(s->ch!=NULL)	
		free(s->ch);
	s->length=t1->length+t2->length;
	s->ch=(char*)malloc(sizeof(char)*s->length);
	assert(s->ch!=NULL);

	int i,j;
	for(i=0;i<t1->length;i++)
	{
		s->ch[i]=t1->ch[i];
	}
	for(j=0;j<t2->length;j++)
	{
		s->ch[i]=t2->ch[j];
		i++;
	}
	s->ch[s->length]='\0';
}

void sub_string(hstring* s,hstring* t,int pos,int len)
{
	if(pos<0||len<0||pos+len>=s->length)
		return;

	if(t->ch!=NULL)
		free(t->ch);
	t->length=len;
	t->ch=(char*)malloc(sizeof(char)*t->length);

	for(int i=0;i<t->length;i++)
	{
		t->ch[i]=s->ch[i+pos];
	}
	t->ch[t->length]='\0';
}

void str_insert(hstring *s,int pos,hstring* t)
{
	if(t->length==0||pos<0||pos>s->length)
		return ;
	/*char* tmp=(char*)malloc(sizeof(char)*(t->length+s->length));
	assert(tmp!=NULL);
	int i,j,k;
	for(i=0;i<pos;i++)
	{
		tmp[i]=s->ch[i];
	}
	for(j=0;j<t->length;j++)
	{
		tmp[i+j]=t->ch[j];
	}
	for(k=0;k<s->length-pos;k++)
	{
		tmp[i+j+k]=s->ch[pos+k];
	}
	tmp[s->length+t->length]='\0';
	s->ch=tmp; */
	char* ch=(char*)realloc(s->ch,sizeof(char)*(s->length+t->length));
	assert(ch!=NULL);

	s->length=s->length+t->length;
	for(int i=s->length-1;i>=pos;i--)
	{
		s->ch[i+t->length]=s->ch[i];
	}
	for(int j=0;j<t->length;j++)
	{
		s->ch[pos+j]=t->ch[j];	
	}
	s->ch[s->length]='\0';
}


void str_delete(hstring* s,int pos,int len)
{
	if(s->length==0||pos<0||len<0||pos+len>s->length)
		return ;
	for(int i=pos+len;i<s->length;i++)
	{
		s->ch[i-len]=s->ch[i];
	}
	s->length=s->length-len;
	s->ch[s->length]='\0';
}

void str_clear(hstring* s)
{
	if(s->ch==NULL)
		return ;
	free(s->ch);
	s->ch=NULL;
	s->length=0;
}

















