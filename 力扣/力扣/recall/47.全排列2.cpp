#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute2(vector<int>& nums) {
        vector<vector<int> > tmp;
        vector<int> item;
        set<vector<int> > all_set;
        generate(nums,0,tmp,all_set);
        return tmp;
    }

    void generate(vector<int>& num,int start,vector<vector<int> > &res,set<vector<int> > &all_set)
    {
        if(start >= num.size() && all_set.find(num) == all_set.end())
        {
            res.push_back(num);
            all_set.insert(num);
        }
        for(int i = start;i < num.size();++i)
        {
            swap(num[start],num[i]);
            generate(num, start + 1, res,all_set);
            swap(num[start], num[i]);
        }
    }
};

int main()
{
    vector<int> nums{1,1,2};
    Solution s;
    vector<vector<int> > res = s.permute2(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
