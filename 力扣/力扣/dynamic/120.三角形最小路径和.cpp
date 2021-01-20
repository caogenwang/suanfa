#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        int sum = 0;
        vector<vector<int> > dp;
        for (int i = 0; i < triangle.size(); i++)
        {
            vector<int> tmp(triangle[i].size(),0);
            dp.push_back(tmp);
        }
        
        for (int i = 0; i < triangle[triangle.size()-1].size(); i++)
        {
            dp[triangle.size()-1][i] = triangle[triangle.size()-1][i];
        }
        
        for (int i = triangle.size() - 2; i >= 0 ; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                dp[i][j] = min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];

            }
        }
        return dp[0][0];
    }
};

class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                } else if (j == triangle[i].size() - 1) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};

class Solution3 {
public:
    int minimumTotal(std::vector<std::vector<int> >& triangle){
    	if (triangle.size() == 0){
	    	return 0;
	    }
    	std::vector<std::vector<int> > dp;
    	for (int i = 0; i < triangle.size(); i++){
	    	dp.push_back(std::vector<int>());
	    	for (int j = 0; j < triangle.size(); j++){
	    		dp[i].push_back(0);
	    	}
	    }
        
	    for (int i = 0; i < dp.size(); i++){
    		dp[dp.size()-1][i] = triangle[dp.size()-1][i];
    	}

	    for (int i = dp.size() - 2; i >= 0; i--){
	    	for (int j = 0; j < dp[i].size(); j++)
	    		dp[i][j] = std::min(dp[i+1][j], dp[i+1][j+1])
							 + triangle[i][j];
    	}
	    return dp[0][0];
    }
};

int main()
{
    vector<vector<int> > triangle{
                                    {2},
                                    {3,4},
                                    {6,5,7},
                                    {4,1,8,3}
                                  };
    Solution3 s;
    int sum = s.minimumTotal(triangle);
    cout<<sum<<endl;
}