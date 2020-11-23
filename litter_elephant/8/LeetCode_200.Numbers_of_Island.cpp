#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;


void DFS(int x,int y,std::vector<std::vector<char> > &grid,std::vector<std::vector<int> > &visitd)
{
    const static int dx[]={-1,1,0,0};
    const static int dy[]={0,0,-1,1};
    visitd[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (new_x < 0 || new_x >= visitd.size() || new_y < 0 || new_y >visitd[new_x].size())
        {
            continue;
        }
        if(grid[new_x][new_y] == '1' && visitd[new_x][new_y] == 0)
        {
            DFS(new_x,new_y,grid,visitd);
        }
    }
}

void BFS(int x,int y,std::vector<std::vector<char> > &grid,std::vector<std::vector<int> > &visitd)
{
    const static int dx[]={-1,1,0,0};
    const static int dy[]={0,0,-1,1};
    std::queue<std::pair<int,int> > Q;
    Q.push(std::make_pair(x,y));
    visitd[x][y] = 1;
    while (!Q.empty())
    {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x < 0 || new_x >= visitd.size() || new_y < 0 || new_y >visitd[new_x].size())
            {
                continue;
            }
            if(grid[new_x][new_y] == '1' && visitd[new_x][new_y] == 0)
            {
                Q.push(std::make_pair(new_x,new_y));
                visitd[new_x][new_y] = 1;
            }
        }
    }
}

int numIslands(std::vector<std::vector<char> > &grid)
{   
    int num_of_island = 0;
    std::vector<std::vector<int> > visited;
    for (int i = 0; i < grid.size(); i++)
    {
        visited.push_back(std::vector<int>());
        for (int j = 0; j < grid[i].size(); j++)
        {
            visited[i].push_back(0);
        }
    }

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if(grid[i][j] == '1' && visited[i][j] == 0)
            {
                BFS(i,j,grid,visited);
                num_of_island++;
            }
        }
    }
    return num_of_island;
}


int main()
{
    std::vector<std::vector<char> > grid;
    char str[10][10] = {"11100",
                        "11000",
                        "00100",
                        "00011"};
    for (int i = 0; i < 4; i++)
    {
        grid.push_back(std::vector<char>());
        for (int j = 0; j < 5; j++)
        {
            grid[i].push_back(str[i][j]);
        }
        
    }
    printf("%d\n",numIslands(grid));
}