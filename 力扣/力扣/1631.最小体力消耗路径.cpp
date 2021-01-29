#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <algorithm>
#include <unistd.h>
#include <tuple>
using namespace std;
/*一条路径耗费的体力值是路径上相邻格子之间高度差绝对值的最大值决定的。*/
// https://leetcode-cn.com/problems/path-with-minimum-effort/
const static int dx[] = {-1,1,0,0};
const static int dy[] = {0,0,-1,1};

class Solution {
public:
    int minimumEffortPath(vector<vector<int> >& heights) {
        
        int left = 0;
        int right = INT_MAX;
        while (left < right){
            vector<vector<int> > visited(heights.size(),vector<int>(heights[0].size(),0));
            int mid = left + (right - left)/2;
            if(DFS(0,0,heights,visited,mid)){//深度搜索，判断当前中间值下，是否可能到达右下角
                right=mid;
            }
            else{
                left=mid+1;               
            }
        }
        return left;
    }

    bool DFS(int x,int y,vector<vector<int> > &heights,vector<vector<int> >&visited,int value)
    {
        if (x == heights.size()-1 && y == heights[0].size()-1)
        {
            return true;
        }
        
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx<0 || newx >= heights.size() || newy<0 || newy>=heights[newx].size() 
                ||  visited[newx][newy] == 1 || abs(heights[x][y]-heights[newx][newy]) > value)
            {
                continue;
            }
            if(DFS(newx,newy,heights,visited,value))
                return true;
        }
        return false;
    }
};


/*  
    很明显的可以用二分查找处理，二分找答案，那么意味着我BFS进行遍历时，
    两个相邻的数字之差不能超过当前的二分mid，于是很快找到答案，比较简单
*/
class Solution2 {
public:
    struct Node
    {
        int x,y;
    };
    int xx[4]={0,0,-1,1};
    int yy[4]={-1,1,0,0};
    bool vis[110][110];
    queue<Node>q;
    bool bfs(int D,vector<vector<int>>& heights)
    {
        int n=heights.size();
        int m=heights[0].size();
        memset(vis,0,sizeof(vis));
        while(!q.empty())q.pop();
        Node t;
        t.x=0,t.y=0;
        vis[0][0]=true;
        q.push(t);
        while(!q.empty())
        {
            t=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                Node w;
                w.x=t.x+xx[i];
                w.y=t.y+yy[i];
                if(w.x<0||w.x>=n)continue;
                if(w.y<0||w.y>=m)continue;
                if(vis[w.x][w.y])continue;
                if(abs(heights[w.x][w.y]-heights[t.x][t.y])>D)continue;
                if(w.x==n-1&&w.y==m-1)return true;
                vis[w.x][w.y]=true;
                q.push(w);
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        if(heights.size()==1&&heights[0].size()==1)return 0;
        int l=0,r=1e6,fin;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(bfs(mid,heights))
            {
                r=mid-1;
                fin=mid;
            }
            else l=mid+1;
        }
        return fin;
    }
};

class Solution3 {
public:
    const int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};//每次前进的步骤
    int minimumEffortPath(vector<vector<int> >& heights) {
    	//确定的初始的二分范围
        int left=0;
        int right=999999;
        while(left<right){//二分搜索
        	//标识访问过的路径
            vector<vector<bool> > sign(heights.size(),vector<bool>(heights[0].size(),false));
            //当前的体力中间值
            int mid=left+(right-left)/2;
            if(dfs(heights,sign,mid,0,0)){//深度搜索，判断当前中间值下，是否可能到达右下角
                right=mid;
            }
            else{
                left=mid+1;               
            }
        }
        //返回
        return left;
    }
	//深度搜索
    bool dfs(vector<vector<int> >& heights,vector<vector<bool> >& sign,int& mid,int x,int y){
        if(x==sign.size()-1&&y==sign[0].size()-1){//说明到达了右下角，直接返回true
            return true;
        }
        sign[x][y]=true;//标识当前访问过的路径
        //可能前进的方向
        for(int i=0;i<4;++i){
        	//当期可能踏出的下一步
            int cur_x=x+step[i][0];
            int cur_y=y+step[i][1];
            //前四个条件满足该位置有效，第五个条件保证当前点之前没有访问过，第六个条件保证两点之间满足体力值要求
            if(cur_x>=0&&cur_x<sign.size()&&cur_y>=0&&cur_y<sign[0].size()&&!sign[cur_x][cur_y]&&(abs(heights[x][y]-heights[cur_x][cur_y])<=mid)){
                if(dfs(heights,sign,mid,cur_x,cur_y)){//在新的位置进行深度搜索
                    return true;
                }
            }
        }
        return false;//跳出循环，说明不能到达右下角
    }
};

class Solution4 {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
    	//确定的初始的二分范围
        int left=0;
        int right=999999;
        const int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};//每次前进的步骤
        while(left<right){//二分搜索
            queue<pair<int,int>> q;//存储广度路径
            q.push({0,0});
        	//标识访问过的路径
            vector<vector<bool>> sign(heights.size(),vector<bool>(heights[0].size(),false));
            sign[0][0]=true;
            //当前的体力中间值
            int mid=left+(right-left)/2;
            while(!q.empty()){
                pair<int,int> cur_p=q.front();
                q.pop();
                for(int i=0;i<4;++i){
                    int cur_x=cur_p.first+step[i][0];
                    int cur_y=cur_p.second+step[i][1];
                    if(cur_x>=0&&cur_x<sign.size()&&cur_y>=0&&cur_y<sign[0].size()&&!sign[cur_x][cur_y]&&abs(heights[cur_p.first][cur_p.second]-heights[cur_x][cur_y])<=mid){
                        q.push({cur_x,cur_y});//存储广度路径
                        sign[cur_x][cur_y]=true;//标识
                    }
                }
            }
            //更新范围
            if(sign.back().back()){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        //返回
        return left;
    }
};

/*并查集*/
// 并查集模板
class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    // 当前连通分量数目
    int setCount;
    
public:
    UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int findset(int x) {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }
    
    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return false;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }
    
    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

class Solution5 {
public:
    int minimumEffortPath(vector<vector<int> >& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int id = i * n + j;
                if (i > 0) {
                    edges.emplace_back(id - n, id, abs(heights[i][j] - heights[i - 1][j]));
                }
                if (j > 0) {
                    edges.emplace_back(id - 1, id, abs(heights[i][j] - heights[i][j - 1]));
                }
            }
        }
        sort(edges.begin(), edges.end(), [](const auto& e1, const auto& e2) {
            auto&& [x1, y1, v1] = e1;
            auto&& [x2, y2, v2] = e2;
            return v1 < v2;
        });

        UnionFind uf(m * n);
        int ans = 0;
        for (const auto [x, y, v]: edges) {
            uf.unite(x, y);
            if (uf.connected(0, m * n - 1)) {
                ans = v;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int> >heights{
                                {1,2,2},
                                {3,8,2},
                                {5,3,5}};
    Solution5 so;
    int res = so.minimumEffortPath(heights);
    cout<<res<<endl;
}