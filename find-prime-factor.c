#include <stdio.h>
#include <string.h>

typedef int INT32;
typedef unsigned int UINT32;


static void primer(UINT32 n,  UINT32 m)
{
	if (n >= m)
	{
		while (0 != n%m)
		{
			m++;
		}		

		n = n / m;
		printf("%d ", m);
		
		primer(n, m);
	}
}


INT32 main (INT32 argc, char *argv[])
{
	UINT32 a = 0;

	if (argc <= 1 || 0 >= strlen(argv[1]))
	{
		printf("input error!!!!\n");
		return -1;
	}

	a = (UINT32)atoi((argv[1]));

	printf("==========primer factor of [%d] is:\n",a);

	primer(a, 2);

	printf("\n============================\n");

	return 0;

}






