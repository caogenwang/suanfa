#include <iostream>
#include <vector>
using namespace std;
/*dp[i]以nums[i]为结尾的最长上升子序列*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1,0);
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i-1])
            {
                dp[i] = dp[i-1]+1; 
            }
            else
            {
                dp[i] = dp[i-1];
            }
        }
        return dp[nums.size()];
    }
};

int main()
{
    int test[] = {1, 3, 2, 3, 1, 4};
	std::vector<int> nums;
	for (int i = 0; i < 6; i++){
		nums.push_back(test[i]);
	}
	Solution s;
    int len = s.lengthOfLIS(nums);
}
