#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

//动态规划的两个经典例子（面试题）
class Solution {
public:
    int cutRope(int n) {//n 是绳子的长度,m是切的段数，n，m都大于1
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        //运行至此,说明绳子的长度是>3的,这之后0/1/2/3这种子问题最大就是其自身长度
        //而不再需要考虑剪一刀的问题,因为它们剪一刀没有不剪来的收益高
        //而在当下这么长的绳子上剪过才可能生成0/1/2/3这种长度的绳子,它们不需要再减
        //所以下面的表中可以看到它们作为子问题的值和上面实际返回的是不一样的 

        //在表中先打上子绳子的最大乘积 
        int* products = new int[n + 1];
        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;//到3为止都是不剪最好
        int max = 0;//用于记录最大乘积 
	    //对于4以上的情况,每次循环要求f(i)
        for (int m = 4; m < n; m++)
        {
            max = 0;
            for (int j = 1; j < m/2; j++)
            {
                //计算f(j)乘以f(i-j)
                int product = products[j] * products[m - j];
                //如果比当前找到的还大 
                if(max < product)
                    max = product;//就把最大值更新
            }
            //这里是循环无关的,书上在for里面,我把它提出来 
            products[m] = max;//最终,更新表中的f(i)=max(f(j)·f(i-j))
        }
        for (int i = 0; i < n; i++)
        {
            cout<<products[i]<<endl;
        }
        
        //循环结束后,所求的f(length)也就求出来了 
        max = products[n-1];//将其记录下来以在销毁后能返回 
        delete[] products;//销毁打表的辅助空间 
        return max; 
    }
};

class Solution1 {
public:
    int cutRope(int number) {
        if (number <= 1)
            return 0;
        if (number == 2)
            return 1;
        if (number == 3)
            return 2;
        vector<int> backup = {0,1,2,3};; //这里被减去的绳子段与前面返回结果的值有所不同
        for (int i = 4; i != number + 1; i++) {
            int j = i / 2;                  //一般趋于最中间的两个数乘积是最大的，因为正方形面积最大。
            backup.push_back(backup[j] * backup[i - j]);
            cout<<backup[j] * backup[i - j]<<endl;
        }
        return backup[number];
    }
};

int climbstairs(int n)
{
    if (n < 1)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    static std::unordered_map<int,int> stairs;
    std::unordered_map<int,int>::const_iterator the_stair = stairs.find(n);
    
    if(the_stair == stairs.end())
    {
        int result = climbstairs(n-1) + climbstairs(n-2);
        stairs[n] = result;
        return result;
    }
    else
    {
        return the_stair->second;
    }
}

int climb(int n)
{
    if( n < 1){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    if(n == 2){
        return 2;
    }
    int result = 0;
    int pre = 1;
    int after = 2;
    for (int i = 3; i < n + 1; i++)
    {
        int result = pre + after;
        pre = after;
        after = result;
    }
    return result;
}

int main(int argc,char**argv)
{
    Solution1 s;
    int max = s.cutRope(7);
    cout<<"max:"<<max<<endl;
    return 0;
}