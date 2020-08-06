#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_set>
#include <list>
#include <fstream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < n)
            return uniquePaths(n,m);
        vector<int>dp(n,1);
        for(int j = 1 ; j < m; j++)
            for(int i = 1; i < n; i++){
                dp[i] = dp[i] + dp[i-1];
            }
        return dp[n-1];
    }
};
/*
f(i,j) = f(i-1,j) + f(i,j-1)
f(i-1,j) = f(i-2,j)+f(i-1,j-1)


f(i,j-1) = f(i-1,j-1)+f(i,j-2)

.
.
.


*/
int main(int argc,char**argv)
{
    Solution s;
    int n = s.uniquePaths(6,7);
    cout<<n<<endl;
}