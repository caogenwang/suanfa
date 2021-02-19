#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0,count = 0;
        for (int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)
                count ++;
            else
                count = 0;
            max = max>count?max:count;
        }
        return max;
    }
};

class Solution2 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (int num : nums) {
            cnt = (num == 0) ? 0 : cnt + 1;
            res = max(res, cnt);
        }
        return res;
    }
};

int main()
{
    vector<int> nums{1,1,0,1,1,1};
    Solution so;
    int res = so.findMaxConsecutiveOnes(nums);
    cout<<res<<endl;
}