#include"BinTree.h"
#include"link_queue.h"
#include"SeqStack.h"
#include"SeqStack1.h"

void init_bintree(BinTree* bt,ElemType ref)
{
	bt->root=NULL;
	bt->ref_val='#';
}

void create_bintree(BinTree* bt,BinTreeNode** t)
{
	ElemType item;
	scanf("%c",&item);
	if(item==bt->ref_val)
		*t=NULL;
	else
	{
		*t=(BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t!=NULL);
		(*t)->data=item;
		create_bintree(bt,&(*t)->left_child);
		create_bintree(bt,&(*t)->right_child);
	}
}

/*void create_bintree(BinTree* bt,BinTreeNode** t,ElemType* str)
{
	if(*str=='\0')
	{
		*t=NULL;
		printf("*t is null\n");
		return;
	}
	if(*str==bt->ref_val)
		*t=NULL;	
	else 
	{
		printf("%c\n",*str);
		*t=(BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t!=NULL);
		(*t)->data=*str;
		create_bintree(bt,&((*t)->left_child),str+1);
		create_bintree(bt,&((*t)->right_child),str+1);
	}
}*/
void pre_order(BinTreeNode* t)
{
	if(t==NULL)
		printf("#");
	else
	{
		printf("%c",t->data);
		pre_order(t->left_child);
		pre_order(t->right_child);
	}
}
void pre_order_(BinTreeNode* t)
{
	if(t!=NULL)
	{
		seq_stack s;
		init_stack(&s);
		push(&s,t);
		BinTreeNode* p;
		while(!is_empty(&s))
		{
			get_top(&s,&p);
			pop(&s);
			printf("%c",p->data);

			if(p->right_child!=NULL)
			{
				push(&s,p->right_child);
			}
			if(p->left_child!=NULL)
			{
				push(&s,p->left_child);
			}
		
		}
		printf("\n");
	}
}

void in_order(BinTreeNode* t)
{
	if(t==NULL)
	{
		printf("#");
	}
	else
	{
		in_order(t->left_child);
		printf("%c",t->data);
		in_order(t->right_child);
	}
}
void in_order_(BinTreeNode* t)
{
	if(t!=NULL)
	{
		seq_stack s;
		init_stack(&s);
		push(&s,t);
		BinTreeNode* p;
		
		while(!is_empty(&s))
		{
			while(t!=NULL&&t->left_child!=NULL)
			{
				push(&s,t->left_child);
				t=t->left_child;
			}
			get_top(&s,&p);
			pop(&s);
			printf("%c",p->data);
			if(p->right_child!=NULL)
			{
				t=p->right_child;
				push(&s,t);
			}
		}
	}
}


void post_order(BinTreeNode* t)
{
	if(t==NULL)
	{
		printf("#");
	}
	else
	{
		post_order(t->left_child);
		post_order(t->right_child);
		printf("%c",t->data);
	}
}
void post_order_(BinTreeNode* t)
{
	if(t!=NULL)
	{
		SeqStack s;
		InitStack(&s);
		stk_node* stk;
		BinTreeNode* p;
		do
		{
			while(t!=NULL)
			{
				stk->ptr=t;
				stk->tag=L;
				Push(&s,stk);
				t=t->left_child;
			}

			int flag=1;
			while(flag==1&&!IsEmpty(&s))
			{
				GetTop(&s,&stk);
				Pop(&s);
				p=stk->ptr;
				switch(stk->tag)
				{
					case L:
						stk->tag=R;
						Push(&s,stk);
						flag=0;
						t=p->right_child;
						break;
					case R:
						printf("%c",stk->ptr->data);
						break;
				}
			}

		}while(!IsEmpty(&s));

		printf("\n");
	}		
}


void level_order(BinTree* bt)
{
	if(bt->root==NULL)
		printf("The tree is empty!\n");
	if(bt->root!=NULL)
	{	
		link_queue q;
		init_queue(&q);
		en_queue(&q,bt->root);
		BinTreeNode* temp;
		while(q.size)
		{
			get_head(&q,&temp);
			de_queue(&q);
			printf("%c",temp->data);
			if(temp->left_child!=NULL)
				en_queue(&q,temp->left_child);
			if(temp->right_child!=NULL)
				en_queue(&q,temp->right_child);
		}
	}
	printf("\n");
}

int size(BinTreeNode* t)
{
	if(t==NULL)
		return 0;
	return size(t->left_child)+size(t->right_child)+1;
}

void size_(BinTreeNode* t,int* cnt)
{
	if(t==NULL)	
		return;
	else
	{
		(*cnt)+=1;
		size_(t->left_child,cnt);
		size_(t->right_child,cnt);
	}
}

int height(BinTreeNode* t)
{
	if(t==NULL)
		return 0;
	else
	{
		int left_number=height(t->left_child);
		int right_number=height(t->right_child);
		if(left_number>right_number)
			return left_number+1;
		else
			return right_number+1;
	}
}

BinTreeNode* search(BinTreeNode* t,ElemType key)
{
	if(t==NULL)
		return NULL;
	if(key==t->data)
		return t;
	BinTreeNode* p=search(t->left_child,key);
	if(p!=NULL)
		return p;
	return search(t->right_child,key);
}

BinTreeNode* search_level_order(BinTreeNode* t,ElemType key)
{
	BinTreeNode* temp;
	if(t!=NULL)
	{
		link_queue q;
		init_queue(&q);
		en_queue(&q,t);
		while(q.size)
		{
			get_head(&q,&temp);
			de_queue(&q);
			if(temp->data==key)
				return temp; 
			if(t->left_child!=NULL)	
				en_queue(&q,temp->left_child);
			if(t->right_child!=NULL)
				en_queue(&q,temp->right_child);
		}
		return NULL;
	}
}

BinTreeNode* parent(BinTreeNode* t,BinTreeNode* key)
{
	if(t==NULL||key==NULL)
		return NULL;
	if(t->left_child==key||t->right_child==key)
		return t;
	BinTreeNode* p=parent(t->left_child,key);
	if(p->left_child==key||p->right_child==key)
		return p;
	return parent(t->right_child,key);
	
}

BinTreeNode* left(BinTreeNode* t)
{
	if(t!=NULL)
		return t->left_child;
}

BinTreeNode* right(BinTreeNode* t)
{
	if(t!=NULL)
		return t->right_child;
}

int empty(BinTree* bt)
{
	if(bt->root==NULL)
		return 0;
	return 1;
}

void copy(BinTreeNode* t,BinTreeNode** x)
{
	if(t==NULL)
		(*x)=NULL;
	else
		{
			(*x)=(BinTreeNode*)malloc(sizeof(BinTreeNode));
			assert((*x)!=NULL);
			(*x)->data=t->data;

			copy(t->left_child,&(*x)->left_child);
			copy(t->right_child,&(*x)->right_child);
		}
}

void clear(BinTreeNode** t)
{
	if((*t)!=NULL)	
	{
		clear(&((*t)->left_child));
		clear(&((*t)->right_child));
		free(*t);
		*t=NULL;
	}
}
















