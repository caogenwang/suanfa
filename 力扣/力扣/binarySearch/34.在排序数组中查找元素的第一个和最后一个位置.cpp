#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int right = size - 1;
        int left = 0;
        while (left <= right)
        {
            int mid = (right-left)/2+left;
            
        }
        
    }
};
/*第一次找到左边界，第二次调用找到右边界,两次寻找的不同等号*/
class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        if (right == nums.size() || nums[right] != target)
            return res;
        res[0] = right;
        left = right;
        right = nums.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        res[1] = right - 1;
        return res;
    }
};

vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> res(2, -1);
    int left = 0, right = nums.size();
    while (left <= right){
        int mid = (left+right)/2;
        if (target < nums[mid])
            left = mid+1;
        else
            right = mid;
    }
    
}

int main()
{
    vector<int>nums{5,7,7,8,8,10};
    int target = 8;
    vector<int> res = searchRange(nums,target);
    cout<<res[0]<<" "<<res[1];
}