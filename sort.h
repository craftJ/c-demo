/*
* brief: sort function declarations
* zj 20160317 add
*
*/

#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>


#define SORT_FUNC_NUMS (4)

int issort(int iStart, int iEnd, int *pdata);
int quicksort(int iStart, int iEnd, int *pdata);
int mergesort(int iStart, int iEnd, int* pdata);
int countsort(int iStart, int iEnd, int* pdata);
#endif





