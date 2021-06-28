#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        vector<vector<int> > visited(grid.size(),vector<int>(grid[0].size(),0));
        int nums = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (visited[i][j] == 0)
                {
                    generate(i,j,grid,visited);
                    nums++;
                }
            }
        }
        return nums;
    }

    void generate(int i,int j,vector<vector<char> >& grid,vector<vector<int> > &visited){
        const static int dx[4] = {1,-1,0,0};
        const static int dy[4] = {0,0,-1,1};

        visited[i][j] = 1;
        for (int m = 0; m < 4; m++)
        {
            int new_x = i + dx[m];
            int new_y = j + dy[m];
            if (new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[new_x].size() && visited[new_x][new_y] != 1)
            {
                if(grid[new_x][new_y])
                    generate(new_x,new_y,grid,visited);
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
    int number = s.numIslands(grid);
    std::cout<<number<<std::endl;
}