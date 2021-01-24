
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> words;
        string word;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ' || i == s.size() - 1)
            {
                words.push_back(word);
                word = "";
            }
            else
            {
                word += s[i];
            }
        }
        for (auto &&w : words)
        {
            cout<<w<<endl;
        }
        
        if (pattern.size() != words.size())
            return false;
        map<int,string> map_s;

        for (int i = 0; i < pattern.size(); i++)
        {
            if (map_s[pattern[i]] != "")
            {
                if (words[i] != map_s[pattern[i]])
                    return false;
                
            }
            else
            {
                for (auto a : map_s) 
                {
                    if (a.second == words[i]) 
                        return false;
                }

                map_s[pattern[i]] = words[i];
            }
        }
        return true;        
    }
};

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) 
        {
            if (i >= n) 
                continue;
            if (m.count(pattern[i])) 
            {
                if (m[pattern[i]] != word) 
                    return false;
            } else 
            {
                for (auto a : m) 
                {
                    if (a.second == word) 
                        return false;
                }
                m[pattern[i]] = word;
            }
        }
        return i == n;
    }
};

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) 
        {
            if (i == n || m1[pattern[i]] != m2[word]) 
                return false;
                
            m1[pattern[i]] = m2[word] = i + 1;
        }
        return i == n;
    }
};

int main()
{
    string pattern = "abba"; 
    string  str = "dog cat cat dog";
    Solution so;
    so.wordPattern(pattern,str);

}