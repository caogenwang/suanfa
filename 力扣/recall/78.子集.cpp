
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > tmp;
        vector<int> item;
        tmp.push_back(item);
        generate(0,nums,tmp,item);
        return tmp;
    }

    void generate(int i,vector<int>& nums,vector<vector<int> > &res,vector<int> &item)
    {
        if (i >= nums.size())
        {
            return;
        }
        item.push_back(nums[i]);
        res.push_back(item);
        generate(i+1,nums,res,item);
        item.pop_back();
        generate(i+1,nums,res,item);
    }
};

class Solution2 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res(1);
        sort(S.begin(), S.end());
        for (int i = 0; i < S.size(); ++i) {
            int size = res.size();
            for (int j = 0; j < size; ++j) {
                res.push_back(res[j]);
                res.back().push_back(S[i]);
            }
        }
        return res;
    }
};

class Solution3 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> out;
        sort(S.begin(), S.end());
        getSubsets(S, 0, out, res);
        return res;
    }
    void getSubsets(vector<int> &S, int pos, vector<int> &out, vector<vector<int> > &res) {
        res.push_back(out);
        for (int i = pos; i < S.size(); ++i) {
            out.push_back(S[i]);
            getSubsets(S, i + 1, out, res);
            out.pop_back();
        }
    }
};

class Solution4 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        int all_set = 1<<S.size()+1;
        for (int i = 0; i < all_set; i++)
        {
            vector<int> item;
            for (int j = 0; j < S.size(); j++)
            {
                if (i&(1<<j))
                {
                    item.push_back(S[j]);
                }
                
            }
            result.push_back(item);
        }
    }
};

int main()
{
    vector<int> nums{1,2,3};
    Solution2 s;
    vector<vector<int> > res = s.subsets(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    
}