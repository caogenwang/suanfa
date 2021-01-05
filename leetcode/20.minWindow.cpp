#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <fstream>
#include <limits.h>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {//在S中包含T的最小字符串
        string res = "";
        int left = 0;
        int cnt = 0;
        int length = S.length;
        int minLen = INT_MAX;
        unordered_map<char,int> letterCnt;
        for(char c:T)//记录要包含的字符
            letterCnt[c] = letterCnt[c] + 1;
        for(int i=0;i<length;i++)
        {
            if(--letterCnt[S[i]] >= 0)//S中存在T中的字符
                cnt++;//记录包含的字符个数
            while (cnt == T.size())//letterCnt中包含所有T中的字符了
            {
                if(minLen > i - left + 1)
                {
                    minLen = i - left + 1;
                    res = S.substr(left,minLen);
                }
                if(++letterCnt[S[i]]>0)//当前节点是存在T中的
                    cnt--;
                left++;
            }
        }
        return res;
    }
};


int main()
{

}

string minwindows(string s,string t)
{
    string res = "";
    int length = s.size();
    int left = 0;
    int cnt = 0;
    int minLen = INT_MAX;
    unordered_map<char,int> letterCnt;
    for (char c :t)
        letterCnt[c] = letterCnt[c] + 1;
    for (int i = 0; i < length; i++)
    {
        if(--letterCnt[s[i]] >= 0)
            cnt++;
        while (cnt == t.size())
        {
            if (minLen > i - left + 1)
            {
                minLen = i - left + 1;
                res = s.substr(left,minLen);
            }
            if(++letterCnt[s[i]]>0)
                cnt --;
            left ++;
        }
        return res;
    }
}

string minwindowns2(string s,string t)
{

}