#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;
/*
    以 i 位置结尾的最长连续子数组的长度，因为这个状态可以反映 i 位置及其前面区间的情况。
    下一个位置 i + 1 可以根据 dp[i] 就知道了前面的情况，再根据 arr[i + 1] 和 arr[i] 的大小关系，
    能更新状态 dp[i + 1]
*/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int length = arr.size();
        vector<int> down(length,0);
        vector<int> up(length,0);
        int maxLen = 1;
        up[0] = 1;
        down[0] = 1;
        for (int i = 1; i < length; i++)
        {
            if (arr[i]>arr[i-1]){
                up[i] = down[i-1] + 1;
                down[i] = 1;
            }
            else if(arr[i]<arr[i-1])
            {
                down[i] = up[i-1] + 1;
                up[i] = 1;
            }
            else
            {
                up[i] = 1;
                down[i] = 1;
            }
            maxLen = max(maxLen,max(up[i],down[i]));
        }
        return maxLen;    
    }
};

int main()
{
    vector<int> nums{9,4,2,10,7,8,8,1,9};
    Solution su;
    int res = su.maxTurbulenceSize(nums);
    cout<<res<<endl;
}