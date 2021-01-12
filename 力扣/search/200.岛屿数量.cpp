#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        if (grid.size() == 0){
	    	return 0;
	    }

        vector<vector<int> > visited;
        for (int i = 0; i < grid.size(); i++)
        {
            vector<int> tmp(grid[i].size(),0);
            visited.push_back(tmp);
        }
        int nums = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1' && visited[i][j] != 1)
                {
                    BFS(i,j,grid,visited);
                    nums++;
                }
            }
        }
        return nums;
    }
    void DFS(int x,int y,vector<vector<char> >& grid,vector<vector<int> >& visited)
    {
        const static int dx[] = {-1,1,0,0};
        const static int dy[] = {0,0,-1,1};
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx<0 || newx >= grid.size() || newy<0 || newy>=grid[newx].size())
            {
                continue;
            }
            if (grid[newx][newy] == '1' && visited[newx][newy] != 1)
            {
                DFS(newx,newy,grid,visited);
            }
        }
    }

    void BFS(int x,int y,vector<vector<char> >& grid,vector<vector<int> >& visited)
    {
        const static int dx[] = {-1,1,0,0};
        const static int dy[] = {0,0,-1,1};
        queue<pair<int,int> > Q;
        visited[x][y] = 1;
        Q.push(std::make_pair(x,y));
        while (!Q.empty())
        {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (newx<0 || newx >= grid.size() || newy<0 || newy>=grid[newx].size())
                {
                    continue;
                }
                if (grid[newx][newy] == '1' && visited[newx][newy] != 1)
                {
                    Q.push(make_pair(newx,newy));
                    visited[newx][newy] = 1;
                }
            }

        }
        
    }
};

int main(){
    vector<vector<char> > grid;
    char str[10][10] = {"11000",
                        "10110",
                        "01000",
                        "00111"};
    for (int i = 0; i < 4; i++)
    {
        grid.push_back(vector<char>());
        for (int j = 0; j < 5; j++)
        {
            grid[i].push_back(str[i][j]);
        }
    }
    
    Solution s;
    int nums = s.numIslands(grid);
    cout<<nums<<endl;
}