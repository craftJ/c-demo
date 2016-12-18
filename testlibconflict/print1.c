#include <stdio.h>

extern int print_func();

int external_print1()
{
	printf("11111111 [%s][%d] !!!\n",__func__,__LINE__);

	print_func();

	return 0;
}





