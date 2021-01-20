#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
    我们定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。
    然后我们定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。它们的递推式为：

    local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)
    global[i][j] = max(local[i][j], global[i - 1][j])

    其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值中取较大值，
    而全局最优比较局部最优和前一天的全局最优
*/
class Solution0 {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) 
            return 0;
        int n = prices.size(); 
        int g[n][3] = {0}, l[n][3] = {0};
        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= 2; ++j) {
                l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
                g[i][j] = max(l[i][j], g[i - 1][j]);
            }
        }
        return g[n - 1][2];
    }
};

class Solution1 {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) 
            return 0;
        int g[3] = {0};
        int l[3] = {0};
        for (int i = 0; i < prices.size() - 1; ++i) 
        {
            int diff = prices[i + 1] - prices[i];
            for (int j = 2; j >= 1; --j) 
            {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(l[j], g[j]);
            }
        }
        return g[2];
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};

int main()
{
    vector<int> prices{3,3,5,0,0,3,1,4};
    Solution1 s2;
    int profit = s2.maxProfit(prices);
    cout<<profit<<endl;
    return 0;
}