#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int c1=0,c2=0,c3=0;
        for (int i = 1; i < A.size(); i++)
        {
            if(A[i] - A[i-1] > 0)
                c1 ++;
            else if(A[i] - A[i-1] < 0)
                c2 ++;
            else
                c3++;
        }
        if(((c1+c3) == A.size() - 1) || ((c2+c3) == A.size() - 1))
            return true;
        return false;
    }
};

int main()
{
   vector<int> A{6,5,4,4};
   Solution so;
   bool res = so.isMonotonic(A);
   cout<<res<<endl;
}