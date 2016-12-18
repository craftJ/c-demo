#include <stdio.h>

extern int print_func();

int external_print2()
{
	printf("22222222 [%s][%d] !!!\n",__func__,__LINE__);

	print_func();

	return 0;
}





