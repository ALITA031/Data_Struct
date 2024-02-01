#include"sparse_matrix.h"

void init_matrix(smatrix* sm)
{
	memset(sm,0,sizeof(*sm));
}

void creat_matrix(smatrix *sm)
{
	FILE *fp=fopen("Matrix.txt","r");
	if(fp==NULL)
		exit(1);
	fscanf(fp,"%d %d",&sm->row,&sm->col);

	int cnt=0;
	int key=0;

	for(int i=0;i<sm->row;i++)
	{
		for(int j=0;j<sm->col;j++)
		{
			fscanf(fp,"%d",&key);
			if(key!=0)
			{
				sm->data[cnt].val=key;
				sm->data[cnt].i=i;
				sm->data[cnt].j=j;
				cnt++;
			}
		}
	}
	sm->nzero=cnt;
	fclose(fp);
}

void print_matrix(smatrix* sm)
{
	int cnt=0;
	for(int i=0;i<sm->row;i++)
	{
		for(int j=0;j<sm->col;j++)
		{
			if(sm->data[cnt].i==i&&sm->data[cnt].j==j)
			{
				printf("%d ",sm->data[cnt].val);
				cnt++;
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
	printf("##################\n");
}

void copy_matrix(smatrix* sm,smatrix* sm1)
{
	sm1->row=sm->row;
	sm1->col=sm->col;
	sm1->nzero=sm->nzero;
	for(int i=0;i<sm->nzero;i++)
	{
		sm1->data[i].i=sm->data[i].i;
		sm1->data[i].j=sm->data[i].j;
		sm1->data[i].val=sm->data[i].val;
	}
}

void add_matrix(smatrix* sm,smatrix* sm1,smatrix* t)
{
	int len1=sm->nzero,len2=sm1->nzero;
	int m=0,n=0,cnt=0;
	t->row=sm->row;
	t->col=sm->col;

	while(m<len1&&n<len2)
	{
		if(sm->data[m].i<sm1->data[n].i)
		{
			t->nzero+=1;
			t->data[cnt].i=sm->data[m].i;
			t->data[cnt].j=sm->data[m].j;
			t->data[cnt].val=sm->data[m].val;
			cnt++;
			m++;
		}
		else if(sm->data[m].i==sm1->data[n].i&&sm->data[m].j<sm1->data[n].j)
		{
			t->nzero+=1;
			t->data[cnt].i=sm->data[m].i;
			t->data[cnt].j=sm->data[m].j;
			t->data[cnt].val=sm->data[m].val;
			cnt++;
			m++;
		}
		else if(sm->data[m].i==sm1->data[n].i&&sm->data[m].j==sm1->data[n].j)
		{
			if(sm->data[m].val+sm1->data[n].val!=0)
			{
				t->nzero+=1;
				t->data[cnt].i=sm->data[m].i;
				t->data[cnt].j=sm->data[m].j;
				t->data[cnt].val=sm->data[m].val+sm1->data[n].val;
				cnt++;
			}
			m++;
			n++;
		}
		else 
		{
			t->nzero+=1;
			t->data[cnt].i=sm1->data[n].i;
			t->data[cnt].j=sm1->data[n].j;
			t->data[cnt].val=sm1->data[n].val;
			cnt++;
			n++;
		}
	}
	if(m<len1)
	{
		for(int p=m;p<len1;p++)
		{
			t->nzero++;
			t->data[cnt].val=sm->data[p].val;
			t->data[cnt].i=sm->data[m].i;
            t->data[cnt].j=sm->data[m].j;
			m++;
			cnt++;

		}
	}
	if(n<len2)
	{
		for(int p=n;p<len2;p++)
		{
			t->nzero++;
			t->data[cnt].val=sm1->data[p].val;
			t->data[cnt].i=sm1->data[n].i;
            t->data[cnt].j=sm1->data[n].j;
			n++;
			cnt++;
		}
	}
}

void sub_matrix(smatrix* sm,smatrix* sm1,smatrix* t)
{
	int len1=sm->nzero,len2=sm1->nzero;
	int m=0,n=0,cnt=0;
	t->row=sm->row;
	t->col=sm->col;

	while(m<len1&&n<len2)
	{
		if(sm->data[m].i<sm1->data[n].i)
		{
			t->nzero+=1;
			t->data[cnt].i=sm->data[m].i;
			t->data[cnt].j=sm->data[m].j;
			t->data[cnt].val=sm->data[m].val;
			cnt++;
			m++;
		}
		else if(sm->data[m].i==sm1->data[n].i&&sm->data[m].j<sm1->data[n].j)
		{
			t->nzero+=1;
			t->data[cnt].i=sm->data[m].i;
			t->data[cnt].j=sm->data[m].j;
			t->data[cnt].val=sm->data[m].val;
			cnt++;
			m++;
		}
		else if(sm->data[m].i==sm1->data[n].i&&sm->data[m].j==sm1->data[n].j)
		{
			if(sm->data[m].val-sm1->data[n].val!=0)
			{
				t->nzero+=1;
				t->data[cnt].i=sm->data[m].i;
				t->data[cnt].j=sm->data[m].j;
				t->data[cnt].val=sm->data[m].val-sm1->data[n].val;
				cnt++;
			}
			m++;
			n++;
		}
		else 
		{
			t->nzero+=1;
			t->data[cnt].i=sm1->data[n].i;
			t->data[cnt].j=sm1->data[n].j;
			t->data[cnt].val=sm1->data[n].val;
			cnt++;
			n++;
		}
	}
	if(m<len1)
	{
		for(int p=m;p<len1;p++)
		{
			t->nzero++;
			t->data[cnt].val=sm->data[p].val;
			t->data[cnt].i=sm->data[m].i;
            t->data[cnt].j=sm->data[m].j;
			cnt++;
			m++;
		}
	}
	if(n<len2)
	{
		for(int p=n;p<len2;p++)
		{
			t->nzero++;
			t->data[cnt].val=sm1->data[p].val;
			t->data[cnt].i=sm1->data[n].i;
            t->data[cnt].j=sm1->data[n].j;
			cnt++;
			n++;
		}
	}
}

void creat_matrix1(smatrix *sm)
{
	FILE *fp=fopen("Matrix1.txt","r");
	if(fp==NULL)
		exit(1);
	fscanf(fp,"%d %d",&sm->row,&sm->col);

	int cnt=0;
	int key=0;

	for(int i=0;i<sm->row;i++)
	{
		for(int j=0;j<sm->col;j++)
		{
			fscanf(fp,"%d",&key);
			if(key!=0)
			{
				sm->data[cnt].val=key;
				sm->data[cnt].i=i;
				sm->data[cnt].j=j;
				cnt++;
			}
		}
	}
	sm->nzero=cnt;
	fclose(fp);
}

void transpose_matrix(smatrix* sm,smatrix* t)
{
	t->row=sm->col;
	t->col=sm->row;
	t->nzero=sm->nzero;
	int cnt=0;
	for(int m=0;m<sm->col;m++)
	{
		for(int n=0;n<sm->nzero;n++)
		{
			if(sm->data[n].j==m)
			{
				t->data[cnt].val=sm->data[n].val;
				t->data[cnt].i=sm->data[n].j;
				t->data[cnt].j=sm->data[n].i;
				cnt++;
			}
		}
	}
}






















