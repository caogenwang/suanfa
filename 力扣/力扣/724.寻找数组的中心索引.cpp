#include <iostream>
#include <vector>
#include <unordered_map>
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
        if (nums.size() <= 0)
        {
            return -1;
        }
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                sum += 0;
            }
            else{
                sum += nums[i-1];
            }
            if ((total - nums[i])%2 != 0) {
                continue;
            }
            
            int left = (total - nums[i])/2;
            if (left == sum)
            {
                return i;
            }
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