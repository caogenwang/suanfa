#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos;
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = (right + left)/2;
            if (target == nums[mid])
                return mid;
            if (target < nums[mid])
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }
};
class Solution2 {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= target) return i;
        }
        return nums.size();
    }
};

class Solution3 {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.back() < target) return nums.size();
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};


int main()
{

}
