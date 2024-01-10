#include"SeqList.h"

int main()
{
	SeqList mylist;
	InitSeqList(& mylist);
	ElemType Item,pos;
	int select=1;
	while(select)
	{
		printf("************************************\n");
		printf("* [1]  push_back   [2]  push_front *\n");
		printf("* [3]  show_list   [4]  pop_back   *\n");
		printf("* [5]  pop_front   [6]  insert_pos *\n");
		printf("* [7]  find        [8]  length     *\n");
		printf("* [9]  delete_pos  [10] delete_val *\n");
		printf("* [11] sort        [12] reverse    *\n");
		printf("* [13] clear       [14] destory    *\n");
		printf("* [0]  quit_system                 *\n");
		printf("************************************\n");
		printf("Please set number:>\n");
		scanf("%d",&select);
		if(select==0)
			break;
		switch(select)
		{
			case 1:
				printf("Please set the number(-1 end):>\n");
				while(scanf("%d",&Item),Item!=-1)
				{		
				push_back(&mylist,Item);
				}
				break;
			case 2:
				printf("Please set the number(-1 end):>\n");
				while(scanf("%d",&Item),Item!=-1)
				{		
				push_front(&mylist,Item);
				}
				break;
			case 3:
				show_list(mylist);
				break;
			case 4:
				pop_back(&mylist);
				break;
			case 5:
				pop_front(&mylist);
				break;
			case 6:
				printf("Please set num and pos\n");
				scanf("%d %d",&Item,&pos);
				insert_pos(&mylist,Item,pos);
				break;
			case 7:
				printf("Please set the num that you want to find\n");
				scanf("%d",&Item);
				pos=find(mylist,Item);
				if(pos==-1)
					printf("Error!\n");
				else
					printf("The pos is %d\n",pos);
				break;
			case 8:
				printf("The length is %d\n",length(mylist));
				break;
			case 9:
				printf("Please set the number that you want to delete.\n");
				scanf("%d",&pos);
				delete_pos(&mylist,pos);
				break;
			case 10:
				printf("Please set the val that you want to delete\n");
				scanf("%d",&Item);
				delete_val(&mylist,Item);
				break;
			case 11:
				sort(&mylist);
				break;
			case 12:
				reverse(&mylist);
				break;
			case 13:
				clear(&mylist);
				break;
			case 14:
				destory(&mylist);
				break;
			default:
			printf("False,Please set number again\n");
				break;	
		}
	}
	return 0;
}

