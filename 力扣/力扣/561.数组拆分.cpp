#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i+=2)
            sum += nums[i];
        
        return sum;
    }
};

class Solution2 {
public:
    int arrayPairSum(vector<int>& nums) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 2) {
            res += nums[i];
        }
        return res;
    }
};


int main()
{
    vector<int>nums{6,2,6,5,1,2};
    Solution so;
    int res = so.arrayPairSum(nums);
    cout<<res<<endl;
}