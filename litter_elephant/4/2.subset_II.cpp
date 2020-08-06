#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
       vector<int> item;
       vector<vector<int>> result;
        generate(0,S,item,result);
        return result;
    }
    void generate(int i,vector<int> &S,vector<int> &item,vector<vector<int>> &result)
    {
        if(i >= S.size()){
            return;
        }
        item.push_back(S[i]);
        result.push_back(item);
        generate(i + 1,S,item,result);
        
        item.pop_back();
        generate(i + 1,S,item,result);
    }


};

class Solution2 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> result;
        int all_set = 1<<S.size();
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
        return result;
    }
};


int main(int argc,char**argv)
{
    vector<int> v={1,2,3,4};
    Solution2 s;
    vector<vector<int>> result = s.subsets(v);

    for (size_t i = 0; i < result.size(); i++)
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