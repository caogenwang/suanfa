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
    vector<vector<int> > subsets(vector<int> &S) {
        int n = S.size();
        vector<vector<int> > res;
        vector<int> temp;
        res.push_back(temp);
        for (int i = 0; i < n; i++)
        {
            temp.clear();
        }
        
    }
};


int main(int argc,char**argv)
{

}