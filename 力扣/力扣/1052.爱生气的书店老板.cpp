#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;
/*  
    我们将 customer 数组的值分为三部分， leftsum, winsum, rightsum。
    我们题目的返回值则是三部分的最大和
*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int leftsum = 0;
        int midsum = accumulate(customers.begin(),customers.begin()+X,0);
        int rightsum = 0;
        for (int i = X; i < grumpy.size(); i++)
            if (grumpy[i] == 0)
                rightsum += customers[i];
        int max = leftsum + midsum + rightsum;
        for (int i = X; i < grumpy.size(); i++)
        {
            if(grumpy[i-X] == 0)
                leftsum += customers[i-X];
            midsum = midsum - customers[i-X] + customers[i];
            if (grumpy[i] == 0)
                rightsum -= customers[i];
            int tmp = leftsum + midsum + rightsum;
            if(tmp > max)
                max = tmp;
        }
        return max;
    }
};

class Solution2 {
    int maxSatisfied(vector<int>&customers, vector<int>&grumpy, int X) {

        int winsum = 0;
        int rightsum = 0;
        int len = customers.size();
        //右区间的值
        for (int i = X; i < len; ++i) {
            if (grumpy[i] == 0) {
                rightsum += customers[i];
            }
        }
        //窗口的值
        for (int i = 0; i < X; ++i) {        
              winsum += customers[i];          
        }
        int leftsum = 0;
        //窗口左边缘
        int left = 1;
        //窗口右边缘
        int right = X;
        int maxcustomer = winsum + leftsum + rightsum;     
        while (right < customers.size()) {
            //重新计算左区间的值，也可以用 customer 值和 grumpy 值相乘获得
            if (grumpy[left-1] == 0) {
                leftsum += customers[left-1];
            }
            //重新计算右区间值
            if (grumpy[right] == 0) {
                rightsum -= customers[right];
            }
            //窗口值
            winsum = winsum - customers[left-1] + customers[right];
            //保留最大值
            maxcustomer = ::max(maxcustomer,winsum+leftsum+rightsum);
            //易懂窗口
            left++;
            right++;
        }        
        return maxcustomer;
    }
};

int main(){
    vector<int> customers {1};
    vector<int> grumpy    {0};
    int X = 1;

    Solution so;
    int res = so.maxSatisfied(customers,grumpy,X);
    cout<<res<<endl;
}
