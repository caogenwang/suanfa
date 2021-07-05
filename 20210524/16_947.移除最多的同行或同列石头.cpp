#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> rowMap, colMap;
        unordered_set<int> rowVisited;
        int res = 0;
        for (auto stone : stones) {
            rowMap[stone[0]].push_back(stone[1]);
            colMap[stone[1]].push_back(stone[0]);
        }
        for(auto it = rowMap.begin();it != rowMap.end();it++){
            res += max(0, helper(rowMap, colMap, it->first, rowVisited) - 1);
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

class Solution2 {
public:
    int removeStones(vector<vector<int> >& stones) {
        int cnt = 0, n = stones.size();
        vector<int> root(n);
        for (int i = 0; i < n; ++i) 
            root[i] = i;//先初始化为自己的头结点

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {//共线的话则放在一起
                    root[getRoot(root, i)] = getRoot(root, j);//同一行或者同一列放在同一个根下
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (root[i] == i)//总共有多少个群组，一个群组只能剩下一个
                ++cnt;
        }
        return n - cnt;//可以最多移除的个数
    }
    int getRoot(vector<int>& root, int x) {
        return x == root[x] ? x : getRoot(root, root[x]);
    }
};


int main(){
    vector<vector<int> > stones{{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    Solution s;
    int res = s.removeStones(stones);
    cout<<res<<endl;
    return 0;
}
