#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <fstream>
#include <limits.h>
#include <vector>
using namespace std;
//0-1背包问题

class Solution{
public:
    int solveKS(int *w,int *v,int index,int capacity)
    {
        if(index < 0 || capacity <= 0)
            return 0;
        //不放第index个物品所得价值
        int res = solveKS(w,v,index - 1,capacity);
        if (w[index] <= capacity){
            res = max(res,v[index] + solveKS(w, v, index-1, capacity - w[index]));//solveKS(w, v, index-1, capacity - w[index])拆分的子问题
        }
        return res;
    }
};


int maxKs(int*w,int*v,int capacity,int n)
{
    int dp[n+1][capacity+1];//背包中容量小于等于capacity时的选择前n个物品实现的最大价值
    for (int i = 0; i <= capacity; i++) 
        dp[0][i] = 0;//初始化二维数组
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 0; j < capacity + 1; j++)
        {
            if(j >= w[i-1]){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < capacity + 1; j++)
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    
    return dp[n][capacity];
}

int main(int argc,char**argv)
{
    int w[4] = {2,1,3,2};
    int v[4] = {12,10,20,15};
    int n = 4;
    int c = 5;
    // Solution s;
    // int res = s.solveKS(w,v,n-1,c);
    // printf("res:%d\n",res);
    int res1 = maxKs(w,v,5,4);
    printf("res:%d\n",res1);
    return 0;
}

/*
    0  1   2   3   4   5

0   0  0   0   0   0   0 
1   0  0   12  12  12  12 
2   0  10  12  22  22  22 
3   0  10  12  22  30  32 
2   0  10  15  25  30  37 
*/