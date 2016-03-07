
/*
*计算一次上1阶或者是2阶，上一个n级的楼梯共有多少走法，这个方法实际使用时，只能测试到40个阶梯的，大于这个之后运行将十分缓慢
*/

#include <stdio.h>
#include <string.h>

 //static int g_ways[100];


static long long step_ways(int n)
{
	if (1>=n)
	{
		return 1;
	}
	
	return step_ways(n-1) + step_ways(n-2);
}


int main(int argc, char *argv[])
{
	int n = 0;
	long long m = 0;
 
	if (1 >= argc || 0 >= strlen(argv[1]))
	{
		printf("input error\n");
		return -1;
	}

	n = atoi(argv[1]);

	if (n > 100)
	{
		printf("n should less than 100\n");
	}

	m = step_ways(n);
	
	printf("========== stairs:[%d]   ways:[%lld] ========\n", n, m);

	return 0;
}




