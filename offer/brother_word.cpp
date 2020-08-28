#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool isBrother(const string word1,const string word2)
{
    if (word1==word2 || word1.length() != word2.length())
        return false;
    string s1 = word1;
    string s2 = word2;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1 == s2)
        return true;
    return false;
}

vector<string> BrotherWords(const string word,vector<string> array)
{
    vector<string> temp;
    int size = array.size();
    for (int i = 0; i < size; i++)
    {
        const string &w = array[i];
        if (isBrother(w,word))
        {
            temp.push_back(array[i]);
        }
    }
    return temp;
}



int main()
{
    string word1 = "abcd";
    vector<string> words={"abcd","adcb","bacd","cdba","dbac",
    "abcf","cdea","efgh","abcde","aefgh"};
    vector<string> brothers =  BrotherWords(word1,words);
    for (int i = 0; i < brothers.size(); i++)
    {
        cout<<brothers[i].c_str()<<endl;
    }
    
    return 0;
}