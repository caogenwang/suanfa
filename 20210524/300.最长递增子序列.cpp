#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        v.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            while (v.size() > 0 && nums[i] <= v.back())
            {
                v.pop_back();
            }
            v.push_back(nums[i]);
        }
        return v.size();
    }
};

class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1,0);
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] > nums[i-1])
                dp[i] = dp[i-1]+1; 
            else
                dp[i] = dp[i-1];
        }
        return dp[nums.size()];
    }
};
class Solution3 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution4 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for (auto a : nums) {
            auto it = lower_bound(v.begin(), v.end(), a);
            if (it == v.end()) 
                v.push_back(a);
            else 
                *it = a;
        }
　　　　　return v.size();
    }
};

int main(){
    vector<int> nums{7,7,7,7,7,7,7,7};
    Solution s;
    int res = s.lengthOfLIS(nums);
    cout<<res<<endl;
}