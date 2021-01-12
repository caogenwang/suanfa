
#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int row = dungeon.size();
    	int column = dungeon[0].size();
    	std::vector<std::vector<int> > 
						dp(row+1, std::vector<int>(column+1, 0));
        dp[row-1][column-1] = std::max(1, 1-dungeon[row-1][column-1]);;
        for (int i = column-2; i>=0; i--){
	    	dp[row-1][i] = std::max(1,dp[row-1][i+1] - dungeon[row-1][i]);
	    }
	    for (int i = row-2; i>=0; i--){
	    	dp[i][column-1] = std::max(1,dp[i+1][column-1] - dungeon[i][column-1]);
	    }
        for (int i = row-2; i>=0; i--){
    		for (int j = column-2; j>=0; j--){
    			int dp_min = std::min(dp[i+1][j], dp[i][j+1]);
		    	dp[i][j] = std::max(1, dp_min - dungeon[i][j]);
		    }
    	}
        return dp[0][0];
    }
};

int main(){
	int test[][3] = {
                        {-2, -3, 3}, 
                        {-5, -10, 1}, 
                        {10, 30, -5}
                    };
	std::vector<std::vector<int> > dungeon;
	for (int i = 0; i < 3; i++){
		dungeon.push_back(std::vector<int>());
		for(int j = 0; j < 3; j++)
        {
			dungeon[i].push_back(test[i][j]);
		}
	}
	Solution solve;
	printf("%d\n", solve.calculateMinimumHP(dungeon));
	return 0;
}