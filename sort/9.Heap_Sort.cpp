#include <stdio.h>
#include <stdlib.h>


void downAdjust(int *a,int parent,int n)
{
    int temp = a[parent];
    int child = 2*parent+1;
    //之所以一直循环是因为可能要一直往下调整
    while (child <= n)
    {
        if (child+1 <= n && a[child] < a[child + 1])
            child++;
        if (a[child] <= temp)
            break;
        a[parent] = a[child];
        parent = child;
        child = 2*parent + 1;
    }
    a[parent] = temp;
}

void heap_sort(int *a,int length)
{
    //在一个数组中的父子关系，父是n，则子是2*n+1，和2*n+2
    //构建大顶堆
    for (int i = ((length - 1) -1)/2; i >=0; i--)
    {
        downAdjust(a,i,length - 1);
    }
     //进行堆排序
    for (int i = length - 1; i >= 1; i--) {
        // 把堆顶元素与最后一个元素交换
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        // 把打乱的堆进行调整，恢复堆的特性
        downAdjust(a, 0, i - 1);
    }
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

    heap_sort(test,10);

    printf("The result array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ",test[i]);
    }
    printf("\n");
    return 0;
}

void upAdjust(int *a,int child,int n)
{
    int parent = (child-1)/2;
    while (parent >= 0)
    {
        int temp = a[parent];

        if (child+1<n && a[child] < a[child+1])
            child ++;
        if (temp < a[parent])
            break;

        a[parent] = a[child];
        a[child] = temp;
        child = parent;
        parent = (child-1)/2;
    }
}