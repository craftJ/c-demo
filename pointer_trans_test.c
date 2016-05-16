
#include <stdio.h>
#include <string.h>



int main ()
{
	int* piTest = NULL;
	char* pcTest1 = NULL;
	char* pcTest2 = NULL;
	char cTest = 'a';

	piTest = (int *)&cTest;

	pcTest1 = &cTest;
	pcTest2 = (char *)piTest;

	/* pcTest1 is different on some device!!!!!*/
	if (pcTest1 == pcTest2)
	{
		printf("pointer is same\n");	
	}
	else
	{
		printf("pointer is different\n");
	}

	printf("pcTest1[%p], pcTest2[%p]\n", pcTest1, pcTest2);	

	return 0;
}





