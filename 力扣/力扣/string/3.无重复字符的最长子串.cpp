#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int right = 0;
        int left = 0;
        int max = 0;
        int tmp_len = 0;
        int record[26] = {0};
        if(s.length()<=0)
        {
            return 0;
        }
        while (right < s.length())
        {
            cout<<"1 "<<s[right]<<endl;
            if (record[s[right] - 'a'])
            {
                cout<<"  2 "<<s[right]<<endl;
                tmp_len = right - left;
                cout<<" tmp_len:"<<tmp_len<<endl;
                if (tmp_len > max)
                {
                    max = tmp_len;
                }
                left = record[s[right] - 'a'] ;
                cout<<" left:"<<left<<endl;
            }
            record[s[right] - 'a'] = right + 1;
            right ++;
        }
        return max;
    }
};
class Solution2 {
public:
    int lengthOfLongestSubstring(string &s) {
        int char_map[128]={0};
        int result = 0;
        int begin = 0;
        string word;
        for (int i = 0; i < s.length(); i++)
        {
            char_map[s[i]]++;
            if (char_map[s[i]] == 1)
            {
                word += s[i];
                if (result < word.length())
                {
                    result = word.length();
                }
            }
            else
            {
                while (char_map[begin] > 1 && begin < i)
                {
                    char_map[s[begin]]--;
                    begin++;
                }
                word = "";
                for (int j = begin; j < i; j++)
                {
                    word += s[j];
                }
            }
        }
        return result;
    }
};
int main()
{
    // string  s = "abcabcbb";
    string s = "pwwkew";
    Solution su;
    int res = su.lengthOfLongestSubstring(s);
    cout<<res<<endl; 
}