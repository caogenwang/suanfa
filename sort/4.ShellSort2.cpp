#include <stdlib.h>
#include <stdio.h>
#include "display.h"
/*
希尔排序是把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；随着增量逐渐减少，
每组包含的关键词越来越多，当增量减至1时，整个文件恰被分成一组，算法便终止
*/
int count = 0;
void group_sort(int *a, int i,int n,int gap)
{
    for (int j = i+gap; j < n; j = j + gap)
    {
        int tmp = a[j];
        int k = j - gap;
        while ((k >= 0) && a[k]>tmp)
        {
            a[k+gap] = a[k];
            k -= gap;
        }
        a[k+gap] = tmp;
    }
}

void shellsort(int *array,int length)
{
    int gap = length/2;
    while (gap>0)
    {
        for (int i = 0; i < gap; i++)
        {
            group_sort(array,length,i,gap);
        }
        gap = gap / 2;
    }
    
}

int test[10]={2,9,5,6,4,8,7,3,1,0};
int main(int argc,char**argv)
{
    
    shellsort(test,10);
    display(test,10);
    printf("count:%d\n",count);
    return 0;
}