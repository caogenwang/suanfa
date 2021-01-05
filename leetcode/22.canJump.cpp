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
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {//jump game
        int maxReach = 0;
        for(int i=0;i<n && i<=maxReach;i++)
            maxReach = max(maxReach,i+A[i]);  /// 跳到该点后还能到达的极限
        if(maxReach<n-1)
            return false;
        return true; 
    }
};

int main(int argc,char**argv)
{
    int A[5] = {2,3,1,1,4};
    int n = 5;
    Solution s;
    bool res = s.canJump(A,n);
    cout<<res<<endl;
}

class Solution2 {
public:
    int jump(int A[], int n) {
        int *dp = new int[n]();  // dp存放都到各点的最小步数
        for(int i = 0; i < n; i++)
        {
            int maxp = min(i+A[i],n-1);  // 从i 出发能走到的最远距离
            for (int j = i + 1; j <= maxp; j ++) {
                if(dp[j] == 0 || dp[j] > dp[i]+1)
                    dp[j] = dp[i] + 1;
                 // 如果位置没被走过,或者可以用更少步数到达，则到达j点的步数为dp[i]+1
            }
        }
        int res = dp[n-1];
        delete [] dp;
        dp = nullptr;
        return res;
    }
};
