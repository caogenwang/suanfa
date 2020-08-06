#include <stdio.h>
#include <stdlib.h>
#include "display.h"
/*
选择排序（Selection sort）是一种简单直观的排序算法。
它的工作原理是：第一次从待排序的数据元素中选出最小（或最大）的一个元素，
存放在序列的起始位置，然后再从剩余的未排序元素中寻找到最小（大）元素，
然后放到已排序的序列的末尾。以此类推，直到全部待排序的数据元素的个数为零。
选择排序是不稳定的排序方法。
*/
int count = 0;
int test[10]={2,9,5,6,4,8,7,3,1,0};
int main(int argc,char**argv)
{
    int length = 10;
    printf("The origin array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ",test[i]);
    }
    printf("\n");
    //1、
    // for (int i = 0; i < 10; i++)
    // {
    //     int temp = -1;
    //     int position = i;
    //     for (int j = i+1; j < 10; j++)
    //     {
    //         if (test[j] < test[position])
    //         {
    //             position = j;
    //         }
    //     }
    //     temp = test[i];
    //     test[i] = test[position];
    //     test[position] = temp;
    // }
    //2、on intenet
    for (int i = 0; i < 10; i++)
    {
        int min = i;
        for (int j = i+1; j < 10; j++)
        {
            if (test[j] < test[min])
            {
                min = j;
            }
            count ++;
        }
        int temp = test[i];
        test[i] = test[min];
        test[min] = temp;
        display(test,10);
    }
    
    printf("The result array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ",test[i]);
    }
    printf("\n");
    printf("count:%d\n",count);
    return 0;
}