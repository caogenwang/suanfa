#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> strs;
        vector<string> res;
        for (int i = 0; i < s.size(); i++)
        {
            string substr = s.substr(i,10);
            strs[substr]++;
        }
        for (unordered_map<string,int>::iterator it = strs.begin();  it != strs.end(); it++)
        {
            if (it->second >1)
            {
                res.push_back(it->first);
            }
        }
        return res;
    }
};

int main()
{

}