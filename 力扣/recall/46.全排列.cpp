#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > tmp;
        vector<int> item;
        generate(nums,0,tmp);
        return tmp;
    }

    void generate(vector<int>& num,int start,vector<vector<int> > &res)
    {
        if(start >= num.size())
            res.push_back(num);
        for(int i = start;i < num.size();++i)
        {
            swap(num[start],num[i]);
            generate(num, start + 1, res);
            swap(num[start], num[i]);
        }
    }
};

class Solution2 {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        permuteDFS(num, 0, res);
        return res;
    }
    void permuteDFS(vector<int>& num, int start, vector<vector<int>>& res) {
        if (start >= num.size()) res.push_back(num);
        for (int i = start; i < num.size(); ++i) {
            swap(num[start], num[i]);
            permuteDFS(num, start + 1, res);
            swap(num[start], num[i]);
        }
    }
};


int main()
{
    vector<int> nums{1,2,3};
    Solution s;
    vector<vector<int> > res = s.permute(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}