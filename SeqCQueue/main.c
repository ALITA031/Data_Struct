#include"seqc_queue.h"
int main()
{
	seq_queue q;
	init_queue(&q);
	for(int i=8;i>0;i--)
	{
		en_queue(&q,i);
	}
	show_queue(&q);
	int val=0;
	for(int i=8;i>0;i--)
	{
		get_head(&q,&val);
		de_queue(&q);
		show_queue(&q);
	}
	clear_queue(&q);
	show_queue(&q);
	
	return 0;
}
