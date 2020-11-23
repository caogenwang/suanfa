#include<iostream>
#include<vector>
using namespace std;

int max_robery(vector<int>& nums)
{
    if (nums.size() == 0){
	    	return 0;
	    }
    if (nums.size() == 1){
        return nums[0];
    }
    std::vector<int> dp(nums.size(), 0);//选择当前房间所能获得的最大值
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++){
        dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[nums.size() - 1];
}

int main()
{
    vector<int> house{5,2,6,3,1,7};
    printf("%d\n",max_robery(house));
}