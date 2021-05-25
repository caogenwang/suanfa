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

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        return helper(nums, 0, (int)nums.size() - 1);
    }
    int helper(vector<int>& nums, int left, int right) {
        if (left >= right) return nums[left];
        int mid = left + (right - left) / 2;
        int lmax = helper(nums, left, mid - 1);
        int rmax = helper(nums, mid + 1, right);
        int mmax = nums[mid], t = mmax;
        for (int i = mid - 1; i >= left; --i) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        t = mmax;
        for (int i = mid + 1; i <= right; ++i) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        return max(mmax, max(lmax, rmax));
    }
};

int main()
{
    vector<int> nums{5,-2,6,-3,1,7};
    Solution s;
    int sum = s.maxSubArray(nums);
    cout<<sum<<endl;
}