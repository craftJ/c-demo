/*
 *find max sum of sub-arry
 *add by zj 20161107
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARRY_NUM (100)
#define MAX_ARRY_VALUE (100)
#define MIN_ARRY_VALUE ((-100))
#define MAX_SUM_VALUE ((((unsigned int)(-1)) >> 1))
#define MIN_SUM_VALUE (~MAX_SUM_VALUE)

static int g_OrginArry[MAX_ARRY_NUM];


/*
 *generate a test arry with random value;
 */
static int arry_init(int iNums)
{
	int i = 0;
	
	srand(time(NULL));

	printf("============= arry ==========\n");
	for (i = 0; i < iNums; i++)
	{
		g_OrginArry[i] = MIN_ARRY_VALUE + rand()%(MAX_ARRY_VALUE - MIN_ARRY_VALUE + 1);
		printf("[%d] ", g_OrginArry[i]);
	}
	printf("\n===============================\n");

	return 0;
}


/*
 * find max sub-arry at middle;
 */
static int find_max_sub_arry_middle(int start, int middle, int end, int* pleft, int* pright)
{
	int i = 0; 
	int leftmax = MIN_SUM_VALUE, rightmax = MIN_SUM_VALUE;
	int lefttmp = MIN_SUM_VALUE, righttmp = MIN_SUM_VALUE;

	for (i = middle; i >= start; i--)
	{	
		lefttmp += g_OrginArry[i];
		if (lefttmp > leftmax)
		{
			leftmax = lefttmp;
			*pleft = i;
		}
	}
	
	for (i = middle+1; i <= end; i++)
	{	
		righttmp += g_OrginArry[i];
		if (righttmp > rightmax)
		{
			rightmax = righttmp;
			*pright = i;
		}
	}
	
	return (leftmax+rightmax);
}



/*
 * find max_sub_arry
 */
static int find_max_sub_arry(int start, int end, int* pleft, int* pright)
{
	int leftsum = MIN_SUM_VALUE, rightsum = MIN_SUM_VALUE, middlesum = MIN_SUM_VALUE;
	int leftTemp1 = 0, rightTemp1 = 0;
	int leftTemp2 = 0, rightTemp2 = 0;
	int leftTemp3 = 0, rightTemp3 = 0;
	int maxsum = MIN_SUM_VALUE;
	int mid = 0;
	
	if (0 > start || MAX_ARRY_NUM <= start \
		|| 0 > end || MAX_ARRY_NUM <= end \
		|| NULL == pleft || NULL == pright)
	{
		printf("err happen!!!![%d][%d][%p][%p]\n", start, end, pleft, pright);
		return -1;
	}
	
	/*1. at last loop */
	if (start == end)
	{
		*pleft = start;
		*pright = end;
		return g_OrginArry[start];
	}

	/*2. seperate 3 parts, callback recursive*/
	mid = start + (end - start)/2;	
	leftsum = find_max_sub_arry(start, mid, &leftTemp1, &rightTemp1);
	rightsum = find_max_sub_arry(mid+1, end, &leftTemp2, &rightTemp2);
	middlesum = find_max_sub_arry_middle(start, mid, end, &leftTemp3, &rightTemp3);
	
	if (leftsum > rightsum && leftsum > middlesum)
	{
		*pleft = leftTemp1;
		*pright = rightTemp1;
		maxsum = leftsum;	
	}
	else if (rightsum > leftsum && rightsum > middlesum)
	{
		*pleft = leftTemp2;
		*pright = rightTemp2;
		maxsum = rightsum;	
	}
	else
	{
		*pleft = leftTemp3;
		*pright = rightTemp3;
		maxsum = middlesum;	
	}

	return maxsum;
}


int main()
{
	int leftpos = 0, rightpos = 0;
	int maxsum = 0;
	int left = 0, mid = 0, right = 0;

	/*1. init arry*/
	(void)arry_init(MAX_ARRY_NUM);

	/*2. seperate 3 parts, callback recursive*/
	left = 0;
	right = MAX_ARRY_NUM - 1;	
	maxsum = find_max_sub_arry(left, right, &leftpos, &rightpos);

	printf("----> result:from[%d] to [%d], max sum[%d]\n",\
			leftpos, rightpos, maxsum);

	return 0;
}



