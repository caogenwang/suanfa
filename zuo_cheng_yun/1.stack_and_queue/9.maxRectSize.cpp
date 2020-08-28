#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

int LargestArea1(vector<int> &nums)
{
    stack<int> s;
    int maxArea = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        printf("i:%d\n",i);
        while (!s.empty() && nums[s.top()] >= nums[i])
        {
            int j = s.top();
            s.pop();
            int k = s.empty()?-1:s.top();
            int curArea = (i - k -1)*nums[j];
            maxArea = max(maxArea,curArea);
        }
        s.push(i);
    }
    while (!s.empty())
    {
        int j = s.top();
        s.pop();
        int k = s.empty()?-1:s.top();
        int curArea = (nums.size() - k -1)*nums[j];
        maxArea = max(maxArea,curArea);
    }
    
    return maxArea;
}

int LargestArea2(vector<int> &nums)
{
   int res = 0;
    stack<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        if(s.empty() || nums[s.top()] <= nums[i])
            s.push(i);
        else
        {
            int tmp = s.top();
            s.pop();
            res = max(res,nums[tmp]*(s.empty()?i:(i - s.top() - 1)));
            --i;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {3,4,5,4,3,6};
    int res = LargestArea1(nums);
    printf("%d\n",res);
    return 0;
}
