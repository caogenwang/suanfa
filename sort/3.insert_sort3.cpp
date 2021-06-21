#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "display.h"
void insert_sort(vector<int> &arr)
{
    for(int i = 0;i<arr.size() - 1;i++)
    {
        int j = i + 1;
        int temp = arr[j];
        while(j>0 && temp<arr[j]){
            arr[j] = arr[j - 1];
            j --;
        }
        arr[j] = temp;
    }
}

int main(){
    vector<int> v{2,3,5,6,7,0,8,9,1,4};
    insert_sort(v);
    return 0;
}
