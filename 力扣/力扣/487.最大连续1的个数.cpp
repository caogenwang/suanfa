#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0,count = 1,cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                if (count == 1)
                {
                    cnt ++;
                    count --;
                }
                else
                {
                    count = 1;
                    cnt = 0;
                }
            }
            else
            {
                cnt ++;
            }
            max = ::max(max,cnt);
        }
        return max;
    }
};

class Solution2 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cur = 0, cnt = 0;
        for (int num : nums) {
            ++cnt;
            if (num == 0) {
                cur = cnt;
                cnt = 0;
            } 
            res = max(res, cnt + cur);
        }
        return res;
    }
};

class Solution3 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, zero = 0, left = 0, k = 1;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) ++zero;
            while (zero > k) {
                if (nums[left++] == 0) --zero;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};


int main()
{
    vector<int> nums{1,0,1,1,0};
    Solution so;
    int res = so.findMaxConsecutiveOnes(nums);
    cout<<res<<endl;
}