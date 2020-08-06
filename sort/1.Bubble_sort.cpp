#include <stdlib.h>
#include <stdio.h>
#include "display.h"
int main(int argc,char**argv)
{
    int test[10]={2,9,5,6,4,8,7,3,1,0};
    int count = 0;
    int length = 10;
    printf("The origin array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ",test[i]);
    }
    printf("\n");

    // 1、
    for (int i = 0; i < length; i++)
    {
        printf("i:%d\n",i);
        for (int j = 0; j < length; j++)
        {
            if (test[i] < test[j])//每一轮循环都选择得到一个最小的数放在最前边
            {
                int temp = test[i];
                test[i] = test[j];
                test[j] = temp;
            } 
            count++;
            display(test,10);
        }
        // printf("exange: ");
        // for (int m = 0; m < length; m++)
        // {
        //     printf("%d ",test[m]);
        // }
        // printf("\n");
    }
    //2、
    // for (int i = 0; i < 10; i++) {//这种方法可以减少循环次数，保证每一次遍历，都能把最大的放在最后边
    //     for (int j = 0; j < 10 -i - 1; j++) {
    //         if (test[j + 1] < test[j]) {
    //             int t = test[j];
    //             test[j] = test[j+1];
    //             test[j+1] = t;
    //         }
    //         count++;
    //     }
    //     printf("exange: ");
    //     for (int m = 0; m < length; m++)
    //     {
    //         printf("%d ",test[m]);
    //     }
    //     printf("\n"); 
    // }
    
    printf("The result array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ",test[i]);
    }
    printf("\n");
    printf("count:%d\n",count);
    return 0;
}

/*
2、The origin array:
2 9 5 6 4 8 7 3 1 0 
exange: 2 5 6 4 8 7 3 1 0 9 
exange: 2 5 4 6 7 3 1 0 8 9 
exange: 2 4 5 6 3 1 0 7 8 9 
exange: 2 4 5 3 1 0 6 7 8 9 
exange: 2 4 3 1 0 5 6 7 8 9 
exange: 2 3 1 0 4 5 6 7 8 9 
exange: 2 1 0 3 4 5 6 7 8 9 
exange: 1 0 2 3 4 5 6 7 8 9 
exange: 0 1 2 3 4 5 6 7 8 9 
exange: 0 1 2 3 4 5 6 7 8 9 
The result array:
0 1 2 3 4 5 6 7 8 9 
localhost:sort yangsen$ g++ -o bubble Bubble_sort.cpp -std=c++11
localhost:sort yangsen$ ./bubble 
1、The origin array:
2 9 5 6 4 8 7 3 1 0 
exange: 9 2 5 6 4 8 7 3 1 0 
exange: 2 9 5 6 4 8 7 3 1 0 
exange: 2 5 9 6 4 8 7 3 1 0 
exange: 2 5 6 9 4 8 7 3 1 0 
exange: 2 4 5 6 9 8 7 3 1 0 
exange: 2 4 5 6 8 9 7 3 1 0 
exange: 2 4 5 6 7 8 9 3 1 0 
exange: 2 3 4 5 6 7 8 9 1 0 
exange: 1 2 3 4 5 6 7 8 9 0 
exange: 0 1 2 3 4 5 6 7 8 9 
*/