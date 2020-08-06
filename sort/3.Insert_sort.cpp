#include <stdlib.h>
#include <stdio.h>
#include "display.h"
/*
插入排序的基本思想是：每步将一个待排序的记录，
按其关键码值的大小插入前面已经排序的文件中适当位置上，直到全部插入完为止
*/
int count = 0;
int main(int argc,char**argv)
{
    int test[10]={2,9,5,6,4,8,7,3,1,0};

    int length = 10;
    printf("The origin array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ",test[i]);
    }
    printf("\n");

    for (int j = 1; j < length; j++)
    {
        int temp = test[j];
        int i = j-1;
        while (i>-1 && temp < test[i])
        {
            test[i+1] = test[i];
            i--;
            count ++;
        }
        test[i+1] = temp;
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