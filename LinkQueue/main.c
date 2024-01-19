#include"link_queue.h"

int main()
{
	link_queue q;
	init_queue(&q);
	for(int i=1;i<=10;i++)
	{
		en_queue(&q,i);
	}
	show(&q);
	de_queue(&q);
	show(&q);
	int head=0;
	get_head(&q,&head);
	printf("%d is queue_head.\n",head);
	printf("Its length is %d\n",length(&q));
	clear_queue(&q);
	printf("Its length is %d\n",length(&q));
	return 0;
}
