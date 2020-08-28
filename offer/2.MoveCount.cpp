#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <list>
#include <queue>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool *flag = new bool[rows*cols];
        for (int i = 0; i < rows*cols; i++)
            flag[i] = false;
        int count = moving(threshold,rows,cols,0,0,flag);
        return count;
    }
    int moving(int threshold,int rows,int cols,int i,int j,bool *flag)
    {
        int count = 0;
        if(i>=0 && i<rows && j >= 0 && j<cols && getsum(i)+getsum(j)<=threshold 
        && flag[i * cols + j] == false)
        {
            flag[i*cols+j] = true;
            count = 1 + moving(threshold, rows, cols, i + 1, j, flag) +
                moving(threshold, rows, cols, i - 1, j, flag)+
                moving(threshold, rows, cols, i , j - 1, flag)+
                moving(threshold, rows, cols, i, j + 1, flag); 
        }
    }
    int getsum(int num)//各个位相加
    {       
        int sum = 0;      
        while(num)           
        {          
            sum += num % 10;           
            num /= 10;                     
        }       
        return sum;   
    }
};

int main(int argc,char**argv)
{
    return 0;
}