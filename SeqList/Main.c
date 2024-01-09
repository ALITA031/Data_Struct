#include"SeqList.h"

int main()
{
	SeqList mylist;
	InitSeqList(& mylist);

	int select=1;
	while(select)
	{
		printf("************************************\n");
		printf("* [1]  push_back   [2]  push_front *\n");
		printf("* [3]  show_list   [4]  pop_back   *\n");
		printf("* [5]  pop_front   [6]  insert_pos *\n");
		printf("* [7]  fine        [8]  length     *\n");
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
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				break;
			case 12:
				break;
			case 13:
				break;
			case 14:
				break;
			default:
			printf("False,Please set number again");
				break;	
		}
	}
	return 0;
}

