#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_set>
#include <list>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> dict) {
        int length = s.length();
        if(length == 0 || dict.size() == 0)
            return false;
        int wordlen = 0;
        bool result = true;
        bool temp[length];
        for(int i = 0;i < length; i ++)
        {
            for(int j=i;j<length;j++)
            {
                string word = s.substr(i,j-i+1);
                if(dict.find(word) != dict.end())
                {
                    wordlen = word.length();
                    for (int p = i; p <= j; p++)
                    {
                        temp[p] = true;
                    }
                    break;
                }
                temp[j]=false;
            }
            if (wordlen != 0)
            {
                i = i + wordlen - 1;
            }
        }
        for (int p = 0; p < length; p++)
        {
            cout<<temp[p]<<endl;
            result = result && temp[p];
        }
        return result;
    }
};

int main(int argc,char**argv)
{
    string str = "aaaaaaa";
    unordered_set<string> dic = {"aaaa","aaa"};
    Solution s;
    bool r = s.wordBreak(str,dic);
    // cout<<r<<endl;
}

class Solution2 {
public:
    bool wordBreak(string s, unordered_set<string> dict) {
        int len = s.length();
        if (len == 0)
            return false;
        vector<int> dp(len,0);
        if (dict.find(s.substr(0,1)) != dict.end())
            dp[0] = 1;
        
        for(int i=1;i<len;i++)
        {
            for(int j=0;j<=i;j++)
            {
                string y = s.substr(j,i-j+1);
                if ((j==0 && dict.find(y) != dict.end())) 
                {
                    dp[i] = 1;
                    break;
                } else if (dp[j-1] && dict.find(y) != dict.end()) //保证j之前的为一个单词。这时候j位置发现的才是单词
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[len-1]==1;
    }
};