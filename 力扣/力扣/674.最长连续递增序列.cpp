#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

/* 连续递增的子序列*/
class Solution {/*错误*/
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> stack;
        stack.push_back(nums[0]);
        int max_len = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (stack.back() > nums[i])
            {
                if (max_len<stack.size())
                {
                    max_len = stack.size();
                }
                stack.clear();
            }
            stack.push_back(nums[i]);
        }
        return max_len;
    }
};

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0, cnt = 0, cur = INT_MAX;
        for (int num : nums) {
            if (num > cur) 
                ++cnt;
            else 
                cnt = 1;
            res = max(res, cnt);
            cur = num;
        }
        return res;
    }
};

int main()
{
    int nums[5] = {1,3,5,4,7};
    vector<int> vec(nums,nums+5);
    Solution su;
    int res = su.findLengthOfLCIS(vec);
    cout<<res<<endl;
}