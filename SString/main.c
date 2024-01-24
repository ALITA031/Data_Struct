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

	return 0;
}
