#include <stdio.h>
#include <stdlib.h>

void count_sort(int *a,int length)
{
    int max = 0;
    if (length < 2 || a == NULL)
    {
        return;
    }
    for (int i = 0; i < length; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    int len = max+1;
    int *b = new int[len];
    for (int j = 0; j < len; j++)
    {
        b[j]=0;
    }

    for (int j = 0; j < length; j++)
    {
        int temp = a[j];
        b[temp]+=1;
    }
    int k = 0;
    for (int m = 0; m < len; m++)
    {
        int n = b[m];
        for (int x = 0; x < n; x++)
        {
            a[k++] = m;
        }
    }
    delete []b;
}
void countSort(int* arr,int length) {
         if(arr == NULL || length < 2) return ;
 
         int n = length;
         int max = arr[0];
         // 寻找数组的最大值
         for (int i = 1; i < n; i++) {
             if(max < arr[i])
                 max = arr[i];
         }
         //创建大小为max的临时数组
         int* temp = new int[max + 1];
         //统计元素i出现的次数
         for (int i = 0; i < n; i++) {
             temp[arr[i]]++;
         }
         int k = 0;
         //把临时数组统计好的数据汇总到原数组
         for (int i = 0; i <= max; i++) {
             for (int j = temp[i]; j > 0; j--) {
                 arr[k++] = i;
             }
         }
        return;
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

    count_sort(test,10);

    printf("The result array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ",test[i]);
    }
    printf("\n");
    return 0;
}