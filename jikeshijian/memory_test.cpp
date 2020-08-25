#include <stdio.h>


int main(int argc, char const *argv[])
{
    int a[4][4]={
        {1,2,3,4},
        {11,12,13,14},
        {21,22,23,24},
        {31,32,33,34}
    };
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%p\n",&a[j][i]);
        }
        
    }
    int i=0;
    while(1)
    {
        printf("%d\n",i);
        i++;
    }
    return 0;
}
