#include <vector>
#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

class SolutionDFS {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        if(grid.empty())
            return 0;

        int res = 0;
        
        // 定义标记数组
        vector<vector<bool>> vecMark(grid.size(),vector<bool>(grid[0].size(),false));

        // 定义搜索边界
        int mostDeep = grid.size();
        int mostLeft = grid[0].size();

        //开始搜索
        for(int i = 0;i < mostDeep;i++)
        {
            for(int j = 0;j < mostLeft;j++)
            {
                if(vecMark[i][j] == true)
                    continue;
                int temp = dfs(grid, i, j, vecMark);
                res = max(res, temp);
            }
        }

        return res;
    }
private:
    int dfs(vector<vector<int>>& grid, int x, int y,vector<vector<bool>>& mark)
    {
        if(x >=  grid.size() || y >= grid[0].size() || x < 0 || y < 0)
            return 0;
            
        if(mark[x][y] == true)
            return 0;
        if(grid[x][y] == 0)
            return 0;
        
        // 对于点[x,y]搜索上下左右4个点是否是岛屿
        // 即[x-1,y],[x+1,y],[x,y-1],[x,y+1]
        // 对于已经搜索过的点要进行标记
        
        mark[x][y] = true;

        return 1 + dfs(grid, x+1, y, mark) + dfs(grid, x-1, y, mark) + dfs(grid, x, y+1, mark) + dfs(grid, x, y-1, mark);
    }
};
//广度优先搜索实现的核心是借助栈来进行层层遍历。
class SolutionBFS{
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        if(grid.empty())
            return 0;

        int res = 0;

        // 定义标记数组
        vector<vector<bool>> vecMark(grid.size(),vector<bool>(grid[0].size(),false));

        // 定义搜索边界
        int mostDeep = grid.size();
        int mostLeft = grid[0].size();

        //开始搜索
        for(int i = 0;i < mostDeep;i++)
        {
            for(int j = 0;j < mostLeft;j++)
            {
                if(vecMark[i][j] == true)
                    continue;

                if(grid[i][j] == 0)
                    continue;

                int itempArea = 0;
                //定义临时栈
                stack<pair<int,int>> stackTemp;
                stackTemp.push(make_pair(i,j));
                vecMark[i][j] = true;
                
                while(!stackTemp.empty())
                {  
                    itempArea++;
                    
                    pair<int,int> curPoint = stackTemp.top();
                    stackTemp.pop();
                    
                    int x = curPoint.first;
                    int y = curPoint.second;

                    if(x-1 >= 0 && grid[x-1][y] == 1 && vecMark[x-1][y] == false)
                    {
                        stackTemp.push(make_pair(x-1, y));
                        vecMark[x-1][y] = true;
                    }    
                    
                    if(x+1 < mostDeep && grid[x+1][y] == 1 && vecMark[x+1][y] == false)
                    {
                        stackTemp.push(make_pair(x+1, y)); 
                        vecMark[x+1][y] = true;                    
                    }
                        
                    if(y-1 >= 0 && grid[x][y-1] == 1 && vecMark[x][y-1] == false) 
                    {
                        stackTemp.push(make_pair(x, y-1));
                        vecMark[x][y-1] = true;
                    }
                    
                    if(y+1 < mostLeft && grid[x][y+1] == 1 && vecMark[x][y+1] == false)
                    {    
                        stackTemp.push(make_pair(x, y+1));   
                        vecMark[x][y+1] = true;
                    }
                }
                res = max(res, itempArea);
            }
        }        

        return res;
    }
};


void DFS_(int x,int y,vector<vector<int>> &grid,vector<vector<int>> &islands,int &area)
{
    const static int dx[4] = {-1,1,0,0};
    const static int dy[4] = {0,0,-1,1};
    grid[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x<0 || new_x>=grid.size() || new_y<0 || new_y>=grid[0].size())
        {
            continue;
        }
        if (grid[new_x][new_y]==0 && islands[new_x][new_y] == 1)
        {
            area ++;
            DFS_(new_x,new_y,grid,islands,area);
           
        }
    }
}

void BFS_(int x,int y,vector<vector<int>> &grid,vector<vector<int>> &islands,int &area)
{
     const static int dx[4] = {-1,1,0,0};
    const static int dy[4] = {0,0,-1,1};
    grid[x][y] = 1;
    queue<pair<int,int>> Q;
    Q.push(make_pair(x,y));
    while (!Q.empty())
    {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();   
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x<0 || new_x>=grid.size() || new_y<0 || new_y>=grid[0].size())
            {
                continue;
            }
            if (grid[new_x][new_y]==0 && islands[new_x][new_y] == 1)
            {
                Q.push(make_pair(new_x,new_x));
                grid[new_x][new_y] = 1;
                area ++;
            }
        }
    }
    
    
}

int maxAreaBfs(vector<vector<int>> &islands)
{
    int row = islands.size();
    int col = islands[0].size();
    int area = 0;
    int max = 0;
    int count = 0;
    vector<vector<int>> grid(row,vector<int>(col,0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {   
            if (grid[i][j] == 0 && islands[i][j]==1)
            {
                count ++;
                area = 0;
                BFS_(i,j,grid,islands,area);
                max = ::max(max,area);
            }
        }
    }
    cout<<"执行次数："<<count++<<endl;
    return max;
}



int maxAreaDfs(vector<vector<int>> &islands)
{
    int row = islands.size();
    int col = islands[0].size();
    int area = 0;
    int max = 0;
    int count = 0;
    vector<vector<int>> grid(row,vector<int>(col,0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {   
            if (grid[i][j] == 0 && islands[i][j]==1)
            {
                count ++;
                area = 0;
                DFS_(i,j,grid,islands,area);
                max = ::max(max,area);
            }
        }
    }
    cout<<"执行次数："<<count++<<endl;
    return max;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> islands = {
                                        {0,0,1,0,0,0,0,1,0,0,0,0,0},
                                        {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                        {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                        {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                        {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                        {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                        {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                        {0,0,0,0,0,0,0,1,1,0,0,0,0}
                                    };
    int max = maxAreaDfs(islands);
    cout<<"max: "<<max<<endl;
    return 0;
}
