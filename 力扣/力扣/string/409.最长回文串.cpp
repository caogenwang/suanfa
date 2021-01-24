#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int char_map[128] = {0};
        int max_len = 0;
        int flag = 0;
        for(int i=0;i<s.length();i++)
            char_map[s[i]]++;
        for(int i = 0;i < 128;i++)
        {
            if(char_map[i]%2 == 0)
                max_len += char_map[i];
            else
            {
                max_len += char_map[i] - 1;
                flag = 1;
            }
        }
        return max_len + flag;
    }
};

int main()
{
    string s = "abccccdd";
    Solution so;
    int res = so.longestPalindrome(s);
    cout<<res<<endl;
}