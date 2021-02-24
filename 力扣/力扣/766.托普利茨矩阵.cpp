#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int> >& matrix) {
        int col = matrix[0].size();
        int row = matrix.size();
        int res = true;
        for (int i = 0; i < row; i++)
        {
            int base = matrix[i][0];
            int m = i;
            int n = 0;
            while (m < row && n < col)
            {
                if(base != matrix[m][n])
                    return false;
                m ++;
                n ++;
            }
        }

        for (int i = 1; i < col; i++)
        {
            int base = matrix[0][i];
            int m = 0;
            int n = i;
            while (m < row && n < col)
            {
                if(base != matrix[m][n])
                    return false;
                m ++;
                n ++;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() - 1; ++i) {
            for (int j = 0; j < matrix[i].size() - 1; ++j) {
                if (matrix[i][j] != matrix[i + 1][j + 1]) 
                    return false;
            }
        }
        return true;
    }
};


int main()
{
    // vector<vector<int>>matrix{{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    vector<vector<int>>matrix{{1,2},{2,2}};
    Solution so;
    bool res = so.isToeplitzMatrix(matrix);
    cout<<res<<endl;

}