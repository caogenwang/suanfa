#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_set>
#include <list>
#include <fstream>
#include <limits.h>
using namespace std;

class Solution{
public:
    void put_down_queue(int x,int y,vector<vector<int>> &mark)
    {
        static const int dx[] = {-1,1,0,0,-1,-1,1,1};
        static const int dy[] = {0,0,-1,1,-1,1,-1,1};
        mark[x][y]=1;
        for (int i=0;i<mark.size();i++)
        {
            for (int j = 0; j < mark[1].size(); j++)
            {
                int new_x = x + i*dx[j];
                int new_y = y + i*dy[j];
                if (new_x>=0 && new_x<mark.size() 
                    && new_y>=0 && new_y<mark.size())
                {
                    mark[new_x][new_y] = 1;
                }
            }
        }
    }

    void generate(int k,int n,vector<string> &loction,vector<vector<string>>&result,
                    vector<vector<int>> &mark)
    {
        if (k == n)//完成一轮
        {
            result.push_back(loction);            
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (mark[k][i] == 0)
            {
                vector<vector<int>> temp_mark = mark;
                loction[k][i]='Q';
                put_down_queue(k,i,mark);
                generate(k+1,n,loction,result,mark);
                mark = temp_mark;
                loction[k][i]='*';
            }
        }
    }
};
int main(int argc,char**argv)
{
    Solution s;
    int n = 8;
    vector<string> location(n,"         ");
    vector<vector<string>> result;
    vector<vector<int>> mark(n,vector<int>(n,0));

    s.generate(0,n,location,result,mark);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {            
            cout<<result[i][j]<<endl;
        }
        cout<<"========="<<endl;
    }
    
}