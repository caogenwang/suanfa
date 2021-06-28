#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
/*
    输入一个字符串，打印出该字符串中字符的所有排列。
    你可以以任意顺序返回这个字符串数组，但里面不能有重复元素
*/
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> all;
        set<string> all_set;
        helper(s,all,0,all_set);
        return all;
    }
    void helper(string origin,vector<string>& res,int start,set<string> &all_set){
        if(start >= origin.size() && all_set.find(origin) == all_set.end())
        {
            res.push_back(origin);
            all_set.insert(origin);
        }

        for (int i = start; i < origin.length(); i++){
            swap(origin,start,i);
            helper(origin,res,start+1,all_set);
            swap(origin,start,i);
        }
    }
    void swap(string &s,int i,int j){
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
};

int main(){
    Solution s;
    string str = "aac";
    vector<string> res = s.permutation(str);
    for (int i = 0; i < res.size(); i++){
        std::cout<<res[i]<<std::endl;
    }
}