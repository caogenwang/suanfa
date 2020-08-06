#include <vector>
#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

bool canJump(vector<int> nums,int size)
{
    vector<int> dp;
    for(int i=0;i<size;i++)
    {
        dp.push_back(i + nums[i]);
    }
    int max = dp[0];
    for (int i = 1; i < size && i <= max; i++)//i <= max是一个重要条件，必须可以jump到第i点
    {
        if (max < dp[i])
        {
            max = dp[i];
        }
    }
    if (max>=size)
    {
        return true;
    }
    return false;
}

int leastJump(vector<int> &nums,int size)
{
  if (nums.size() < 2){
	    	return 0;
	    }
    int step = 1;
    int cur_max_index = nums[0];
    int pre_max_index = nums[0];
    for (int i = 0; i < size; i++)
    {
        if (i > cur_max_index)
        {
            step ++;
            cur_max_index = pre_max_index;
        }
        if (pre_max_index < nums[i] + i){
       		pre_max_index = nums[i] + i;
    	}
    }
    return step;
}


int main(int argc,char**argv)
{
    vector<int> nums = {0,0,0,0,4};
    int n = 5;
    bool isJump = canJump(nums,n);
    cout<<isJump<<endl;
    int count = leastJump(nums,n);
    cout<<count<<endl;
}