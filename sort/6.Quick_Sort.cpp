#include <stdlib.h>
#include <stdio.h>
#include "display.h"
// {2,9,5,6,4,8,7,3,1,0}
int partion(int*arr, int left, int right) {
         //选取中轴元素
         int pivot = arr[left];
         int i = left + 1;
         int j = right;
         while (true) {
             // 向右找到第一个大于等于 pivot 的元素位置
             while (i <= j && arr[i] <= pivot) i++;
             // 向左找到第一个小于等于 pivot 的元素位置
             while(i <= j && arr[j] >= pivot ) j--;
             if(i >= j)
                 break;
             //交换两个元素的位置，使得左边的元素不大于pivot,右边的不小于pivot
             int temp = arr[i];
             arr[i] = arr[j];
             arr[j] = temp;
             printf("i:%d,j:%d\n",i,j);
             display(arr,10);
             printf("----------------------\n");
         }
         /*其实就是交换arr[left]和arr[j]的值，j的位置是一个比pivot的值小的值，所以需要交换位置*/
         arr[left] = arr[j];
         display(arr,10);
         // 使中轴元素处于有序的位置
         arr[j] = pivot;
         display(arr,10);
         printf("***\n");
        return j;
}

int *quickSort(int *arr, int left, int right) {
    if (left < right) {
        //获取中轴元素所处的位置
        int mid = partion(arr, left, right);
        //进行分割
        arr = quickSort(arr, left, mid - 1);
        arr = quickSort(arr, mid + 1, right);
    }
    return arr;
}

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

    quickSort(test,0,9);

    printf("The result array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ",test[i]);
    }
    printf("\n");
    return 0;
}