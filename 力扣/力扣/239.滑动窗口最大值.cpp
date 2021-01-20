#include <iostream>
#include <vector>
#include <deque>
using namespace std;
/*
    给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
    返回滑动窗口中的最大值。
*/
class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> Qmax;//队列中存放的是下标
        int index = 0;
        std::vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        { 
            while (!Qmax.empty() && nums[Qmax.back()] <= nums[i])//不为0，同时新增加的元素比较大，就得将小的删掉
            {
                Qmax.pop_back();
            }
            Qmax.push_back(i);
            if (Qmax.front() == i - k)//超过一个窗口就得删掉队头元素，font位置记录的是最大值的下标，只要满足一个窗口，就是最大值
            {
                Qmax.pop_front();
            }
            if (i >= k-1)//满足一个窗口了
            {
                res.push_back(nums[Qmax.front()]);
            }
        }
        
        return res;
    }
};



int main()
{
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    int k = 3;
    
    Solution1 s1;
    vector<int> res = s1.maxSlidingWindow(nums,k);
    for (auto i : res)
    {
        cout<<i<<endl;
    }
    

}