#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int swimInWater(vector<vector<int>>& grid) {
        int left = 0;
        int right = INT_MAX;
        while (left < right)
        {
            int mid = left + (right - left)/2;
            vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
            if (grid[0][0] <=mid && DFS(0,0,grid,visited,mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
   bool DFS(int x,int y,vector<vector<int>>& grid,vector<vector<int>>& visited,int value)
    {
        if(x == grid.size()-1 && y == grid[0].size()-1)
            return true;
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx < 0 || newx >= grid.size() 
                || newy<0 || newy>=grid[newx].size()
                ||  visited[newx][newy] == 1
                || grid[newx][newy] > value)
            {
                 continue;
            }
           if(DFS(newx,newy,grid,visited,value))
                return true;
        }
       return false;
    }
};

int main()
{

}