#include <stdio.h>

//#include "printfunc.h"

extern int external_print1();
extern int external_print2();

int main()
{

	external_print1();

	external_print2();

	return 0;	
}




