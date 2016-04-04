/*merge sort
 *high_light:
 *zj add 2016.04.03
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>


#define SAFE_FREE(p)  do{if(NULL != p){free(p);}p = NULL;}while(0)

static int tmp_buff_malloc(int **ppdata, int size)
{
	*ppdata = (int*)malloc(size * sizeof(int));
	if (NULL == *ppdata)
	{
		printf("malloc failed!\n");
		return -1;
	}
	return 0;
}



static int merge (int iStart, int iMiddle, int iEnd, int* pdata)
{
	int* pTmp1 = NULL;
	int* pTmp2 = NULL;
	int i = 0,j=0,k=0;
	int nums= 0,numsleft=0,numsright=0;

	if (NULL == pdata)
	{
		return -1;
	}
	
	if (iStart > iMiddle || iMiddle+1 > iEnd)
	{
		return -1;
	}
	
	numsleft = iMiddle - iStart + 1;
	numsright = iEnd - iMiddle;

#if 0
	printf("=========meg input: ");
	for (k = 0; k<(numsleft+numsright); k++)
	{
		printf("%d ", pdata[iStart+k]);
	}
	printf("\n==========meg output: ");
#endif	
	if (0 != tmp_buff_malloc(&pTmp1, numsleft))
	{
		return -1;
	}
	if (0 != tmp_buff_malloc(&pTmp2, numsright))
	{
		return -1;
	}
	

	memcpy(pTmp1,&pdata[iStart], numsleft * sizeof(int));
	memcpy(pTmp2,&pdata[iMiddle+1], numsright * sizeof(int));

	i = 0;
	j = 0;
	k = iStart;
	while (k <= iEnd)
	{
		if (i >= numsleft && j < numsright)
		{
			memcpy(&pdata[k], &pTmp2[j], (numsright - j)*sizeof(int));
			break;
		}
		else if (j >= numsright && i < numsleft)
		{
			memcpy(&pdata[k], &pTmp1[i], (numsleft - i)*sizeof(int));
			break;
		}

		if (pTmp1[i] < pTmp2[j])
		{
			pdata[k] = pTmp1[i];
			i++;
		}
		else
		{
			pdata[k] = pTmp2[j];
			j++;
		}
		k++;
	}

#if 0
	for (k = 0; k < (iEnd-iStart+1); k++)
	{
		printf("%d ", pdata[k+iStart]);
	}
	printf("\n");
#endif

	SAFE_FREE(pTmp1);
	SAFE_FREE(pTmp2);

	return 0;
}





int mergesort (int iStart, int iEnd, int* pdata)
{
	int j = 0;

	if (iStart >= iEnd)
	{
		return 0;
	}

	j = iStart +  (iEnd - iStart)/2;

	
	if (-1 == mergesort(iStart, j, pdata))
	{
		return -1;
	}
	if (-1 == mergesort(j+1, iEnd, pdata))
	{
		return -1;
	}
	if (-1 == merge(iStart, j, iEnd,pdata))	
	{	
		return -1;
	}
	
	return 0;
}


