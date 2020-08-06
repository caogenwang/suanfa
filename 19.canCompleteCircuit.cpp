#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_set>
#include <list>
#include <fstream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {//能够走完加油站
      int total = 0;
      int sum = 0;
      int start = 0;
      for(int i = 0;i < gas.size();i++)
      {
          
          total += gas[i] - cost[i];
          sum += gas[i] - cost[i];
          if(sum < 0)
          {
              start = i + 1;
              sum = 0;
          }
          printf("total:%d,sum%d\n",total,sum);
      }
      return (total < 0)? -1:start;
    }
};

int main(int argc,char**argv)
{
    int a[4] = {1,2,3,4};
    int b[4] = {2,2,2,2};
    vector<int> gas(a,a+4);
    vector<int> cost(b,b+4);
    Solution s;
    int res =  s.canCompleteCircuit(gas,cost);
    cout<<res<<endl;
}

class Solution2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int mx = -1;
        int start = 0;
        for(int i = gas.size()-1;i >= 0;i--)
        {
            total += gas[i] - cost[i];
            if(total > mx)
            {
                start = i;
                mx = total;
            }
        }
        return (total < 0) ? -1 : start;
    }
};

class Solution3 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int total = 0;
       int start = 0;
       int sum = 0;
       int n = gas.size();
       for (int i = 0; i < n; i++)
       {
           total += gas[i] - cost[i];
           sum += gas[i] - cost[i];
           if(sum < 0)
           {
               start = i + 1;
               sum = 0;
           }
       }
       return (total<0)?-1:start;
    }
};