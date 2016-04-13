/*
File: variable param function test

Attention:
	1. " va_list, va_arg, va_end,va_start" may be different from different compilers

	2. first param can not be "REGISTER" or "ARRY" type data,because the address used in "va_start"

typedef char * va_list;
#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_start(ap,v) ( ap = (va_list)&v + _INTSIZEOF(v) )
#define va_arg(ap,t) ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
#define va_end(ap) ( ap = (va_list)0 )
*/


#include <stdio.h>
#include <string.h>
#include <stdarg.h>


int var_param_func(int nums, ...)
{
	va_list pString = NULL;
	char* str = NULL;
 
	va_start(pString, nums);

	while (*pString != '\0')
	{
		str = va_arg(pString, char* );
		fputs(str, stdout);
	}

	va_end(pString);

	return 0;

}




int main (int argc, char*argv[])
{
	switch (argc)
	{
		case 1:
		{
			var_param_func(1, argv[0]);
			break;
		}
		case 2:
		{
			var_param_func(2, argv[0], argv[1]);
			break;
		}
		case 3:
		{
			var_param_func(3, argv[0], argv[1], argv[2]);
			break;
		}
		default:
		{
			var_param_func(4, argv[0], argv[1],argv[2],argv[3]);
			break;
		}
	}
	

	return 0;
}



