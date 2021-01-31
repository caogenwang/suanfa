#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {//超出时间限制
        if (nums.size() <= 0)
        {
            return -1;
        }
        for(int i=0;i<nums.size();i++)
        {
            int left = 0;
            int right = 0;
            for (int j = i-1; j >=0; j--)
            {
                left += nums[j];
            }
            for (int k = i+1; k < nums.size(); k++)
            {
                right += nums[k];
            }
            if (left == right)
            {
                return i;
            }
        }
        return -1;
    }
};

class Solution2 {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((total - nums[i]) == sum*2)
                return i;
            sum += nums[i];
        }
        return -1;
    }
};

class Solution3 {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int curSum = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (sum - nums[i] == 2 * curSum) 
                return i;
            curSum += nums[i];
        }
        return -1;
    }
};

int main()
{
    vector<int>nums{-1,-1,-1,0,1,1};
    Solution2 s;
    int res = s.pivotIndex(nums);
    cout<<res<<endl;
}