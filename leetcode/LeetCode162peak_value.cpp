#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;
vector<int> peak_value(const vector<int> &nums)
{
    int left = 0;
    int right = 0;
    vector<int> dp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i==0)
        {
            if (nums[i+1] < nums[i])
            {
                dp.push_back(i);
            }
        }   
        else if (i==nums.size()-1)
        {
            if (nums[i] > nums[i-1])
            {
                dp.push_back(i);
            }
        }
        else
        {
            if (nums[i] > nums[i-1] && nums[i]>nums[i+1])
            {
                dp.push_back(i);
            }
        }
    }
    return dp;
}

//你的解法应该是 O(logN) 时间复杂度的。
int peak_value(vector<int>&nums)
{
    int left = 0;
    int right = nums.size()-1;
    int mid = 1;
    
    while (left < right && (mid-1)>=0)
    {
        mid = left + (right - left)/2;
         while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) 
                left = mid + 1;
            else right = mid;
        }
        return right;
    }
    return 0;
}
int main()
{
    vector<int> nums = {7,2,3,4,5,1,7,0};
    int peak = peak_value(nums);
    printf("peak:%d\n",peak);
    return 0;
}