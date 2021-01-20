#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution1 {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) 
            return s;
        int n = s.size(), maxLen = 0, start = 0;
        for (int i = 0; i < n - 1; ++i) 
        {
            searchPalindrome(s, i, i, start, maxLen);
            searchPalindrome(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }
    void searchPalindrome(string s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) 
        {
            --left; 
            ++right;
        }
        if (maxLen < right - left - 1) {
            start = left + 1;
            maxLen = right - left - 1;
        }
    }
};

class Solution2 {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) 
            return s;
        int n = s.size(), maxLen = 0, start = 0;
        for (int i = 0; i < n;) {
            if (n - i <= maxLen / 2) 
                break;
            int left = i, right = i;
            while (right < n - 1 && s[right + 1] == s[right]) 
                ++right;
            i = right + 1;
            while (right < n - 1 && left > 0 && s[right + 1] == s[left - 1]) 
            {
                ++right; 
                --left;
            }
            if (maxLen < right - left + 1) {
                maxLen = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, maxLen);
    }
};

class Solution3 {
public:
    string longestPalindrome(string s) {
        if (s.empty()) 
            return "";
        int n = s.size(), left = 0, len = 1;
        vector<vector<int> > dp(s.size(),vector<int>(s.size(),0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
            for (int j = 0; j < i; ++j) {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                if (dp[j][i] && len < i - j + 1) {
                    len = i - j + 1;
                    left = j;
                }
            }
        }
        return s.substr(left, len);
    }
};
/*动态规划*/
/*
复杂度分析

时间复杂度：O(n^2)O(n 
2
 )，其中 nn 是字符串的长度。动态规划的状态总数为 O(n^2)O(n 
2
 )，对于每个状态，我们需要转移的时间为 O(1)O(1)。

空间复杂度：O(n^2)O(n 
2
 )，即存储动态规划状态需要的空间
*/
class Solution4 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n,0));
        string ans;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};

int main()
{
    string ss = "babad";
    Solution3 s;
    string res = s.longestPalindrome(ss);
    cout<<res<<endl;
}