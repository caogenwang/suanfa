#include <stdio.h>
#include <stdlib.h>
#include "display.h"
/*
选择排序（Selection sort）是一种简单直观的排序算法。
它的工作原理是：第一次从待排序的数据元素中选出最小（或最大）的一个元素，
存放在序列的起始位置，然后再从剩余的未排序元素中寻找到最小（大）元素，
然后放到已排序的序列的末尾。以此类推，直到全部待排序的数据元素的个数为零。
选择排序是不稳定的排序方法。n^2
*/
int count = 0;
int test[10]={2,9,5,6,4,8,7,3,1,0};
void swap(int *a,int*b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(int argc,char**argv)
{
    for (int i = 0; i < 10; i++)
    {
        int tmp = i;
        for (int j = i+1; j < 10; j++)
        {
            if(test[j] < test[tmp])
            {
                tmp = j;
            }
            count ++;
        }
        swap(&test[i],&test[tmp]);
    }
    display(test,10);
    printf("count:%d\n",count);
    return 0;
}