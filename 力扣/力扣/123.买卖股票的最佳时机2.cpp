#include <iostream>
#include <vector>

using namespace std;
/*  给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
    设计一个算法来计算你所能获取的最大利润。只能完成两笔交易）。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);

    Solution s;
    int res = s.maxProfit(nums);
    cout<<res<<endl;
    return 0;
}