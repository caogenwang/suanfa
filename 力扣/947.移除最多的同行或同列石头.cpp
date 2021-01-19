#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
    那么，我们应该尽可能晚地移除那些与其他点同行同列的点。也就是说与A点同行或同列的点数量越多，
    那么A应该越晚移除，因为这样，可以通过A点尽可能多得删除一些点
*/
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

class Djset {
public:
    vector<int> parent;  // 记录节点的根
    vector<int> rank;  // 记录根节点的深度（用于优化）
    int count;
    Djset(int n): parent(vector<int>(n)), rank(vector<int>(n)), count(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;//parent自己初始化为自己为头结点
        }
    }

    int find(int x) {//并查集的查找
        // 压缩方式：直接指向根节点
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {//父节点是否相同
            if (rank[rootx] < rank[rooty]) {//节点短的作为父节点
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;//将y的最终父节点设置为x
            if (rank[rootx] == rank[rooty]) 
                rank[rootx] += 1;//rootx升高一级
            count--;
        }
    }

    int get_count() {
        return count;
    }
};
class Solution4 {
public:
    int removeStones(vector<vector<int> >& stones) {
        int n = stones.size();//多少块石头
        Djset ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    ds.merge(i, j);//同一行同一列就merage到同一父节点下
                }
            }
        }
        return n - ds.get_count();
    }
};

int main()
{
    vector<vector<int> >stones{{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    vector<vector<int> >stones2{{0,0},{0,2},{1,1},{2,0},{2,2}};
    vector<vector<int> >stones3{{0,0}};
    Solution4 s;
    int num = s.removeStones(stones);
    cout<<num<<endl;
}