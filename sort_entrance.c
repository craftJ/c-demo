/*
* brief: 插入排序
* highlight:
* 	 1.测试数据根据输入可配置随机数 
* 	 2.随机数起止可配 
* zj 20160317 add
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define RANDOM_RANGE_MAX (10000)


typedef int(*SORT)(int iStart, int iEnd, int *pdata);

typedef struct
{
	const char* funcName;
	SORT pSortFunc;
	
}SORT_FUNCS,*PSORT_FUNCS;


SORT_FUNCS g_struFuncs[SORT_FUNC_NUMS] = 
{
	{
		"insert sort", issort
	},
	{
		"quick sort", quicksort
	},
	{
		"merge sort", mergesort
	},
};



static int choose_sort_func(SORT* ppFunc)
{
	int i = 0;
	int choice = -1;	

	if (NULL == ppFunc)
	{
		printf("param err!!!\n");
		return -1;
	}
	
	printf("--------- Please choose sort function: \n");
	for (i = 0; i<SORT_FUNC_NUMS; i++)
	{
		printf("[%d] %s\n", i, g_struFuncs[i].funcName);
	}
	printf("\n");

	scanf("%d", &choice);

	if (0 > choice || SORT_FUNC_NUMS <= choice)
	{
		printf("choice input error!!!\n");
		return -1;
	}

	*ppFunc = g_struFuncs[choice].pSortFunc;

	printf("Choose Sort Func: %s\n", g_struFuncs[choice].funcName);

	return 0;
}



static int show_result(int iRange, int *pdata)
{
	int i = 0;

	printf("=========== sort result: ===============\n");
	for (i = 0; i<iRange; i++)
	{
		printf("%d, ", pdata[i]);
	}

	printf("\n========================================\n");
	
	return 0;
}

static int generate_test_data(int start, int end, int iRange, int *pdata)
{
	int i = 0;

	if (NULL == pdata)
	{
		return -1;
	}
	
	if (iRange > RANDOM_RANGE_MAX)
	{
		iRange = RANDOM_RANGE_MAX;
	}

	srand(time(NULL));

	printf("============== raw data: ==================\n");

	for (i = 0; i<iRange; i++)
	{
		pdata[i] = rand()%(end-start+1) + start;
		printf("%d, ", pdata[i]);
	}

	printf("\n===========================================\n");
	return 0;
}



int main (int argc, char *argv[])
{
	int start = 0;
	int end = 0;
	int rdnum = 0;
	int* pdata = NULL;	
	int (*func)(int iStart, int iEnd, int *pdata);
	
	if (argc < 3)
	{
		printf("input err\n");
		return 0;
	}

	start = atoi(argv[1]);
	end = atoi(argv[2]);
	rdnum = end - start + 1;
	func = NULL;

	printf("======= random range: [%d - %d], total size:%d\n",start,end,rdnum);

	pdata = (int*)malloc(RANDOM_RANGE_MAX * sizeof(int));

	if (NULL == pdata)
	{
		printf("malloc err!!\n");
		return 0;
	}

	if (0 != generate_test_data(start,end, rdnum,pdata))
	{
		printf("generate test data err!!!\n");
		goto exit;
	}

	
	if (0 != choose_sort_func(&func))
	{
		printf("choose sort fun err!!!!\n");
		goto exit;
	}

	if (0 != func(0, rdnum-1, pdata))
	{
		printf("sort err!!!!\n");
		goto exit;
	}

	if (0 != show_result(rdnum,pdata))
	{
		printf("show result err!!!\n");
		goto exit;
	}


exit:
	if (NULL != pdata)
	{
		free(pdata);
	}	

	return 0;
}




