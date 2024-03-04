#include"BinTree.h" 
#include"link_queue.h"
int main()
{
	BinTree bt;
	init_bintree(&bt,'#');

	create_bintree(&bt,&(bt.root));
//	ElemType* str="ABC##DE##F##G#H##";
//	printf("%s",str);
//	printf("\n");
//	create_bintree(&bt,&(bt.root),str);

	pre_order(bt.root);
	printf("\n");
	in_order(bt.root);
	printf("\n");
	post_order(bt.root);
	printf("\n");
	level_order(&bt);

	printf("the size of tree node is %d\n",size(bt.root));

	int cnt=0;
	size_(bt.root,&cnt);
	printf("the size_ of tree node is %d\n",cnt);

	printf("the height of tree is %d\n",height(bt.root));

	BinTreeNode* tmp=search(bt.root,'C');
	BinTreeNode* temp=search_level_order(bt.root,'D');
	printf("The value of search is %c\n",tmp->data);
	printf("The value of search_ is %c\n",temp->data);

	BinTreeNode* temp1=parent(bt.root,temp);
	printf("the parents of %c is %c\n",temp->data,temp1->data);

	BinTree your_tree;
	init_bintree(&your_tree,'#');
	copy(bt.root,&(your_tree.root));
	level_order(&your_tree);

	clear(&(your_tree.root));
	printf("!!!!!!!!\n");
	level_order(&your_tree);
	return 0;
}
