
#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*medium*/
/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，
找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。
*/
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
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> out;
        combinationSumDFS(candidates, target, 0, out, res);
        return res;
    }
    void combinationSumDFS(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res) {
        if (target < 0) 
            return;
        if (target == 0) 
        {
            res.push_back(out); 
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            out.push_back(candidates[i]);
            combinationSumDFS(candidates, target - candidates[i], i, out, res);
            out.pop_back();
        }
    }
};

int main()
{
    vector<int> nums{2,3,6,7};
    int target = 7;
    Solution s;
    vector<vector<int> > res = s.combinationSum(nums,target);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}