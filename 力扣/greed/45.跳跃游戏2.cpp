#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int pre_max = nums[0];
        int cur_max = nums[0];
        int steps = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (i > cur_max)
            {
                cur_max = pre_max;
                steps ++;
            }
            if (pre_max < i + nums[i])
            {
                pre_max = i + nums[i];
            }
        }
        return steps;
    }
};
class Solution2 {
public:
    int jump(vector<int>& nums) {
        int res = 0, n = nums.size(), i = 0, cur = 0;
        while (cur < n - 1) {
            ++res;
            int pre = cur;
            for (; i <= pre; ++i) {
                cur = max(cur, i + nums[i]);
            }
            if (pre == cur) return -1; // May not need this
        }
        return res;
    }
};

class Solution3 {
public:
    int jump(std::vector<int>& nums) {
    	if (nums.size() < 2){
	    	return 0;
	    }
        int current_max_index = nums[0];
        int pre_max_max_index = nums[0];
        int jump_min = 1;
        for (int i = 1; i < nums.size(); i++){
        	if (i > current_max_index){
        		jump_min++;
	        	current_max_index = pre_max_max_index;
	        }
        	if (pre_max_max_index < nums[i] + i){
       			pre_max_max_index = nums[i] + i;
        	}
        }
        return jump_min;
    }
};

int main()
{
    vector<int>nums{2,3,1,1,4};
    Solution3 s;
    int res = s.jump(nums);
    cout<<res<<endl;
}