#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <numeric>
using namespace std;
class Solution {//暴力搜索
public:
    double findMaxAverage(vector<int>& nums, int k) {//n方的复杂度
        double max_avg = findMaxAverageK(nums,k);
        for(int i= k;i<nums.size();i++)
            max_avg = max(max_avg,findMaxAverageK(nums,i));
        return max_avg;
    }

    double findMaxAverageK(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.begin()+k,0);
        double max_avg = (double)sum / k;
        for(int i = k;i<nums.size();i++)
        {
            sum = sum - nums[i-k] + nums[i];
            max_avg = max(max_avg,(double)sum / k);
        }
        return max_avg;
    }
};
/*
    那么可以根据这个特点来确定折半方向，我们通过 left 和 right 值算出来的 mid，可以看作是 
    maxAvg 的一个 candidate，所以就让数组中的每一个数字都减去 mid，然后算差值的累加和，
    一旦发现累加和大于0了，那么说明 mid 比 maxAvg 小，这样就可以判断方向了。

    我们建立一个累加和数组 sums，然后求出原数组中最小值赋给 left，最大值赋给 right，
    题目中说了误差是 1e-5，所以循环条件就是 right 比 left 大 1e-5，然后算出来 mid，

    定义一个 minSum 初始化为0，布尔型变量 check，初始化为 false。然后开始遍历数组，先更新累加和数组 
    sums，注意这个累加和数组不是原始数字的累加，而是它们和 mid 相减的差值累加。我们的目标是找长度大于
    等于k的子数组的平均值大于 mid，由于每个数组都减去了 mid，那么就转换为找长度大于等于k的子数组的差累积
    值大于0。
    
    建立差值累加数组的意义就在于通过 sums[i] - sums[j] 来快速算出j和i位置中间数字之和，
    那么只要j和i中间正好差k个数字即可，然后 minSum 就是用来保存j位置之前的子数组差累积的最小值，
    所以当 i >= k 时，我们用 sums[i - k] 来更新 minSum，这里的 i - k 就是j的位置，
    然后判断如果 sums[i] - minSum > 0了，说明找到了一段长度大于等k的子数组平均值大于 mid 了，
    就可以更新 left 为 mid 了，我们标记 check 为 true，并退出循环。在 for 循环外面，
    当 check 为 true 的时候，left 更新为 mid，否则 right 更新为 mid
*/
class Solution2 {//二分搜索
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> sums(n + 1, 0);
        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());
        while (right - left > 1e-5) {
            double minSum = 0, mid = left + (right - left) / 2;
            bool check = false;
            for (int i = 1; i <= n; ++i) {
                sums[i] = sums[i - 1] + nums[i - 1] - mid;
                if (i >= k) {
                    minSum = min(minSum, sums[i - k]);
                }
                if (i >= k && sums[i] > minSum) {
                    check = true; 
                    break;
                } 
            }
            if (check) 
                left = mid;
            else 
                right = mid;
        }
        return left;
    }
};

int main()
{
    vector<int>nums{1,12,-5,-6,50,3};int k = 4;
    Solution2 so;
    double res = so.findMaxAverage(nums,k);
    // cout<<res<<endl;
}