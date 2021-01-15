
#include<iostream>
#include<vector>
using namespace std;
//dp[i] 表示以 nums[i] 为结尾的最长递增子串的长度
 int lengthOfLIS(std::vector<int>& nums) {
    	if (nums.size() == 0){
	    	return 0;
	    }
        std::vector<int> dp(nums.size(), 0);//以当前数为结尾的最大连续递增子序列
        dp[0] = 1;
        int LIS = 1;
        for (int i = 1; i < dp.size(); i++){
        	dp[i] = 1;
        	for (int j = 0; j < i; j++){
	        	if (nums[i] > nums[j] && dp[i] < dp[j] + 1){
	        		dp[i] = dp[j] + 1;
	        	}
	        }
	        if (LIS < dp[i]){
        		LIS = dp[i];
        	}
        }
        return LIS;
    }

int main()
{
    int test[] = {10, 9, 2, 5, 3, 7, 101, 18};
	std::vector<int> nums;
	for (int i = 0; i < 6; i++){
		nums.push_back(test[i]);
	}
	printf("%d\n", lengthOfLIS(nums));
	return 0;
}