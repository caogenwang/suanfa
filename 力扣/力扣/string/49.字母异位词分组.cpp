#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        map<string,vector<string> > strs_map;
        vector<vector<string>> res;
        for (int i = 0; i < size; i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            strs_map[tmp].push_back(strs[i]);
        }
        for (map<string,vector<string> >::iterator it = strs_map.begin(); it != strs_map.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};



int main()
{
    char str[6][5]=  {"eat", "tea", "tan", "ate", "nat", "bat"};
}