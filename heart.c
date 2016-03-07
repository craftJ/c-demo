/*
 (x^2 + y^2 - 1)^3 = x^2 * y^3

*/


#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define HEART_CHAR ('*')

int main (int argc, char* argv[])
{
	float a,b,c,x,y = 0.0;

	if (argc < 2)
	{
		b = 1.5f;
		c = 1.5f;
	}
	else
	{
		b = atof(argv[1]);
		c = atof(argv[2]);
	}

	for (y = (b); y > b*(-1.0); y = y - 0.1f)
	{
		for (x = (c*(-1.0)); x < c; x = x + 0.05f)  //控制x步长可以控制心型的胖瘦
		{
			a = x*x + y*y - 1.0;
			
			putchar(((a*a*a <= (x*x*y*y*y)) ? HEART_CHAR : ' '));		
	
		//	printf("%c", ((a*a*a <= (x*x*y*y*y)) ? HEART_CHAR : ' '));
		}
			
	//	printf("\n");
		putchar('\n');
	}

	printf("\n\n");

	return 0;
}

