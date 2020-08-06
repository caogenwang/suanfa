#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <list>
using namespace std;
void bucket_sort(int *a,int length)
{
    int min = a[0];
    int max = a[0];
    for (int i = 0; i < length; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    int d = max - min;
    int bucketNum = d/3 + 1;
    vector<list<int> > bucket(bucketNum);
    cout<<"bucket: "<<bucket.size()<<endl;
    for (int i = 0; i < bucket.size(); i++)
    {
        list<int> l;
        l.clear();
        bucket[i] = l;
    }
    
    for (int j = 0; j < length; j++)
    {
        int h = a[j]/bucketNum;
        bucket[h].push_back(a[j]);
    }

    for (int i = 0; i < bucket.size(); i++)
    {
        list<int> l = bucket[i];
        l.sort();
        bucket[i] = l;
    }
    int k=0;
     for (int i = 0; i < bucket.size(); i++)
    {
        list<int> l = bucket[i];
        cout<<"bucket:"<<i<<endl;
        for (list<int>::iterator it = l.begin();it != l.end();it ++)
        {
            a[k++] = (*it);
        }   
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

    bucket_sort(test,10);

    printf("The result array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ",test[i]);
    }
    printf("\n");
    return 0;
}