#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>&nums)
{
    vector<int> dp(nums.size(),0);
    int max_sum=dp[0];
    for (int i = 1; i < nums.size(); i++)
    {
        dp[i] = std::max(dp[i],dp[i-1]+nums[i]);//以某个点为结尾的所有子序列的和最大
        if (max_sum < dp[i])
        {
            max_sum = dp[i];
        }
        
    }
    return max_sum;
}

int main()
{

	std::vector<int> nums;
	nums.push_back(-2);
	nums.push_back(1);
	nums.push_back(-3);
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-5);
	nums.push_back(4);
	printf("%d\n", maxSubArray(nums));
	return 0;
}