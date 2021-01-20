#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int num = 0;
        int i=0,j=0;
        while (i < g.size() && j < s.size())
        {
            if (s[j]>= g[i])
            {
                i++;
            }
            j++;
        }
        return i;
    }
};

int main()
{
    vector<int> g{5,10,2,15,9};//需求因子
    vector<int> s{6,1,20,3,8};//糖果大小
    Solution s1;
    int num = s1.findContentChildren(g,s);
    cout<<num<<endl;
}