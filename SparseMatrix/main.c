#include"sparse_matrix.h"
int main()
{
	smatrix sm,sm1;
	init_matrix(&sm);
	init_matrix(&sm1);
	creat_matrix(&sm);
	print_matrix(&sm);
	creat_matrix1(&sm1);
    //copy_matrix(&sm,&sm1);
	print_matrix(&sm1);

	smatrix t;
	smatrix t1;
	init_matrix(&t);
	init_matrix(&t1);
	add_matrix(&sm,&sm1,&t);
	print_matrix(&t);
	sub_matrix(&sm,&sm1,&t1);
	print_matrix(&t1);

	smatrix t2;
	init_matrix(&t2);
	transpose_matrix(&t1,&t2);
	print_matrix(&t2);

	fast_transpose_matrix(&t1,&t2);
	print_matrix(&t2);
	
	return 0;
}
