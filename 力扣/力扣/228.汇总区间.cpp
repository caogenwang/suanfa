#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int> > summaryRanges(vector<int>& nums) {
        int len = nums.size();
        int pos = 0;
        vector<vector<int> > res;
        vector<int> tmp;
        if(nums.size() <= 0)
        {
            tmp.push_back(0);
            res.push_back(tmp);
            return res;
        }
        if (nums.size() == 1)
        {
            tmp.push_back(nums[0]);
            res.push_back(tmp);
            return res;
        }      
        for (int i = 1; i < len; i++)
        {
            if (nums[i] - nums[i-1] > 1)
            {
                if (pos == i)
                {
                    tmp.push_back(nums[pos]);
                }
                else
                {
                    tmp.push_back(nums[pos]);
                    tmp.push_back(nums[i]);
                }
                
                pos = i;
                res.push_back(tmp);
                tmp.clear();
            }
            else
            {
                if(i == len-1)
                {
                    tmp.push_back(nums[pos]);
                    tmp.push_back(nums[i]);
                    res.push_back(tmp);
                    tmp.clear();
                }
            }
        }
        if (pos == len - 1)
        {
            tmp.push_back(nums[pos]);
            res.push_back(tmp);
        }
        
        return res;
    }
};
class Solution2 {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0, n = nums.size();
        while (i < n) {
            int j = 1;//每次循环j都为重置为1
            while (i + j < n && (long)nums[i + j] - nums[i] == j)//一直顺序增加
                ++j;
            res.push_back(j <= 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
            i += j;
        }
        return res;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(0);
    // nums.push_back(2);
    // nums.push_back(3);
    // nums.push_back(4);
    // nums.push_back(6);
    // nums.push_back(8);
    // nums.push_back(9);

    Solution s;
    vector<vector<int> > vs = s.summaryRanges(nums);
    for (int i = 0; i < vs.size(); i++)
    {
        for (int j = 0; j < vs[i].size(); j++)
        {
            cout<<vs[i][j]<<" ";
        }
         cout<<endl;
    }
    return 0;
}