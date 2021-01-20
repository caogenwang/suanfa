#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        if (grid.size() == 0){
	    	return 0;
	    }
        int sum = 0;
        vector<vector<int> > dp;
        for (int i = 0; i < grid.size(); i++)
        {
            vector<int> tmp(grid[i].size(),0);
            dp.push_back(tmp);
        }
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); i++)
        {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for (int i = 1; i < grid.size(); i++)
        {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[i].size(); j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;;
        }
        cout<<"----------------"<<endl;
        for (int i = 1; i < grid.size(); i++)
        {
            for (int j = 1; j < grid[i].size(); j++)
            {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[0].size(); j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;;
        }
        cout<<"----------------"<<endl;
        return dp[dp.size()-1][dp[0].size()-1];
    }
};

class Solution2 {
public:
    int minPathSum(std::vector<std::vector<int> >& grid) {
    	if (grid.size() == 0){
	    	return 0;
	    }
	    int row = grid.size();
    	int column = grid[0].size();
    	std::vector<std::vector<int> > 
						dp(row, std::vector<int>(column, 0));
    	
	    dp[0][0] = grid[0][0];
	    for (int i = 1; i < column; i++){
    		dp[0][i] = dp[0][i-1] + grid[0][i];
    	}
	    for (int i = 1; i < row; i++){
	    	dp[i][0] = dp[i-1][0] + grid[i][0];
    		for (int j = 1; j < column; j++){
		    	dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
		    }
    	}
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[i].size(); j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;;
        }

	    return dp[row-1][column-1];
    }
};

int main()
{
    vector<vector<int> > grid{{1,3,1},{1,5,1},{4,2,1}};
    Solution s;
    int sum = s.minPathSum(grid);
    cout<<sum<<endl;
}