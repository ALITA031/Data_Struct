#include"hstring.h"
int main()
{
	hstring s;
	init_string(&s);
	str_assign(&s,"I love bxc .");
	print_string(&s);
	//###################################
	printf("The length of string is %d ",str_length(&s));
	printf("\n");
	//###################################
	hstring t;
	init_string(&t);
	str_copy(&s,&t);
	print_string(&t);
	//###################################
	printf("s:%d",str_empty(&s));
	printf("\n");
	hstring st;
	init_string(&st);
	printf("st%d",str_empty(&st));
	printf("\n");
	//#################################
	str_compare(&s,&t);
	hstring t1;
	init_string(&t1);
	str_assign(&t1,"I really love bxc.");
	str_compare(&s,&t1);
	//#################################
	hstring x;
	init_string(&x);
	str_concat(&x,&s,&t1);
	print_string(&x);
	//##################################
	hstring tmp;
	init_string(&tmp);
	sub_string(&s,&tmp,7,3);
	print_string(&tmp);
	//###################################
	hstring x1,x2;
	init_string(&x1);
	init_string(&x2);
	str_assign(&x1,"I  bxc.");
	str_assign(&x2,"love");
	str_insert(&x1,2,&x2);
	print_string(&x1);
	//##################################
	hstring x3;
	init_string(&x3);
	str_assign(&x3,"I really really love  bxc.");
	str_delete(&x3,2,6);
	print_string(&x3);
	//#################################
	str_clear(&x3);
	print_string(&x3);

	//##################################
	hstring s1,s2;
	init_string(&s1);
	init_string(&s2);

	str_assign(&s1,"I love bxc");
	str_assign(&s2,"bxc");
	int pos=str_find(&s1,&s2,0);
	printf("The pos of %s is %d\n",s2.ch,pos);
	//####################################

	hstring s3,s4,s5;
	init_string(&s3);
	init_string(&s4);
	init_string(&s5);

	str_assign(&s3,"I really love xxx");
	str_assign(&s4,"xxx");
	str_assign(&s5,"bxc");

	str_replace(&s3,&s4,&s5);
	print_string(&s3);




	
	return 0;
}
