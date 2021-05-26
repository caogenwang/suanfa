#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2)
	    	return 0;
        int pre_max = nums[0];
        int cur_max = nums[0];
        int count = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if(i > cur_max){
                count++;
                cur_max = pre_max;
            }
            if(pre_max < i + nums[i])
                pre_max = i + nums[i];

        }
        return count;
    }
};

int main()
{
    vector<int> nums{2,3,1,1,4};
    Solution s;
    int res = s.jump(nums);
    cout<<res<<endl;
    
}