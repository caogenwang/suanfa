#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*暴力方法应该是把1-s.length长度的字符串都试一下*/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxLength = 0;
        for (int i = 1; i < s.length()+1; i++)
            maxLength = max(maxLength,findmaxLength(s,t,i,maxCost));
        return maxLength;
    }

    int findmaxLength(string s,string t,int window,int maxCost)
    {
        int maxLength = 0;
        for (int i = window; i < s.length()+1; i++)
        {
            int cost = maxCost;
            string s1 = s.substr(i-window,window);
            string s2 = t.substr(i-window,window);
            int j = 0;
            while (j < s1.length()){
                if(s1[j] != s2[j])
                    cost -= abs(s1[j] - s2[j]);
                if (cost <= 0)
                    break;
                j++;
            }
            maxLength = max(maxLength,j+1);
        }
        return maxLength;
    }
};
/*
题目啰里吧嗦说了那么一大堆，
其实就是求：
满足|s[i] - t[i]|的和
小于等于maxCost的连续最大个数

那么我们不妨先把|s[i] - t[i]|放入一个数组arr
然后我们用变量left和right维护着一个在数组arr上滑动的窗口
每次窗口滑动时，计算当前窗口所有数字之和nowWindowSum，
如果nowWindowSum小于等于maxCost,
将窗口右边界扩大一个下标即right++，
如果nowWindowSum大于maxCost，说明当前窗口中的数字不符合要求。
那么为了寻找下一个符合要求且大小大于maxLength的窗口，
(maxLength表示当前找到的符合要求的最大长度)
可以将窗口整体向右移动一个下标，即left++、right++。

当窗口滑完整个数组之后，length - 1 - left + 1即为最后窗口的大小，
也就是题目所需的最大长度
*/
class Solution2 {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int length = s.length();
        vector<int> arr(length,0);
        for(int i = 0; i < length; i++) {
            arr[i] = abs(s[i] - t[i]);
        }
        // 当前窗口所有数字之和
        int nowWindowSum = 0;
        // left为当前窗口的左边界，right为当前窗口的右边界
        int left = 0;
        for(int right = 0; right < length; right++) {
            nowWindowSum += arr[right];
            // 当前窗口所有数字之和大于最大预算时
            // 窗口左右边界同时加一，即窗口整体往右移动一个下标    
            if(nowWindowSum > maxCost) {
                nowWindowSum -= arr[left];
                left++;
            }
            // 当前窗口所有数字之和小于等于最大预算时
            // 窗口右边界加一，即窗口往右扩大一个下标
        }
        return length - left;
    }
};

int main()
{
    string s = "abcd"; string t = "bcdf";int  cost = 3;
    Solution2 so;
    int res = so.equalSubstring(s,t,cost);
    cout<<res<<endl;
}