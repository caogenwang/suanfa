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
    int minDistance(string word1, string word2) {//从一个字符串变到另一个字符串需要的最短距离
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> memo(m,vector<int>(n));
        return helper(word1,0,word2,0,memo);
    }
    int helper(string word1,int i, string word2,int j,vector<vector<int>>& memo)
    {
        if(i == word1.size()) 
            return (int)word2.size() - j;
        if(j == word2.size())
            return (int)word1.size() - i;

        if(memo[i][j] > 0)
            return memo[i][j];
        int res = 0;
        if(word1[i] == word2[j])
        {
            return helper(word1, i + 1, word2, j + 1, memo);
        }
        else
        {
            int insertCnt = helper(word1, i, word2, j + 1, memo);
            int deleteCnt = helper(word1, i + 1, word2, j, memo);
            int replaceCnt = helper(word1, i + 1, word2, j + 1, memo);
            res = min(insertCnt, min(deleteCnt, replaceCnt)) + 1;
        }
        memo[i][j] = res;
    }
};

int main(int argc,char**argv)
{

}

class Solution1 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size()-1;
        int n = word2.size()-1;
        vector<vector<int> > dp(m+1,vector<int>(n+1));

        for(int i = 0;i <= m;i ++)
        {
            for(int j = 0;j <= n;j ++)
            {
                if(word1[i] == word2[j])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
                }
                
            }
        }
        return dp[m][n];
    }
};