
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<utility>
#include<set>
using namespace std;
bool connect(const string &word1,const string &word2)
{
    int cnt=0;
    for(int i=0;i<word1.length();i++)
    {
        if (word1[i] != word2[i])
        {
            cnt++;
        }
    }
    return cnt == 1;
}

void constuct_graph(string &beginword,vector<string> &wordlist,map<string,vector<string> > &graph)
{
    wordlist.push_back(beginword);
    for (int i = 0; i < wordlist.size(); i++)
    {
        graph[wordlist[i]] = vector<string>();
    }

    for(int i=0;i<wordlist.size();i++)
    {
        for(int j=i+1;j<wordlist.size();j++)
        {
            if(connect(wordlist[i],wordlist[j]))
            {
                graph[wordlist[i]].push_back(wordlist[j]);
                graph[wordlist[j]].push_back(wordlist[i]);
            }
        }
    }
}
int BFS_graph(const string &beginword,const string &endword,map<string,vector<string> > &graph)
{
    queue<pair<string,int> > Q;
    set<string> visited;
    Q.push(make_pair(beginword,1));
    visited.insert(beginword);
    while (!Q.empty())
    {
        string node=Q.front().first;
        cout<<node<<endl;
        int step = Q.front().second;
        Q.pop();
        if (node == endword)
        {
            return step;
        }
        vector<string> neighbour = graph[node];
        for (int i = 0; i < neighbour.size(); i++)
        {
            if(visited.find(neighbour[i]) == visited.end())
            {
                Q.push(make_pair(neighbour[i],step+1));
                visited.insert(neighbour[i]);
            }
        }
    }
    return 0;
}

int main()
{
    string beginword="hit";
    string endword="cog";
    vector<string> wordlist;
    wordlist.push_back("hot");
    wordlist.push_back("dot");
    wordlist.push_back("dog");
    wordlist.push_back("lot");
    wordlist.push_back("log");
    wordlist.push_back("cog");

    map<string,vector<string> > graph;
    constuct_graph(beginword,wordlist,graph);

    // for (map<string,vector<string> >::iterator it=graph.begin();it != graph.end();it++)
    // {
    //     cout<<"key: "<<it->first<<endl;
    //     vector<string> neighbour = it->second;
    //     cout<<"value: ";
    //     for (int i = 0; i < neighbour.size(); i++)
    //     {
    //         cout<<neighbour[i]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    printf("%d\n",BFS_graph(beginword,endword,graph));

}