#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <fstream>
#include <limits.h>
#include <vector>
using namespace std;
//给出一组数字，返回该组数字的所有排列,存在重复的数字
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> res;
        vector<int> out,visited(num.size(),0);
        sort(num.begin(),num.end());
        permuteUniqueDFS(num,0,visited,out,res);
        return res;
    }
    void permuteUniqueDFS(vector<int>& nums, int level, 
        vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
        if(level >= nums.size())
        {
            res.push_back(out);
            return;
        }
        for(int i = 0;i < nums.size();i++)
        {
            if (visited[i] == 1) 
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) 
                continue;
            visited[i] = 1;
            out.push_back(nums[i]);
            permuteUniqueDFS(nums, level + 1, visited, out, res);
            out.pop_back();
            visited[i] = 0;
        }
    }
};

class Solution2 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        permute(nums, 0, res);
        return vector<vector<int>> (res.begin(), res.end());
    }
    void permute(vector<int>& nums, int start, set<vector<int>>& res) {
        printf("start:%d\n",start);
        for (int j = 0; j < nums.size(); j++)
        {
            cout<<nums[j];
        }
        cout<<endl<<endl;;
        if (start >= nums.size()) 
            res.insert(nums);
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[i] == nums[start]) 
                continue;
            swap(nums[i], nums[start]);
            permute(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
};

int main(int argc,char**argv)
{
    int a[5]={1,2,3,4,5};
    vector<int> b(a,a+5);
    vector<int> &c=b;
    vector<vector<int> > res;
    Solution2 s;
    res = s.permuteUnique(c);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j];
        }
        cout<<endl;
    }
    return 0;
}