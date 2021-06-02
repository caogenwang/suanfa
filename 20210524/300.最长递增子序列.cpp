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

int main(){
    vector<int> nums{7,7,7,7,7,7,7,7};
    Solution s;
    int res = s.lengthOfLIS(nums);
    cout<<res<<endl;
}