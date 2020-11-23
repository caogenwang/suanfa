#include<iostream>
#include<vector>
using namespace std;

bool generate(int i,vector<int> &nums,int target,int bucket[])
{
    if(i >= nums.size())
        return bucket[0]==target && bucket[1]==target && bucket[2]==target && bucket[3]==target;
    for (int j = 0; j < 4; j++)
    {
        if(bucket[j]+nums[i] > target)
        {
            continue;
        }
        bucket[j]+=nums[i];
        if(generate(i+1,nums,target,bucket))
        {
            return true;
        }
        bucket[j]-=nums[i];
    }
    return false;
}

bool makesquare(vector<int> &nums)
{
    if(nums.size() < 4)
        return false;
    int sum=0;
    for(auto num:nums)
        sum+=num;
    if(sum%4)
        return false;
    sort(nums.rbegin(),nums.rend());
    int bucket[4] = {0};
    return generate(0,nums,sum/4,bucket);
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    printf("%d\n",makesquare(nums));
}