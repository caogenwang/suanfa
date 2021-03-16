#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int> > transpose(vector<vector<int> >& matrix) {
        vector<vector<int> > res(matrix[0].size(),vector<int>(matrix.size(),0));
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                res[j][i] = matrix[i][j];
        return res;
    }
};

int main()
{
    vector<vector<int> > matrix{{1,2,3},{4,5,6},{7,8,9}};
    Solution so;
    vector<vector<int> > res = so.transpose(matrix);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}