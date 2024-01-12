#include"SList.h"
int main()
{
	List mylist;
	InitList(&mylist);
	
	int select =1;
	int Item=0;
	while(select)
	{
		printf("************************************\n");
		printf("* [1]  push_back   [2]  push_front *\n");
		printf("* [3]  show_list   [4]  pop_back   *\n");
		printf("* [5]  pop_front   [6]  insert_val *\n");
		printf("* [7]  find        [8]  length     *\n");
		printf("* [9]  delete_val  [10] sort       *\n");
		printf("* [11] reverse     [12] clear      *\n");
		printf("* [13] destory     [14] quit_system*\n");
		printf("************************************\n");
		printf("Please set number:>\n");
		scanf("%d",&select);
		if(select==0)
			break;
		switch(select)
		{
			case 1:
			//	printf("Please set the num that you want to push_back.(-1 end):>\n");
			//	while(scanf("%d",&Item),Item!=-1)
			//	{
			//		push_back(&mylist,Item);	
			//	}
				break;
			case 2:
			//	printf("Please set the num that you want to push_back.(-1 end):>\n");
			//	while(scanf("%d",&Item),Item!=-1)
			//	{
		        //		push_front(&mylist,Item);	
			//	}
				
				break;
			case 3:
				//show_list(&mylist);
				break;
			case 4:
				//pop_back(&mylist);
				break;
			case 5:
				//pop_front(&mylist);
				break;
			case 6:
				//printf("Please set the num that you want to insert :>\n");
				//scanf("%d",&Item);	
				//insert_val(&mylist,Item);
				break;
			case 7:
				//printf("Please set the data that you want to find. :>\n");
				//scanf("%d",&Item);
				//PNode p=find(&mylist,Item);
				//if(p!=NULL)
					//printf("The data you want to find is there: %d\n",p->data);
				//else
					//printf("Here is no data you want to find.\n");	
				//break;
			case 8:
				//printf("The length of Single List is %ld.\n",length(&mylist));
				break;
			case 9:
				//printf("Please set the number that you want to delete.\n");
				//scanf("%d",&Item);
				//delete_val(&mylist,Item);
				break;
			case 10:
				//sort(&mylist);
				break;
			case 11:
				//reverse(&mylist);
				break;
			case 12:
				//clear(&mylist);
				break;
			case 13:
				//destory(&mylist);
				break;
			case 14:
				break;
			default:
			printf("False,Please set number again\n");
				break;	
		}
	}
	return 0;
}
