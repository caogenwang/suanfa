#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
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