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
    int SumPaths(int m,int n) {
        vector<vector<int> > dp(m+1,vector<int>(n+1,1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1]; 
            }
        }
        cout<<dp[n-1]<<endl;
        return dp[n-1];
    }

    int totalMethod(int n, int m){
        if (n == 0 && m == 0){
            return 0;
        }
        if (n == 0 || m == 0){
            return 1;
        }

        return totalMethod(n-1, m) + totalMethod(n, m-1);
    }
};

int main(int argc,char **argv)
{
    int m = 5;
    int n = 5;
    Solution s;
    s.SumPaths(m,n);
    s.uniquePaths(m,n);
    cout<<s.totalMethod(m,n)<<endl;
}