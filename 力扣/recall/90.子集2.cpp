#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > tmp;
        vector<int> item;
        sort(nums.begin(),nums.end());
        set<vector<int> > set_items;
        set_items.insert(item);
        tmp.push_back(item);
        generate(0,nums,tmp,item,set_items);
        return tmp;
    }

    void generate(int i,vector<int>& nums,vector<vector<int> > &res,vector<int> &item,set<vector<int> > &set_items)
    {
        if (i >= nums.size())
        {
            return;
        }
        item.push_back(nums[i]);

        if(set_items.find(item) == set_items.end())
        {
            res.push_back(item);
            set_items.insert(item);
        }

        generate(i+1,nums,res,item,set_items);
        item.pop_back();
        generate(i+1,nums,res,item,set_items);
    }
};

int main()
{
    vector<int> nums{1,2,2};
    Solution s;
    vector<vector<int> > res = s.subsetsWithDup(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    
}