
#include <stdio.h>

int main()
{
	char i = 81;

	while (i--)
	{
		/*%3可以忽略，是功能代码，其中这个除以9和对9取余的处理，技巧强，实现了一个9*9的循环*/
		if (i / 9 % 3 == i % 9 % 3)
		{
			continue;
		}
	
		printf("a=%d, b=%d\n",i/9%3, i%9%3);
	}

	return 0;
}
