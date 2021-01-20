#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;
/*hard*/
class Solution {
public:
    vector<int> hitBricks(vector<vector<int> >& grid, vector<vector<int> >& hits) {

    }
};

class Solution2 {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size(), k = hits.size();
        vector<int> res(k);
        unordered_set<int> noDrop;
        for (int i = 0; i < k; ++i) 
            grid[hits[i][0]][hits[i][1]] -= 1;

        for (int i = 0; i < n; ++i) {
            if (grid[0][i] == 1) 
                check(grid, 0, i, noDrop);
        }
        for (int i = k - 1; i >= 0; --i) {
            int oldSize = noDrop.size(), x = hits[i][0], y = hits[i][1];
            if (++grid[x][y] != 1) continue;
            if ((x - 1 >= 0 && noDrop.count((x - 1) * n + y)) 
                || (x + 1 < m && noDrop.count((x + 1) * n + y))
                || (y - 1 >= 0 && noDrop.count(x * n + y - 1))
                || (y + 1 < n && noDrop.count(x * n + y + 1))
                || x == 0) {
                check(grid, x, y, noDrop);
                res[i] = noDrop.size() - oldSize - 1;
            }
        }
        return res;
    }
    void check(vector<vector<int> >& grid, int i, int j, unordered_set<int>& noDrop) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1 || noDrop.count(i * n + j)) return;
        noDrop.insert(i * n + j);
        check(grid, i - 1, j, noDrop);
        check(grid, i + 1, j, noDrop);
        check(grid, i, j - 1, noDrop);
        check(grid, i, j + 1, noDrop);
    }
};

int main()
{
    vector<vector<int> >grid{
        {1,0,0,0},
        {1,1,1,0}
    };
    vector<vector<int> >hits{{1,0}};
    Solution s;
    vector<int> res = s.hitBricks(grid,hits);
    for (auto i : res)
    {
        cout<<i<<endl;
    }
    
}