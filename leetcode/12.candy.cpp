#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_set>
#include <list>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
         int len = ratings.size();
        vector<int> candys(len,1);
        for(int i=1;i<len;i++)
        {
            if(ratings[i]>ratings[i-1])
                candys[i] = candys[i-1] + 1;
        }
        for(int j=len-2;j>=0;j--)
        {
            if(ratings[j]>ratings[j+1] && candys[j] <= candys[j+1])
                candys[j] = candys[j+1] + 1;
        }
        int sum = 0;
        for(int num:candys)
            sum = sum+num;
        return sum;
    }
};


int main(int argc,char**argv)
{

}

