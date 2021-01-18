#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
       int n = nums.size(), reach = 0;
        for (int i = 0; i < n; ++i) {
            if (i > reach || reach >= n - 1) 
                break;
            reach = max(reach, i + nums[i]);
        }
        return reach >= n - 1;
    }
};

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
            if (dp[i] < 0) 
                return false;
        }
        return true;
    }
};

int main()
{
    vector<int>nums{2,3,1,1,4};
    Solution2 s;
    bool res = s.canJump(nums);
    cout<<res<<endl;
}