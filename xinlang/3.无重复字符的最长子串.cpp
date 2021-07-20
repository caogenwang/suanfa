#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <set>

using namespace  std;
class Solution {
public:
    bool isduplicate(string s){
        set<char> visit;
        for (int i=0;i<s.length();i++) {
            if(visit.end() == find(visit.begin(), visit.end(), s[i]))
                visit.insert(s[i]);
            else
                return false;
        }
        return true;
    }

int lengthOfLongestSubstring(string s) {
    if(s.size()<=1)
        return s.size();
    int max = 0;
    vector<string> res;
    for (int i = 0; i < s.length(); i++)
    {
        string tmp;
        tmp += s[i];
        for (int j = i+1; j < s.length(); j++)
        {
            tmp += s[j];
            res.push_back(tmp);
        }
    }
    for(int i=0;i<res.size();i++){
        if(res[i].length()>max &&  isduplicate(res[i])){
            max = res[i].length();
            cout<<res[i]<<endl;
        }
        
    }
    return max;
}
};

int lengthOfLongestSubstring(string s) {
    int res = 0, left = -1, n = s.size();
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
        if (m.count(s[i]) && m[s[i]] > left) {
            left = m[s[i]];
        }
        m[s[i]] = i;
        res = max(res, i - left);
    }
    return res;
}

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

int main(){

}