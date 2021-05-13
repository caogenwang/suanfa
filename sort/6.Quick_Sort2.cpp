#include <stdlib.h>
#include <stdio.h>
#include "display.h"
// {2,9,5,6,4,8,7,3,1,0}
int partion(int*arr, int left, int right) {
    int mid = (left+right) / 2;
    int poivt = arr[mid];
    int i = left;
    int j = right;
    while (true)
    {
        //向右找到第一个大于poivt的元素
        while (i <= mid && arr[i] <= poivt) i ++;
        //向左边找到第一个小于poivt的元素
        while (j >= mid && arr[j] >= poivt) j --;
        if (i>=j)
            break;
        
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;

        printf("i:%d,j:%d\n",i,j);
        display(arr,10);
        printf("----------------------\n");
    }
    printf("****************\n");
    return mid;
}

int *quickSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = partion(arr,left,right);
        arr = quickSort(arr,left,mid-1);
        arr = quickSort(arr,mid+1,right);
    }
    return arr;
}

int test[10]={2,9,5,6,4,8,7,3,1,0};
int main(int argc,char**argv)
{
    int length = 10;
    
    quickSort(test,0,9);

    return 0;
}