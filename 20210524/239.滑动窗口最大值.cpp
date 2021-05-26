/*
    给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
    你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
    返回滑动窗口中的最大值。

    输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
    输出：[3,3,5,5,6,7]
    解释：
    滑动窗口的位置                最大值
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
    1 [3  -1  -3] 5  3  6  7       3
    1  3 [-1  -3  5] 3  6  7       5
    1  3  -1 [-3  5  3] 6  7       5
    1  3  -1  -3 [5  3  6] 7       6
    1  3  -1  -3  5 [3  6  7]      7
*/
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> Qmax;//队列中存放的是下标
        std::vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        { 
            while (!Qmax.empty() && nums[Qmax.back()] <= nums[i])//不为0，同时新增加的元素比较大，就得将小的删掉
            {
                Qmax.pop_back();
            }
            Qmax.push_back(i);
            if (Qmax.front() == i - k)//超过一个窗口就得删掉队头元素，font位置记录的是最大值的下标，只要满足一个窗口
            {
                Qmax.pop_front();//Qmax中只有一个值
            }
            if (i >= k-1)//满足一个窗口了
            {
                res.push_back(nums[Qmax.front()]);
            }
        }
        return res;
    }

    vector<int> minSlidingWindow(vector<int>& nums, int k) {
        deque<int> minQ;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!minQ.empty() && nums[minQ.back()] > nums[i])
            {
                minQ.pop_back();
            }
            minQ.push_back(i);
            if(minQ.front() == i - k){
                minQ.pop_front();
            }
            if(i >= k-1)
                res.push_back(nums[minQ.front()]);
        }
        return res;
    }

    vector<int> diff_array(vector<int> &minArr,vector<int> &maxArr){
        vector<int> res;
        for (int i = 0; i < minArr.size(); i++)
        {
            res.push_back(maxArr[i] - minArr[i]);
        }
        return res;
    }
};

int main(){
    vector<int>nums{1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution s;
    vector<int> res1 = s.maxSlidingWindow(nums,k);
    for (int i : res1)
        cout<<i<<" ";
    cout<<endl;
    vector<int> res2 = s.minSlidingWindow(nums,k);
    for (int i : res2)
        cout<<i<<" ";
    cout<<endl;
    vector<int> res3 = s.diff_array(res1,res2);
    for (int i : res3)
        cout<<i<<" ";
    cout<<endl;
}