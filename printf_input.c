
#include <stdio.h>
#include <string.h>


int main ()
{
	int inputCode = 0;

	while ((inputCode = getchar()) != EOF)
	{

		if (inputCode != 0xa) // printf input key except "ENTER" 
		{
			printf("--------input key value :[%c][%d][0x%0x]\n",inputCode, inputCode,inputCode);	
		}
	}
	
	return 0;

}







