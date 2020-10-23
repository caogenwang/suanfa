#include <stdio.h>

#include <vector>
class Solution {
public:
    int jump(std::vector<int>& nums) {
        if(nums.size() <2)
            return 0;
        int jump_min = 1;
        int cur_jump_index = nums[0];
        int pre_jump_index = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > cur_jump_index)
            {
                jump_min++;
                cur_jump_index = pre_jump_index;
            }
            if (pre_jump_index < nums[i] + i)
            {
                pre_jump_index = nums[i] + i;
            }
        }
        return jump_min;
    }
};

int main(){
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	Solution solve;
	printf("%d\n", solve.jump(nums));
	return 0;
}