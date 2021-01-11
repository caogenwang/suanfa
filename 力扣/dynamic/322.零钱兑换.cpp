#include <iostream>
#include <vector>
using namespace std;
/*dp[i]组成金额所需要的最少的张数*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if(i-coins[j] >= 0 && dp[i-coins[j]] != -1)
                {
                    if (dp[i] == -1 || dp[i] > dp[i-coins[j]] + 1)
                    {
                        dp[i] = dp[i-coins[j]] + 1;
                    }
                }
            }
        }
        return dp[amount];
    }
};

class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};


int main()
{
    vector<int> nums{1,2,5,7,10};
    Solution2 s;
    int account = 14;
    int rob = s.coinChange(nums,account);
    cout<<rob<<endl;
}


