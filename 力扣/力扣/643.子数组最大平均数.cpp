#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <numeric>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.begin()+k,0);
        double max_avg = (double)sum / k;
        for(int i = k;i<nums.size();i++)
        {
            sum = sum - nums[i-k] + nums[i];
            max_avg = max(max_avg,(double)sum / k);
        }
        return max_avg;
    }
};

int main()
{
    vector<int>nums{1,12,-5,-6,50,3};int k = 4;
    Solution so;
    double res = so.findMaxAverage(nums,k);
    cout<<res<<endl;
}