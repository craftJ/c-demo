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


int issort(int iStart, int iEnd, int *pdata)
{
	int i = 0,j = 1;
	int key = 0;	
	int iRange = iEnd - iStart +1;
	
	for (i = 0; i < iRange; i++)
	{
		key = pdata[i];

		j = i -1;
		while (j>=0)
		{
			if (key < pdata[j])
			{
				pdata[j+1] = pdata[j];
				j--;
			}
			else
			{
				break;
			}
		}
	
		pdata[j+1] = key;
	}

	return 0;
}




