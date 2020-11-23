#include<iostream>
#include<vector>
using namespace std;

void display(std::vector<std::vector<int> > &nums)
{
    for (int i=0;i<nums.size(); i++)
    {
        for (int j=0;j<nums[i].size(); j++)
        {
            printf("%d ",nums[i][j]);
        }
        printf("\n");
    }
}

int minimumTotal(std::vector<std::vector<int> > &triangle)
{
    std::vector<std::vector<int> > dp;
    for (int i=0; i<triangle.size();i++)
    {
        vector<int> tmp;
        for (int j = 0; j < triangle[i].size(); j++)
        {
            tmp.push_back(0);;
        }
        dp.push_back(tmp);
    }    

    for (int i=0;i<triangle[triangle.size()-1].size(); i++)
    {
        dp[triangle.size()-1][i] = triangle[triangle.size()-1][i];
    }
    for (int i=triangle.size()-2;i>=0; i--)
    {
        for(int j=triangle[i].size() - 1;j>=0;j--)
        {
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
        }
        display(dp);
        printf("---------------\n");
    }
    return dp[0][0];
}

int main()
{
    std::vector<std::vector<int> > triangle;
	int test[][10] = {{2}, 
                      {3, 4}, 
                      {6, 5, 7}, 
                      {4, 1, 8, 3}};//注意初始化
	for (int i = 0; i < 4; i++){
		triangle.push_back(std::vector<int>());
		for (int j = 0; j < i + 1; j++){
			triangle[i].push_back(test[i][j]);
		}
	}
	printf("%d\n", minimumTotal(triangle));
	return 0;
}
