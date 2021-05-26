/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];//以当前这个节点为结尾的最大子序列的和
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {   
            dp[i] = ::max(dp[i-1]+nums[i],nums[i]);
            if (dp[i] > max)
            {
                max = dp[i];
            }
        }
        return max;
    }
};

int main(){
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    int res = s.maxSubArray(nums);
    cout<<res<<endl;
}