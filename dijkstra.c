#include <stdio.h>
#include <string.h>


#define VERTEX_MAX (10)
#define DIST_INVAILD (999999)

static int g_matrix[VERTEX_MAX][VERTEX_MAX] = {
1,2,DIST_INVAILD,DIST_INVAILD,DIST_INVAILD,DIST_INVAILD,DIST_INVAILD,1,3,
1,2,3,1,2,DIST_INVAILD,DIST_INVAILD,DIST_INVAILD,4,6,
2,3,6,7,1,2,4,5,1,DIST_INVAILD,
1,5,6,7,8,9,2,3,4,1,
4,5,6,7,DIST_INVAILD,DIST_INVAILD,DIST_INVAILD,3,4,1,
3,4,5,6,12,5,67,34,34,DIST_INVAILD,
1,3,4,34,4,5,56,87,11,3,
1,3,3,3,3,5,5,67,3,5,
5,1,2,3,4,2,1,2,1,3,
DIST_INVAILD,DIST_INVAILD,8,6,5,3,2,DIST_INVAILD,8,6};


static int dijkstra
(int aMatrix[VERTEX_MAX][VERTEX_MAX], int iNums, int iStart, int aDist[VERTEX_MAX], int aFind[VERTEX_MAX], int aPrev[VERTEX_MAX])
{
	int i = 0, j = 0,k = 0;
	int v = 0, tmp = 0;
	int iMinDist = 0;

	if (0 >= iNums || 0 >= iStart || iNums < iStart || VERTEX_MAX < iNums)
	{
		printf("param err,iNums[%d], iStart[%d]\n",iNums,iStart);
		return -1;
	}

	/*init*/
	for (i = 0; i < iNums; i++)
	{
		aFind[i] = 0;
		aDist[i] = DIST_INVAILD;
		aPrev[i] = 0;
	}
	v = iStart - 1;
	aFind[v] = 1;
	aDist[v] = 0;
	
	for (i = 0; i < iNums - 1; i++)
	{
		iMinDist = DIST_INVAILD;
		for (j = 0; j < iNums; j++)
		{
			if (0 == aFind[j] && iMinDist > aDist[j])
		 	{
				iMinDist = aDist[j];
				k = j;
			}
		}
		
		aFind[k] = 1;

		for (j = 0; j < iNums; j++)
		{
			tmp = aMatrix[k][j] == DIST_INVAILD ? DIST_INVAILD : aDist[k] + aMatrix[k][j];		
			if (0 == aFind[j] && tmp < aDist[j])
			{
				aDist[j] = tmp;
				aPrev[j] = k;
			}
		}
	}	

	return 0;
}

static int show_path(int aPrev[VERTEX_MAX], int iStart)
{
	int i = 0,j = 0, k = 0;
	int aPath[VERTEX_MAX];
	int tmp = 0;

	for (i = 0 ; i < VERTEX_MAX; i++)
	{
		if (0 == aPrev[i])
		{
			continue;
		}

		memset(aPath, 0, sizeof(aPath));
		aPath[0] = i;
		tmp = i;
		k = 1;
		while (tmp != iStart)
		{
			aPath[k] = aPrev[tmp];
			tmp = aPrev[tmp];
			k++;
		}
		aPath[k] = iStart;

		printf("[%d] to [%d] path: \n", iStart, i+1);

		while (k >= 0)
		{
			if (k != 0)
			{
				printf("[%d] -> ", aPath[k]);
			}
			else
			{
				printf("[%d]\n", aPath[k]);
			}
			k--;
		}

	}

	return 0;
}


int main ()
{
	int i = 0, j = 0;
	int v,u,dist = 0;
	int iNums = 0;
	int iStart = 0;
	int iAuto = 0;
	int aDist[VERTEX_MAX];
	int aFind[VERTEX_MAX];
	int aPrev[VERTEX_MAX];
	#define is_vertex_vaild(v) (1 <= (v) && VERTEX_MAX >= (v))
	#define is_dist_vaild(d) (0 <= (d) && DIST_INVAILD >= (dist))

	/* init arry map */
	if (0)
	{
		printf("======== build your map: \n");
		for (i = 0; i < VERTEX_MAX; i++)
		{
			if (3 == scanf("%d %d %d", &v,&u,&dist))
			{
				if (!is_vertex_vaild(u) || !is_vertex_vaild(v) || !is_dist_vaild(dist))
				{
					printf("err input!!!\n");
					continue;
				}
			
				g_matrix[u-1][v-1] = dist;
			}
		}
	}
	printf("======== map:\n");
	for (i = 0; i < VERTEX_MAX; i++)
	{
		for (j = 0; j < VERTEX_MAX; j++)
		{
			printf("[%d] ",g_matrix[i][j]);
		}
		printf("\n");
	}

	/* get start node */
	printf("======== input your start node: ");
	scanf("%d", &iStart);	
	if (!is_vertex_vaild(iStart))
	{
		printf("start node err\n");
		return -1;
	}


	/* dijsktra */
	if (0 != dijkstra(g_matrix,VERTEX_MAX,iStart,aDist, aFind, aPrev))
	{
	    printf("dijsktra failed!!!\n");
		return -1;
	}

	/* output result */
	if (0 != show_path(aPrev,iStart))
    {
		printf("show path failed!!\n");
		return -1;
	}

	return 0;
}





