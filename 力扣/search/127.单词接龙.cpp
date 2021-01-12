#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*
    给定两个单词（beginWord 和 endWord）和一个字典，
    找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,vector<string> > graph;
        construct_graph(beginWord,wordList,graph);
        return BFS_graph(beginWord,endWord,graph);
    }

    int BFS_graph(string beginWord,string endWord,map<string,vector<string> > &graph)
    {
        queue<pair<string,int> > Q;
        set<string> visit;
        Q.push(make_pair(beginWord,1));
        visit.insert(beginWord);
        while (!Q.empty())
        {
            string node = Q.front().first;
            int step = Q.front().second;
            Q.pop();
            if (node == endWord)
            {
                return step;
            }
            const vector<string> &neighbors = graph[node];
            for (int i = 0; i < neighbors.size(); i++)
            {
                if(visit.find(neighbors[i]) == visit.end())
                {
                    Q.push(make_pair(neighbors[i],step+1));
                    visit.insert(neighbors[i]);
                }
            }
        }
        return 0;
    }

    void construct_graph(string beginWord,vector<string>& wordList,
                         map<string,vector<string> > &graph)
    {
        wordList.push_back(beginWord);
        for (int i = 0; i < wordList.size(); i++)
        {
            graph[wordList[i]] = vector<string>();
        }

        for (int i = 0; i < wordList.size(); i++)
        {
            for (int j = i+1; j < wordList.size(); j++)
            {
                if(connected(wordList[i],wordList[j]))
                {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }

    bool connected(string w1, string w2)
    {
        int cnt = 0;
        for (int i = 0; i < w1.length(); i++)
        {
            if (w1[i] != w2[i])
            {
                cnt++;
            }
        }
        return cnt==1;
    }
};

int main()
{
    string beginword = "hit";
    string endword = "cog";
    vector<string> wordlist;
    wordlist.push_back("hot");
    wordlist.push_back("dot");
    wordlist.push_back("dog");
    wordlist.push_back("lot");
    wordlist.push_back("log");
    wordlist.push_back("cog");

    Solution s;
    int result = s.ladderLength(beginword,endword,wordlist);
    cout<<result<<endl;
}