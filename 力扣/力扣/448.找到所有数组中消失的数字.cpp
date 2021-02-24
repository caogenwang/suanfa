#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {//使用额外空间了
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       set<int> array_set(nums.begin(),nums.end());
       vector<int> res;
       for (int i = 1; i <= nums.size(); i++)
           if (array_set.find(i) == array_set.end())
               res.push_back(i);
       return res;
    }
};
/*
真正求解本题需要用到一个奇技淫巧：原地修改数组。
这个思想来自于长度为 N 的数组可以用来统计 1~N1 N 各数字出现的次数；
题目给出的数组的长度正好为 N，所以可以原地修改数组实现计数。
当前元素是 nums[i]，那么我们把第 nums[i] - 1 位置的元素 乘以 -1，
表示这个该位置出现过。当然如果 第 nums[i] - 1位置的元素已经是负数了，
表示 nums[i]已经出现过了，就不用再把第 nums[i] - 1nums[i]−1 位置的元素乘以 -1。最后，
对数组中的每个位置遍历一遍，如果 i 位置的数字是正数，说明 i 未出现过。
*/
class Solution2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;//当前数字，按照顺序所在的数组位置
            nums[idx] = (nums[idx] > 0) ? -nums[idx] : nums[idx];//没有出现的数字的位置就得不到修改
            cout<<idx<<" "<<nums[idx]<<endl;
        }

        // for (auto &&i : nums)
        // cout<<i<<" "<<endl;   

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums{4,3,2,7,8,2,3,1};
    Solution2 so;
    vector<int> res = so.findDisappearedNumbers(nums);
    // for (auto &&i : res)
    //     cout<<i<<endl;    
}