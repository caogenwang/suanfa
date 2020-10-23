#include <stdio.h>
#include <iostream>
#include <vector>
class Solution {
public://寻找转折点
    int wiggleMaxLength(std::vector<int>& nums) {
        const static int START = 0;
        const static int UP = 1;
        const static int DOWN = 2;
        int state = START;
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            switch (state)
            {
                case START:
                    if(nums[i]<nums[i-1])
                        state = DOWN;
                    else
                        state = UP;
                    count++;
                    std::cout<<nums[i]<<std::endl;
                    break;
                case UP:
                    if(nums[i]<nums[i-1])
                    {
                        state = DOWN;
                        count++;
                        std::cout<<nums[i]<<std::endl;
                    }
                    break;
                case DOWN:
                    if(nums[i]>nums[i-1])
                    {
                        state = UP;
                        count++;
                        std::cout<<nums[i]<<std::endl;
                    }
                    break;
                default:
                    break;
            }
        }
        return count;
    }
};

int main(){
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(17);
	nums.push_back(5);
	nums.push_back(10);
	nums.push_back(13);
	nums.push_back(15);
	nums.push_back(10);
	nums.push_back(5);
	nums.push_back(16);
	nums.push_back(8);
	Solution solve;
	printf("%d\n", solve.wiggleMaxLength(nums));
	return 0;
}
