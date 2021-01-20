#include <iostream>
#include <vector>
using namespace std;
class Solution1 {
public:
    int climbStairs(int n) {
        if (n==1 || n==2)
            return n;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};
//dp[i] = dp[i-1] + dp[i-2];
class Solution2 {
public:
    int climbStairs(int n) {
        vector<int> dp(n+3,0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

int main()
{
    int n = 45;
    Solution2 s;
    int r = s.climbStairs(n);
    cout<<r<<endl;
}