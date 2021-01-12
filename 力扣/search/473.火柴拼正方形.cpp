#include <iostream>
#include <vector>
#include <queue>
#include<numeric>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4)
            return false;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum%4)
        {
            return false;
        }
        std::sort(nums.rbegin(),nums.rend());
        int bucket[4] = {0};
        return generate(0,nums,sum/4,bucket);
    }

    bool generate(int i,vector<int>&nums,int target,int bucket[])
    {
        if(i>=nums.size())
        {
            return bucket[0] == target && bucket[1] == target && bucket[2] == target && bucket[3] == target;
        }

        for (int j = 0; j < 4; j++)
        {
            if (bucket[j] + nums[i] > target)
            {
                continue;
            }
            bucket[j] += nums[i];
            if (generate(i+1,nums,target,bucket))
            {
                return true;
            }
            bucket[j] -= nums[i];
        }
        return false;
    }
};

class Solution2 {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.empty() || nums.size() < 4) 
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) 
            return false;
        vector<int> sums(4, 0);
        sort(nums.rbegin(), nums.rend());
        return helper(nums, sums, 0, sum / 4);
    }
    bool helper(vector<int>& nums, vector<int>& sums, int pos, int target) {
        if (pos >= nums.size()) {
            return sums[0] == target && sums[1] == target && sums[2] == target;
        }
        for (int i = 0; i < 4; ++i) {
            if (sums[i] + nums[pos] > target) 
                continue;
            sums[i] += nums[pos];
            if (helper(nums, sums, pos + 1, target)) 
                return true;
            sums[i] -= nums[pos];
        }
        return false;
    }
};

class Solution3 {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.empty() || nums.size() < 4) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) return false;
        int n = nums.size(), all = (1 << n) - 1, target = sum / 4;
        vector<int> masks, validHalf(1 << n, false);
        for (int i = 0; i <= all; ++i) {
            int curSum = 0;
            for (int j = 0; j <= 15; ++j) {
                if ((i >> j) & 1) curSum += nums[j];
            }
            if (curSum == target) {
                for (int mask : masks) {
                    if ((mask & i) != 0) continue;
                    int half = mask | i;
                    validHalf[half] = true;
                    if (validHalf[all ^ half]) return true;
                }
                masks.push_back(i);
            }
        }
        return false;
    }
};


int main()
{
    vector<int> nums{1,1,2,2,2};
    Solution s;
    cout<<s.makesquare(nums)<<endl;

}
