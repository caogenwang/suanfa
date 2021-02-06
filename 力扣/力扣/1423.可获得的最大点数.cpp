#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <numeric>
using namespace std;

class Solution {//首尾的滑动窗口
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxPoint = accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
        int sum = maxPoint;
        int right = 0;
        int length = cardPoints.size();
        int i = k - 1;
        while (right < k)
        {
            right = k - i -1;
            if (right != 0)
                sum += cardPoints[length - right];
            if (sum>maxPoint)
                maxPoint = sum;
            if(i>=0)
                sum -= cardPoints[i];
            i --;
        }
        return  maxPoint;      
    }
};

int main()
{
    int a[7] = {1,2,3,4,5,6,1};
    vector<int> nums(a,a+7);
    int k = 3;
    Solution so;
    int res = so.maxScore(nums,k);
    cout<<res<<endl;
}

