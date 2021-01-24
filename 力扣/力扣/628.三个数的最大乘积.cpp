#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int p = nums[0] * nums[1] * nums[n - 1];
        return max(p, nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }
};

int main()
{
    vector<int>nums{1,2,3,4};
    Solution s;
    int res = s.maximumProduct(nums);
    cout<<res<<endl;
    return 0;
}