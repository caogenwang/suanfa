#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_set>
#include <list>
#include <fstream>
#include <limits.h>
using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int> > grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) dp[i][0] = grid[i][0] + dp[i - 1][0];
        for (int j = 1; j < n; ++j) dp[0][j] = grid[0][j] + dp[0][j - 1];
        for(int i=1;i<m;i++)
        {
            for (int j = 1; j < n; j++) 
            {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};

class Solution1
{
public:
    int minPathSum(vector<vector<int>> grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                    dp[j]+=grid[i][j];
                else
                    dp[j] = grid[i][j] + min(dp[j],dp[j-1]);
            }
        }
        return dp[n-1];
    }
};


/*
f(i,j) = min(f(i-1,j),f(i,j-1))
*/


int main(int argc,char**argv)
{
    vector<vector<int> > grid={
        {1,2,3,4},
        {4,5,6,7},
        {7,8,9,0}
    };
    Solution1 s;
    int n = s.minPathSum(grid);
    cout<<n<<endl;
}