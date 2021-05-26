/*
给你一个字符串 s，找到 s 中最长的回文子串。

 

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    string longest(string s){
        if (s.size() < 2) return s;

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

int main(){

}


