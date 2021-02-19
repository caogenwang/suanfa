#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       
    }
};

int main()
{
    vector<int> nums{4,3,2,7,8,2,3,1};
    Solution so;
    vector<int> res = so.findDisappearedNumbers(nums);
    for (auto &&i : res)
        cout<<i<<endl;    
}