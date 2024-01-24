#include"sstring.h"

void init_string(sstring s)
{
	s[0]='\0';
}

void str_assign(sstring s,u_char* str)
{
	int len=strlen(str);
	if(len>MAXSTRLEN)
	{
		printf("Error!\n");
		return ;
	}
	for(int i=0;i<len;i++)
	{
		s[i]=str[i];
	}
	s[len]='\0';
}

void print_string(sstring s)
{
	printf("%s\n",s);
}

void str_copy(sstring s,sstring t)
{
	int len=str_length(s);
	for(int i=0;i<len;i++)
	{
		t[i]=s[i];
	}
	t[len]='\0';
}

int str_empty(sstring s)
{
	if(s[0]!='\0')
		return 0;
	return 1;
}

int str_compare(sstring s,sstring t)
{
	int result=0;
	while(*s!='\0'||*t!='\0')
	{
		result=*s-*t;
		if(result==0)
			break;
		s++;
		t++;
	}
	if(result>0)
		result=1;
	else if(result<0)
		result=-1;
	return result;
}

int str_length(sstring s)
{
	int i=0;
	u_char flag=s[0];
	while(flag!='\0')
	{
		i++;
		flag=s[i];
	}
	return i;
}

void str_concat(sstring s1,sstring s2,sstring y)
{
	int len1=str_length(s1);
	int len2=str_length(s2);
	int i,j;

	if(len1+len2<=MAXSTRLEN)
	{
		for(i=0;i<len1;i++)
			y[i]=s1[i];
		for(j=0;j<len2;j++)
			y[j+i]=s2[j];
		y[len1+len2]='\0';
	}
	else if(len1<MAXSTRLEN)
	{
		for(i=0;i<len1;i++)
			y[i]=s1[i];
		for(j=0;j<MAXSTRLEN-len1;j++)
			y[i+j]=s2[j];
		y[MAXSTRLEN]='\0';	
	}
	else
	{
		for(i=0;i<MAXSTRLEN;i++)
			y[i]=s1[i];
		y[MAXSTRLEN]='\0';
	}

}

void sub_string(sstring s,sstring sub,int pos,int len)
{
	int s_len=str_length(s);
	if(len<0||pos<0||pos+len>s_len)
	{
		printf("Error!\n");
		return ;
	}
	for(int i=0;i<len;i++)
	{
		sub[i]=s[pos+i];
	}
	sub[len]='\0';
}

void str_insert(sstring s,int pos,sstring t)
{
	int len1=str_length(s);
	int len2=str_length(t);
	if(len1+len2>MAXSTRLEN)
	{
		int len3=MAXSTRLEN-len1;
		for(int i=len1+len3;i>=pos+len3;i--)
		{
			s[i]=s[i-len3];
		}
		for(int j=0;j<len3;j++)
		{
			s[j+pos]=t[j];
		}
		return ;
	}
	for(int i=len1+len2;i>=pos+len2;i--)
	{
		s[i]=s[i-len2];
	}
	for(int j=0;j<len2;j++)
	{
		s[pos+j]=t[j];
	}
}

void str_delete(sstring s,int pos,int len)
{
	if(pos<0||len<=0||pos+len>MAXSTRLEN)
	{
		printf("Error!\n");
		return ;
	}
	int s_len=str_length(s);
	for(int i=pos;i<=s_len;i++)
	{
		s[i]=s[i+len];
	}
}

void str_clear(sstring s)
{
	s[0]='\0';
}











