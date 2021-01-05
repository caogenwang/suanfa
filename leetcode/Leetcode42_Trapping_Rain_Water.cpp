#include <vector>
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int trappingRainWater(const vector<int> &nums)
{
    int sum = 0;
    int left = 0;
    int right = 0;
    int minnum = 0;
    vector<int> dp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i==0)
        {
            if (nums[i+1] < nums[i])
            {
                dp.push_back(i);
            }
        }   
        else if (i==nums.size()-1)
        {
            if (nums[i] > nums[i-1])
            {
                dp.push_back(i);
            }
        }
        else
        {
            if (nums[i] > nums[i-1] && nums[i]>nums[i+1])
            {
                dp.push_back(i);
            }
        }
    }
    int temp = 0;
    for (int i=0;i+1<dp.size();i++)
    {
        left = dp[i];
        right = dp[i+1];
        temp = ::min(nums[left],nums[right]);
        for (int i = left+1; i < right; i++)
        {
            sum += (temp - nums[i]);
        }
    }
    
    return sum;
}
/*
先来看一种方法，这种方法是基于动态规划 Dynamic Programming 的，维护一个一维的 dp 数组，
这个 DP 算法需要遍历两遍数组，第一遍在 dp[i] 中存入i位置左边的最大值，然后开始第二遍遍历数组，
第二次遍历时找右边最大值，然后和左边最大值比较取其中的较小值，然后跟当前值 A[i] 相比，
如果大于当前值，则将差值存入结果，
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, mx = 0, n = height.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = mx;//第一遍在 dp[i] 中存入i位置左边的最大值
            mx = max(mx, height[i]);
        }
        for (int i = 0; i < dp.size(); i++)
        {
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        mx = 0;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = min(dp[i], mx);
            mx = max(mx, height[i]);//第二次遍历时找右边最大值，然后和左边最大值比较取其中的较小值，然后跟当前值 A[i] 相比
            
            if (dp[i] > height[i]) 
                res += dp[i] - height[i];
        }
        return res;
    }
};
/*
再看一种只需要遍历一次即可的解法，这个算法需要 left 和 right 两个指针分别指向数组的首尾位置，
从两边向中间扫描，在当前两指针确定的范围内，先比较两头找出较小值，如果较小值是 left 指向的值，
则从左向右扫描，如果较小值是 right 指向的值，则从右向左扫描，若遇到的值比当较小值小，则将差值存入结果，
如遇到的值大，则重新确定新的窗口范围，以此类推直至 left 和 right 指针重合
*/
class Solution2 {
public:
    int trap(vector<int>& height) {
        int res = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            int mn = min(height[l], height[r]);
            if (mn == height[l]) {
                ++l;
                while (l < r && height[l] < mn) {
                    res += mn - height[l++];
                }
            } else {
                --r;
                while (l < r && height[r] < mn) {
                    res += mn - height[r--];
                }
            }
            printf("l:%d ",l);
            printf("r:%d\n",r);
        }
        return res;
    }
};
//进步一简化版
class Solution3 {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, level = 0, res = 0;
        while (l < r) {
            int lower = height[(height[l] < height[r]) ? l++ : r--];
            level = max(level, lower);
            res += level - lower;
        }
        return res;
    }
};

class Solution5 {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int i = 0, res = 0, n = height.size();
        while (i < n) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i++);
            } else {
                int t = st.top(); st.pop();
                if (st.empty()) continue;
                res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
            }
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    // int sum = trappingRainWater(nums);
    Solution5 s;
    int sum = s.trap(nums);
    cout<<sum<<endl;
    return 0;
}

