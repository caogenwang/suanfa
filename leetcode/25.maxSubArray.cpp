#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <fstream>
#include <limits.h>
using namespace std;

/*
请计算给出的数组（至少含有一个数字）中具有最大和的子数组（子数组要求在原数组中连续
*/
class Solution1 {
public:
    int maxSubArray(int A[], int n) {
        int res = INT_MIN, curSum = 0;
        for (int i=0;i<n;i++ ) {
            int num = A[i];
            curSum = max(curSum + num, num);
            res = max(res, curSum);
        }
        return res;
    }
};

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        return helper(nums, 0, (int)nums.size() - 1);
    }
    int helper(vector<int>& nums, int left, int right) {
        if (left >= right) return nums[left];
        int mid = left + (right - left) / 2;
        int lmax = helper(nums, left, mid - 1);
        int rmax = helper(nums, mid + 1, right);
        int mmax = nums[mid], t = mmax;
        for (int i = mid - 1; i >= left; --i) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        t = mmax;
        for (int i = mid + 1; i <= right; ++i) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        return max(mmax, max(lmax, rmax));
    }
};

int main(int argc,char**argv)
{
    int a[9] = {-2,1,-3,4,-1,2,1,-5,4}; 
    return 0;
}