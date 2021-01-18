#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > tmp;
        vector<int> item;
        sort(candidates.begin(),candidates.end());
        set<vector<int> > set_items;
        generate(0,candidates,tmp,item,set_items,target,0);
        return tmp;
    }

    void generate(int i,vector<int>& nums,vector<vector<int> > &res,vector<int> &item,set<vector<int> > &set_items,int target,int sum)
    {
        if (i >= nums.size() || sum > target)
        {
            return;
        }
        sum += nums[i];
        item.push_back(nums[i]);

        if(set_items.find(item) == set_items.end() && sum==target)
        {
            res.push_back(item);
            set_items.insert(item);
        }

        generate(i+1,nums,res,item,set_items,target,sum);
        sum -= nums[i];
        item.pop_back();
        generate(i+1,nums,res,item,set_items,target,sum);
    }
};

class Solution2 {
public:
    vector<vector<int> > combinationSum2(vector<int>& num, int target) {
        vector<vector<int> > res;
        vector<int> out;
        sort(num.begin(), num.end());
        helper(num, target, 0, out, res);
        return res;
    }
    void helper(vector<int>& num, int target, int start, vector<int>& out, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) { res.push_back(out); return; }
        for (int i = start; i < num.size(); ++i) {
            if (i > start && num[i] == num[i - 1]) 
                continue;
            out.push_back(num[i]);
            helper(num, target - num[i], i + 1, out, res);
            out.pop_back();
        }
    }
};

int main()
{
    vector<int> nums{10,1,2,7,6,1,5};
    int target = 8;
    Solution s;
    vector<vector<int> > res = s.combinationSum2(nums,target);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}