
#include <stdio.h>

#include <vector>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int> >& triangle){
    	if (triangle.size() == 0){
	    	return 0;
	    }
    	std::vector<std::vector<int> > dp;//代表每一个位置最小的和
    	for (int i = 0; i < triangle.size(); i++){
	    	dp.push_back(std::vector<int>());
	    	for (int j = 0; j < triangle.size(); j++){
	    		dp[i].push_back(0);
	    	}//二维数组清零
	    }
	    for (int i = 0; i < dp.size(); i++){
    		dp[dp.size()-1][i] = triangle[dp.size()-1][i];//最后一行赋值
    	}
	    for (int i = dp.size() - 2; i >= 0; i--){
	    	for (int j = 0; j < dp[i].size(); j++)//注意这一行的细节
	    		dp[i][j] = std::min(dp[i+1][j], dp[i+1][j+1])
							 + triangle[i][j];
    	}
	    return dp[0][0];
    }
};

int main(){
	std::vector<std::vector<int> > triangle;
	int test[][10] = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};//注意初始化
	for (int i = 0; i < 4; i++){
		triangle.push_back(std::vector<int>());
		for (int j = 0; j < i + 1; j++){
			triangle[i].push_back(test[i][j]);
		}
	}
	Solution solve;
	printf("%d\n", solve.minimumTotal(triangle));
	return 0;
}
