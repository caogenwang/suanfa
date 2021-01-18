#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {//超时
public:
    map<vector<int>,vector<vector<int> > > graph;
    set<vector<int> > visited;
    int removeStones(vector<vector<int> >& stones) {
        int nums = 0;
        makegraph(stones);
        for (int i = 0; i < stones.size(); i++)
        {
            if (visited.find(stones[i]) == visited.end())
            {
                DFS(stones[i],graph,visited);
                nums ++;
            }
        }
        return stones.size() - nums;
    }
    void makegraph(vector<vector<int> > &stones)
    {
        for (int i = 0; i < stones.size(); i++)
        {

            graph[stones[i]] = vector<vector<int> >();
        }
        for (map<vector<int>,vector<vector<int> > >::iterator it = graph.begin(); \
                it != graph.end(); it++)
        {
            for (int i = 0; i < stones.size(); i++)
            {
                if (sameline(it->first,stones[i]))
                {
                    it->second.push_back(stones[i]);
                }
            }
        }
    }

    void DFS(vector<int> stone, map<vector<int>,vector<vector<int> > > &graph,set<vector<int> > &visited)
    {
        if (visited.find(stone) != visited.end())
        {
            return;
        }
        visited.insert(stone);
        vector<vector<int> > neighbers = graph[stone];
        for (int i = 0; i < neighbers.size(); i++)
        {
            if (visited.find(neighbers[i]) == visited.end())
            {
                DFS(neighbers[i],graph,visited);
                visited.insert(neighbers[i]);
            }
        }
    }
    bool sameline(vector<int> t1,vector<int> t2)
    {
        if (t1[0] == t2[0])
        {
            return true;
        }
        else if(t1[1] == t2[1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Solution2 {
public:
    int removeStones(vector<vector<int> >& stones) {
        unordered_map<int, vector<int>> rowMap, colMap;
        unordered_set<int> rowVisited;
        int res = 0;
        for (auto stone : stones) {
            rowMap[stone[0]].push_back(stone[1]);//建立所有横坐标对应纵坐标的hash表
            colMap[stone[1]].push_back(stone[0]);//建立所有纵坐标对应横坐标的hash表
        }
        for (auto a : rowMap) {
            res += max(0, helper(rowMap, colMap, a.first, rowVisited) - 1);
        }
        return res;
    }
    int helper(unordered_map<int, vector<int> >& rowMap, unordered_map<int, vector<int> >& colMap, int row, unordered_set<int>& rowVisited) {
        if (rowVisited.count(row)) 
            return 0;
        rowVisited.insert(row);
        int res = rowMap[row].size();
        for (int c : rowMap[row]) {
            for (int r : colMap[c]) {
                res += helper(rowMap, colMap, r, rowVisited);
            }
        }
        return res;
    }
};

class Solution3 {
public:
    int removeStones(vector<vector<int> >& stones) {
        int cnt = 0, n = stones.size();
        vector<int> root(n);
        for (int i = 0; i < n; ++i) 
            root[i] = i;//先初始化为自己的头结点
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {//共线的话则放在一起
                    root[getRoot(root, i)] = getRoot(root, j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (root[i] == i) 
                ++cnt;
        }
        return n - cnt;
    }
    int getRoot(vector<int>& root, int x) {
        return x == root[x] ? x : getRoot(root, root[x]);
    }
};

int main()
{
    vector<vector<int> >stones{{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    vector<vector<int> >stones2{{0,0},{0,2},{1,1},{2,0},{2,2}};
    vector<vector<int> >stones3{{0,0}};
    Solution s;
    int num = s.removeStones(stones3);
    cout<<num<<endl;
}