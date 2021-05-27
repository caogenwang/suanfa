/*
给定一个三角形 triangle ，找出自顶向下的最小路径和。
每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 
上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，
那么下一步可以移动到下一行的下标 i 或 i + 1 。
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        int sum = 0;
        vector<vector<int> > dp;
        for (int i = 0; i < triangle.size(); i++)
        {
            vector<int> tmp(triangle[i].size(),0);
            dp.push_back(tmp);
        }
        for (int i = 0; i < triangle[triangle.size()-1].size(); i++)
        {
            dp[triangle.size()-1][i] = triangle[triangle.size()-1][i];
        }

       for (int i = triangle.size() - 2; i >= 0 ; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                dp[i][j] = min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];

            }
        }
        return dp[0][0];
    }

};

int main(){
    vector<vector<int> >triangle{
                                    {2},
                                    {3,4},
                                    {6,5,7},
                                    {4,1,8,3}
                                };
    Solution s;
    int res = s.minimumTotal(triangle);
    cout<<res<<endl;
}