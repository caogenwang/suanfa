#include <stdlib.h>
#include <stdio.h>
/*
归并排序（MERGE-SORT）是利用归并的思想实现的排序方法，
该算法采用经典的分治（divide-and-conquer）策略（分治法将问题分(divide)成一些小的问题然后递归求解，
而治(conquer)的阶段则将分的阶段得到的各答案"修补"在一起，即分而治之)。
*/
// 合并函数，把两个有序的数组合并起来
int count = 0;
// void merge(int *t, int left, int middle, int right)
// {
//     for (int i = middle + 1; i < right; i++)
//     {
//         int temp = t[i];
//         int j = middle;
//         while (j>=left && temp < t[j])//插入排序
//         {
//             t[j+1] = t[j];
//             j--;
//             count++;
//         }
//         t[j+1]=temp;
//     }
// }

void merge(int* arr, int left, int mid, int right) {
    //先用一个临时数组把他们合并汇总起来
    int* a = new int[right - left + 1];
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            a[k++] = arr[i++];
        } else {
            a[k++] = arr[j++];
        }
        count++;
    }
    while(i <= mid) {a[k++] = arr[i++];count++;}
    while(j <= right) {a[k++] = arr[j++];count++;}
    // 把临时数组复制到原数组
    for (i = 0; i < k; i++) {
        arr[left++] = a[i];
    }
    delete []a;
}

void mergeSort(int *t,int left,int right){//递归的作用是先进行分治
        if (left<right){
            int middle = (left+right)/2;
            mergeSort(t, 0, middle-1);
            mergeSort(t, middle+1, right);
            merge(t,left,middle,right);
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

    mergeSort(test,0,9);

    printf("The result array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ",test[i]);
    }
    printf("\n");
    printf("count:%d\n",count);
    return 0;
}

// 非递归式的归并排序
// int * mergeSort(int* arr) {
//          int n = 10;
//          // 子数组的大小分别为1，2，4，8...
//          // 刚开始合并的数组大小是1，接着是2，接着4....
//          for (int i = 1; i < n; i += i) {
//              //进行数组进行划分
//              int left = 0;
//              int mid = left + i - 1;
//              int right = mid + i;
//              //进行合并，对数组大小为 i 的数组进行两两合并
//              while (right < n) {
//                  // 合并函数和递归式的合并函数一样
//                  merge(arr, left, mid, right);
//                  left = right + 1;
//                  mid = left + i - 1;
//                  right = mid + i;
//              }
//              // 还有一些被遗漏的数组没合并，千万别忘了
//              // 因为不可能每个字数组的大小都刚好为 i
//              if (left < n && mid < n) {
//                  merge(arr, left, mid, n - 1);
//              }
//          }
//          return arr;
//      }

// void merge(int*arr,int left,int mid,int right,int* temp){
//         int i = left;//左序列指针
//         int j = mid+1;//右序列指针
//         int t = 0;//临时数组指针
//         while (i<=mid && j<=right){
//             if(arr[i]<=arr[j]){
//                 temp[t++] = arr[i++];
//             }else {
//                 temp[t++] = arr[j++];
//             }
//         }
//         while(i<=mid){//将左边剩余元素填充进temp中
//             temp[t++] = arr[i++];
//         }
//         while(j<=right){//将右序列剩余元素填充进temp中
//             temp[t++] = arr[j++];
//         }
//         t = 0;
//         //将temp中的元素全部拷贝到原数组中
//         while(left <= right){
//             arr[left++] = temp[t++];
//         }
//     }