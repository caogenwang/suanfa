#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <fstream>
#include <limits.h>
using namespace std;
//给出一个只包含0和1的二维矩阵，找出最大的全部元素都是1的长方形区域，返回该区域的面积。
class Solution {
public:
    int maximalRectangle(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> height(n + 1,0);
        for(int i = 0;i < m;++i)
        {
            stack<int> s;
            for (int j = 0; j < n + 1; j++)
            {
                if(j < n)
                {
                    height[j] = matrix[i][j] == 1 ? height[j] + 1 : 0;
                }
                while (!s.empty() && height[s.top()] >= height[j]) {
                    int cur = s.top(); s.pop();
                    res = max(res, height[cur] * (s.empty() ? j : (j - s.top() - 1)));
                }
                s.push(j);
            }
        }
        return res;
    }
};

class Solution2{
public:
    int maximalRectangle(vector<vector<int> > &matrix)
    {
        int res = 0;
        vector<int> height;
        for(int i=0;i < matrix.size();i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                height[j] = matrix[i][j] == 1 ?(height[j]+1):0;
            }
            res = max(res,largestRectangleArea(height));
        }
    }
    int largestRectangleArea(vector<int>& height)
    {
        int res = 0;
        stack<int> s;
        for (int i = 0; i < height.size(); i++)
        {
            if(s.empty() || height[s.top()] <= height[i])
                s.push(i);
            else
            {
                int tmp = s.top();
                s.pop();
                res = max(res,height[tmp]*(s.empty()?i:(i - s.top() - 1)));
                --i;
            }
        }
        return res;
    }
};

int main(int argc,char**argv)
{
    vector<vector<int> > matrix ={
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };
    vector<vector<int> > &mat = matrix;
    Solution s;
    s.maximalRectangle(mat);
    return 0;
}
