#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution1 
{
public:
    vector<int> findRedundantConnection(vector<vector<int> >& edges) 
    {
        unordered_map<int, unordered_set<int> > m;
        for (auto edge : edges) 
        {
            if (hasCycle(edge[0], edge[1], m, -1)) 
                return edge;
            m[edge[0]].insert(edge[1]);//保存每个点的邻接点
            m[edge[1]].insert(edge[0]);
        }
        return {};
    }
    bool hasCycle(int cur, int target, unordered_map<int, unordered_set<int> >& m, int pre)
    {
        if (m[cur].count(target))
            return true;
        for (int num : m[cur])//遍历所有保存的节点的邻接点
        {
            if (num == pre) 
                continue;
            if (hasCycle(num, target, m, cur))
                return true;
        }
        return false;
    }
};

class Solution2 
{
public:
    vector<int> findRedundantConnection(vector<vector<int> >& edges) 
    {
        unordered_map<int, unordered_set<int> > m;
        for (auto edge : edges)
        {
            queue<int> q{{edge[0]}};
            unordered_set<int> s{{edge[0]}};
            while (!q.empty()) 
            {
                auto t = q.front(); 
                q.pop();
                if (m[t].count(edge[1])) 
                    return edge;
                for (int num : m[t]) 
                {
                    if (s.count(num)) 
                        continue;
                    q.push(num);
                    s.insert(num);
                }
            }
            m[edge[0]].insert(edge[1]);
            m[edge[1]].insert(edge[0]);
        }
        return {};
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int> >& edges) {
        vector<int> root(2001, -1);
        for (auto edge : edges) {
            int x = find(root, edge[0]), y = find(root, edge[1]);
            if (x == y) 
                return edge;
            root[x] = y;
        }
        return {};
    }

    int find(vector<int>& root, int i) {
        while (root[i] != -1) {
            i = root[i];//寻找每个节点的头结点
        }
        return i;
    }

};

int main()
{
    vector<vector<int> > edges{{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    Solution2 s;
    vector<int> res = s.findRedundantConnection(edges);

    for (int i:res)
        cout<<i<<endl;
}