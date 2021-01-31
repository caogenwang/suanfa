#include <iostream>
#include <vector>

using namespace std;

/*
    给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
    如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int tmp = prices[0];
       int pos = 0;
       for (int i = 1; i < prices.size(); i++)
       {
           if (tmp > prices[i])
           {
               tmp = prices[i];
               pos = i;
           }
       }
       int money = 0;
       for (int i = pos+1; i < prices.size(); i++)
       {
           if(money < (prices[i] - tmp))
           {
               money = prices[i] -tmp;
           }
       }
       return money;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, buy = INT_MAX;
        for (int price : prices) {
            buy = min(buy, price);
            res = max(res, price - buy);
        }
        return res;
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