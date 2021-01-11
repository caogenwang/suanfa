#include <iostream>
#include <vector>
using namespace std;

/*dp[i] = max(dp[i-1]+nums[i],nums[i])*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
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

int main()
{
    vector<int> nums{5,-2,6,-3,1,7};
    Solution s;
    int sum = s.maxSubArray(nums);
    cout<<sum<<endl;
}