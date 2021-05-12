#include <stdlib.h>
#include <stdio.h>
#include "display.h"
/*
插入排序的基本思想是：每步将一个待排序的记录，
按其关键码值的大小插入前面已经排序的文件中适当位置上，直到全部插入完为止
*/
int count = 0;
int test[10]={2,9,5,6,4,8,7,3,1,0};
int main(int argc,char**argv)
{
    for (int i = 0; i < 10; i++)
    {
        int j = i + 1;
        int tmp = test[j];
        while ((j-1) >= 0 && test[j-1] > tmp)
        {
            test[j] = test[j - 1];
            j --;
            count ++;
        }
        if(j < i + 1)
            test[j] = tmp;
    }
    display(test,10);
    printf("count:%d\n",count);
    return 0;
}