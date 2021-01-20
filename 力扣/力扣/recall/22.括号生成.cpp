#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*medium*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate("",n,n,result);
        return result;
    }
    void generate(string item,int left,int right,vector<string> &result)
    {
        if (left == 0 && right == 0)
        {
            result.push_back(item);
            return;
        }
        if (left > 0)
        {
            generate(item+'(',left-1,right,result);
        }
        if (left < right)
        {
            generate(item+')',left,right-1,result);
        }
    }
};

int main()
{
    int n = 3;
    Solution s;
    vector<string> res = s.generateParenthesis(n);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<endl;
    }
    
}