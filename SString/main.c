#include"sstring.h"
int main()
{
	sstring s;	
	init_string(s);
	sstring t;
	init_string(t);

	u_char* str="abcdef";	
	str_assign(s,str);
	print_string(s);

	str_copy(s,t);
	print_string(t);
	
	str_assign(s,"I love bxc.");
	print_string(s);
	str_assign(t,"I really love bxc.");
	print_string(t);
	printf("s compare t is %d\n",str_compare(s,t));
	
	sstring y;
	init_string(y);
	str_concat(s,t,y);
	print_string(y);
	printf("######################\n");

	sstring sub;
	init_string(sub);
	sub_string(y,sub,11,18);
	print_string(sub);
	printf("#####################\n");
	
	str_insert(t,0,s);
	print_string(t);
	printf("########################\n");
	
	str_delete(t,0,11);
	print_string(t);
	printf("#######################\n");

	str_clear(t);
	print_string(t);
	printf("##########################\n");
	
	sstring s1,s2;
	init_string(s1);
	init_string(s2);
	str_assign(s1,"I REALLY LOVE BXC");
	str_assign(s2,"BXC");

	int pos=str_find(s1,s2,0);
	printf("The pos of %s is %d\n",s2,pos);
	printf("##########################\n");
	
	sstring s3,s4,s5;
	init_string(s3);
	init_string(s4);
	init_string(s5);
	str_assign(s3,"I REALLY LOVE XXX XXX XXX ");
	str_assign(s4,"XXX");
	str_assign(s5,"BXC");
	
	str_replace(s3,s4,s5);
	print_string(s3);
	return 0;
}
