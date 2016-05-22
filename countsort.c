//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>

#include "sort.h"

static int find_max(int iStart, int iEnd, int* pdata)
{
	int i = 0;
	int iMax = 0;
	int iNums = iEnd - iStart + 1;

	for (i = 0; i<iNums; i++)
	{
		iMax = (pdata[i] > iMax) ? pdata[i] : iMax;
	}
	
	return iMax;
}

int countsort (int iStart, int iEnd, int* pdata)
{
	int i = 0, iTmp = 0;
	int iNums = 0;
	int iMax = 0;
	int* pCount = NULL;
	int* pResult = NULL;

	//check input
	if (0 > iStart || 0 > iEnd || iStart >= iEnd || pdata == NULL)
	{
		printf("input err\n");
		return -1;
	}


	//find the max and count nums;
	iMax = find_max(iStart, iEnd, pdata);	
	iNums = iEnd - iStart + 1;

//	printf("--------> iMax[%d], iNums[%d]\n",iMax, iNums);

	//alloc memory
	pResult = (int *)malloc(iNums * sizeof(int));
	pCount = (int *)malloc((iMax+1) * sizeof(int));
	if (pResult == NULL || pCount == NULL)
	{
		printf("malloc err\n");
		return -1;
	}
	else
	{
		memset(pResult, 0, iNums * sizeof(int));
		memset(pCount, 0, (iMax+1)*sizeof(int));
	}	


	//count the times of every numer in pdata
	for (i = 0; i < iNums; i++)
	{
		iTmp = pdata[i];
		pCount[iTmp]++;
	}

	//count thd times sum of before
	for (i = 1; i <= iMax; i++)
	{
		iTmp = pCount[i];
		pCount[i] = pCount[i-1] + iTmp;
	}
	
	//sort by counts
	for (i = 0; i < iNums; i++)
	{
		iTmp = pCount[pdata[i]];
		pResult[iTmp-1] = pdata[i];
		pCount[pdata[i]]--;	
	}

	memcpy(pdata, pResult, iNums*sizeof(int));

	
	free(pResult);
	free(pCount);

	return 0;

}




