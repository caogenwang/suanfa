#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles){
        vector<int> res;
        for (int i = 0; i < puzzles.size(); i++)
        {
            string w1 = puzzles[i];
            int count = 0;
            for (int j = 0; j < words.size(); j++)
            {
                int pos = (int)words[j].find(w1[0]);
                if (pos != -1 && isAllExist(words[j],w1))
                {
                   count++;
                }
            }
            res.push_back(count);
        }
        return res;
    }
    bool isAllExist(string w1,string w2)
    {
        for (int i = 0; i < w1.length(); i++){
            int pos = (int)w2.find(w1[i]);
            if(pos == -1)
                return false;
        }
        return true;
    }
};

class Solution2 {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles){
         vector<int> res;
        for (int i = 0; i < puzzles.size(); i++)
        {
            string w1 = puzzles[i];
            
        }
    }
};
int main()
{
    vector<string> words{"aaaa","asas","able","ability","actt","actor","access"};
    vector<string> puzzles{"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    
    Solution so;
    vector<int> res = so.findNumOfValidWords(words,puzzles);

    for (int i = 0; i < res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
}