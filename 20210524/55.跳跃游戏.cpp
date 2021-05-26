#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool canJump(vector<int> &nums){
        int jump = 0;
        for (int i = 0; i < nums.size(); i++){
            if(i > jump || jump >= nums.size())
                break;
            jump = ::max(jump,i + nums[i]);
        }
        return jump >= nums.size() - 1;
    }
};

int main()
{
    vector<int> nums{3,2,1,0,4};
    Solution s;
    bool res = s.canJump(nums);
    cout<<res<<endl;
    
}