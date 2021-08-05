#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
/*暴力破解*/
string minWindow(string s, string t) {
    vector<int> tmp(27,0);
    for (int i=0; i<t.length(); i++) {
        tmp[t[i]-'A'] = 1;
    }
    int size = t.length();
    vector<vector<char> > res;
    for (int i =0; i<s.length(); i++) {
        int n = size;
        vector<char> tmp_str;
        vector<char> tmp_pos(tmp.begin(),tmp.end());
        tmp_str.push_back(s[i]);
        if(tmp_pos[s[i]-'A'] == 1){
            tmp_pos[s[i]-'A'] = -1;
            n--;
        }
        for (int j=i+1;j<s.length() ; j++) {
            if (tmp_pos[s[j]-'A'] == -1) {
                
                tmp_str.push_back(s[j]);
            }
            else
            {
                tmp_str.push_back(s[j]);
                if (tmp_pos[s[j]-'A'] == 1) {
                    tmp_pos[s[j]-'A'] = -1;
                    n--;
                }
                if(n==0){
                    res.push_back(tmp_str);
                    break;
                }
            }
        }
    }
    int min = INT_MAX;
    int pos = 0;
    for (int i=0; i<res.size(); i++) {
        if(res[i].size()<min){
            min = res[i].size();
            pos = i;
        }
    }
    string res_str;
    for (int i=0; i<res[pos].size(); i++) {
        res_str += res[pos][i];
    }
    return res_str;
}

class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> letterCnt;
        int left = 0, cnt = 0, minLen = INT_MAX;
        for (char c : t) 
            ++letterCnt[c];//记录所有t中的字符串
        for (int i = 0; i < s.size(); ++i) {
            if (--letterCnt[s[i]] >= 0) //计数器 cnt,遍历到的是t中的字符，所以要cnt加1
                ++cnt;
            while (cnt == t.size()) {//cnt==t.size()得到一个包含全部t的最小子串
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }
                if (++letterCnt[s[left]] > 0)//如果起点去除的是t中的字符串，就将计数减一，退出
                    --cnt;
                ++left;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    string minWindow(string s, string t) {
        vector<int> letterCnt(128, 0);
        int left = 0, cnt = 0, minLeft = -1, minLen = INT_MAX;
        for (char c : t) ++letterCnt[c];
        for (int i = 0; i < s.size(); ++i) {
            if (--letterCnt[s[i]] >= 0) ++cnt;
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    minLeft = left;
                }
                if (++letterCnt[s[left]] > 0) --cnt;
                ++left;
            }
        }
        return minLeft == -1 ? "" : s.substr(minLeft, minLen);
    }
};