#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。
*/
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
        while (k>0)
        {
            Q.pop_back();
            k--;
        }
        
        string s;
        
        
    }
};

int main()
{

}