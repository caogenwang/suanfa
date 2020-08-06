#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_set>
#include <list>
#include <fstream>
using namespace std;
// 给定一个三角形，找出从顶到底的最小路径和，每一步可以从上一行移动到下一行相邻的数字
//    [                   
//         [2],                 [2],              
//        [3,4],              [3, 4],            [2],
//       [6,5,7],      ==>   [7, 6, 10]     ==>  [9, 10]   ==>     [11]
//      [4,1,8,3]
//    ]
 
/**思路:
    * 自底向上 dp: 不需要额外的空间
    * dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + ***[i][j]
    * dp[i][j]: 表示到达 (i, j)最小路径的总和
*/
 
// 修改输入样例:
//    4
 
//    2
//    3 4
//    6 5 7
//    4 1 8 3

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
       int n = triangle.size();
        for(int i=n-2;i >=0;i++){
            for(int j=0;j<=i;j++)
            {
                triangle[i][j]+=min(triangle[i+1][j], triangle[i+1][j+1]);//只有相邻的两个
            }
        }
        return triangle[0][0];
    }
};

class Solution1 {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
     int sum;
     sum = getres(triangle,0,0);
     return sum;
    }
    int getres(vector<vector<int> > &triangle,int l,int k)
    {
        int sum = triangle[l][k];
        if(l < triangle.size() -1)
            sum = sum + min(getres(triangle,l+1,k),getres(triangle,l+1,k+1));
        return sum;
    }
};
int climbStairs(int n) {
        /*fn(n) = f(n-1) + f(n-2);*/
        if(n == 1)
            return 1;
        if(n==2)
            return 2;
       return climbStairs(n-1) + climbStairs(n-2);
    }

int climbStairs1(int n) {
    /*fn(n) = f(n-1) + f(n-2);*/
    if(n == 1)
        return 1;
    if(n==2)
        return 2;
    int a = 1;
    int b = 2;
    int c = 0;
    for(int i = 3;i<=n;i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
int main(int argc,char**argv)
{
    int n=1000;
    int step = climbStairs(n);
    cout<<step<<endl;
}
