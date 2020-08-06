#include <stdlib.h>
#include <stdio.h>
void display(int*arr,int n)
{
    printf("start\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}