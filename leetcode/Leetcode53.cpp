#include <vector>
#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

int maxSubArraySum(vector<int> &nums)
{
    vector<int> dp(nums.size(),0);
    dp[0] = nums[0];
    int max = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (dp[i-1] + nums[i] < nums[i])
        {
            dp[i] = nums[i];
        }
        max = std::max(dp[i],max);
    }
    
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int result = maxSubArraySum(nums);
    return 0;
}
