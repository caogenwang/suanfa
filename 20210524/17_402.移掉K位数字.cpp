/*
    给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，
    使得剩下的数字最小。请你以字符串形式返回这个最小的数字。

    输入：num = "1432219", k = 3
    输出："1219"
    解释：移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219 

*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> Q;
        Q.push_back(num[0]);
        for (int i = 1; i < num.size(); i++)
        {
            while (!Q.empty() && Q.back()>num[i] && k>0)
            {
                Q.pop_back();
                k--;
            }
            if (!Q.empty() || num[i] != '0')
            {
                Q.push_back(num[i]);
            }
        }

        while (Q.size() != 0 && k>0)
        {
            Q.pop_back();
            k--;
        }
        string s;
        for(int i = 0;i < Q.size();i++)
        {
            s += Q[i];
        }
        return s.length()==0?"0":s;
    }
};



class Solution_copy{
    string removeKdigit(string nums,int k){
        vector<char> Q;
        Q.push_back(nums.at(0));
        for (int i = 0; i < nums.size(); i++)
        {
            while(!Q.empty() && Q.back() > nums[i] && k > 0)
            {
                Q.pop_back();
                k--;
            }
            if(!Q.empty() || nums[i] != '0'){
                Q.push_back(nums[i]);
            }
        }
        while (Q.size() != 0 && k>0)
        {
            Q.pop_back();
            k--;
        }
        string s;
        for (int i = 0; i < Q.size(); i++)
        {
            s += Q[i];
        }
        return s.length() == 0 ?"0":s;
    }
};

int main(){

}