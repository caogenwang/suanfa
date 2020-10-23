#include <stdio.h>
#include <iostream>
#include <vector>
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        std::vector<int> dp;
        for (int i = 0; i < nums.size(); i++)
        {
            dp.push_back(i + nums[i]);
        }
        int jump = 0;
        int max_index = dp[0];
        while(jump < dp.size() && jump <= max_index)
        {
        	if (max_index < dp[jump])//max_index得不到更新的条件是，以后的步数越来越小，一直都会更新一个最大的index
            {
	        	max_index = dp[jump];
	        }
        	jump++;
        }
        if (jump == dp.size()){
        	return true;
        }
        return false;
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
	printf("%d\n", solve.canJump(nums));
	return 0;
}
