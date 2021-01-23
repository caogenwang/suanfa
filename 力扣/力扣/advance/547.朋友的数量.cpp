#include <stdio.h>

#include <vector>

using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int> >& M) {
        vector<bool> visited(M.size(),false);
        int nums = 0;
        for (int i = 0; i < M.size(); i++)
        {
            if (visited[i])
                continue;

            DFS(i,M,visited);
            nums++;
        }
        return nums++;
    }

    void DFS(int x,vector<vector<int> >& M,vector<bool> &visited)
    {
        visited[x] = true;
        for (int i = 0; i < M.size(); i++)
        {
            if (!M[x][i] || visited[i])
            {
                continue;
            }
            DFS(i,M,visited);
        }
    }
};

int main()
{

}