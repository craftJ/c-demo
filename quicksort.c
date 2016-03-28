/*
* brief: quick sort
* highlight:
* 		基准值采用了中位法获取	 
* zj 20160326 add
*
*/

#include <stdio.h>
#include <string.h>
#include <time.h>

/* find the middle value by random*/
static int set_base_unit(int iStart, int iEnd, int *pdata)
{
	int iRand1,iRand2,iRand3 = 0;
	int middle = 0, tmp =  0;
	srand(time(NULL));
	
	iRand1 = rand()%(iEnd - iStart + 1) + iStart;
	iRand2 = rand()%(iEnd - iStart + 1) + iStart;
	iRand3 = rand()%(iEnd - iStart + 1) + iStart;
	
	//printf("==== %d %d  %d\n", iRand1, iRand2, iRand3);

	tmp = (pdata[iRand1] > pdata[iRand2]) ? iRand1 : iRand2;
	if (pdata[tmp] < pdata[iRand3])
	{
		middle = tmp;
	}
	else
	{
		tmp = (pdata[iRand1] < pdata[iRand2]) ? iRand1 : iRand2;
		middle = (pdata[tmp] > pdata[iRand3]) ? tmp : iRand3;
	}

	return middle;
}


static int partion(int iStart, int iEnd, int *pdata)

{
	int key = 0, tmp = 0, keyIdx = 0;
	int j = iStart;
	int k = iEnd;
	int i = 0;

	if (iEnd <= iStart || NULL == pdata)
	{
		return -1;
	}

	if (3 <= k-j)
	{	
		keyIdx = set_base_unit(j,k,pdata);
		key = pdata[keyIdx];
	}
	else
	{
		keyIdx = iStart;
		key = pdata[iStart];
	}
	printf("===== start: %d   end:%d  key:%d keyIdx:%d\n",iStart,iEnd,key,keyIdx);

	for (i = 0; i<=(iEnd-iStart); i++)
	{
		printf("%d ", pdata[i+iStart]);
	}
	printf("\n====================================\n");
	
	j--;
	k++;

	//printf("===== key:%d\n",key);	
	while (j < k)
	{
		do
		{
			j++;
		}while (pdata[j] < key && j < k);

		do
		{
			k--;
		}while (pdata[k] > key && k > j);

		
		if (j < k)
		{
			tmp = pdata[j];
			pdata[j] = pdata[k];
			pdata[k] = tmp;
		}	
	}
	
	return k;
}


int quicksort(int iStart, int iEnd, int *pdata)
{
	int j;
	
	while (iStart < iEnd)
	{
		if (0 > (j = partion(iStart, iEnd, pdata)))

		{
			return -1;
		}
		
		if (0 > quicksort(iStart, j, pdata))
		{
			return -1;
		}
		
		iStart = j+1;
	}

	return 0;
}





