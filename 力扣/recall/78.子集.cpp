
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > tmp;
        generate(0,tmp);
        return tmp;
    }

    void generate(int i,vector<vector<int> > &res)
    {

    }

};

int main()
{
    vector<int> nums{1,2,3};
    Solution s;
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