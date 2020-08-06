#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S,int target) {
        vector<int> item;
        vector<vector<int> > result;
        set<vector<int>> set_res;
        sort(S.begin(),S.end());

        generate(0,S,item,result,set_res,0,target);
        return result;
    }
    void generate(int i,vector<int> &S,vector<int> &item,vector<vector<int>> result,set<vector<int>> &set_res,int sum,int target)
    {
        if(i >= S.size() || sum >target){
            return;
        }
        sum+=S[i];
        item.push_back(S[i]);
        if (sum == target && set_res.find(item) == set_res.end())
        {
            result.push_back(item);
            set_res.insert(item);
        }
        generate(i + 1,S,item,result,set_res,sum,target);
        
        sum-=S[i];
        item.pop_back();
        generate(i + 1,S,item,result,set_res,sum,target);
    }
};

int main(int argc,char**argv)
{
    vector<int> v={1,2,3,4};
    Solution s;
    vector<vector<int>> result = s.subsets(v,5);
    cout<<result.size()<<endl;
    for (int i = 0; i < result.size(); i++)
    {
        vector<int> temp = result[i];
        for (size_t j = 0; j < temp.size(); j++)
        {
            cout<<temp[j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}