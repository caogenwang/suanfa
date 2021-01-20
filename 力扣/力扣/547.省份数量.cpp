#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
    有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，
    那么城市 a 与城市 c 间接相连。
    省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
    给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 
    个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。
    返回矩阵中 省份 的数量。
求小岛
    和的数量是不一样的。这个是求朋友圈的数量
*/
class Solution1 {
public:
    int findCircleNum(vector<vector<int> >& isConnected) {
        vector<vector<int> > visited(isConnected.size(),vector<int>(isConnected[0].size(),0));
        for (int i = 0; i < isConnected.size(); i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                visited[i][j] = 0;
            }
        }

        int num = 0;
        for (int i = 0; i < isConnected.size(); i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if (isConnected[i][j] == 1 && visited[i][j] != 1)
                {
                    DFS(isConnected,i,j,visited);
                    num++;
                }
            }
        }
        return num;
    }

    void DFS(vector<vector<int> >& isConnected,int x,int y,vector<vector<int> >& visited)
    {
        const static int dx[]={-1,1,0,0};
        const static int dy[]={0,0,-1,1};
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (newx < 0 || newx >= visited.size() || newy < 0 || newy >=visited[newx].size())
            {
                continue;
            }

            if (isConnected[newx][newy] == 1 && visited[newx][newy] != 1)
            {
                DFS(isConnected,newx,newy,visited);
            }
        }
    }
};

class Solution2 {
public:
    int findCircleNum(vector<vector<int> >& isConnected) {//朋友圈最大是列数
        int num = 0;
        vector<bool> visited(isConnected.size(),false);
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (visited[i])
                continue;
            DFS(i,isConnected,visited);
            num ++;
        }
        return num;
    }
    void DFS(int x,vector<vector<int> >& isConnected,vector<bool>& visited)
    {
        visited[x] = true;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (!isConnected[x][i] || visited[i]) 
                continue;
            cout<<x<<" "<<i<<endl;
            DFS(i,isConnected, visited);//跳跃式遍历，节点依次是[0][3],[3][2],[2][1]
        }
    }
};

class Solution3 {
public:
    int findCircleNum(vector<vector<int> >& M) {
        int n = M.size(), res = 0;
        vector<bool> visited(n, false);
        queue<int> q;
        for (int i = 0; i < n; ++i) 
        {
            if (visited[i]) 
                continue;

            q.push(i);
            while (!q.empty()) 
            {
                int t = q.front(); 
                q.pop();
                visited[t] = true;

                for (int j = 0; j < n; ++j)//每一列遍历
                {
                    if (!M[t][j] || visited[j]) 
                        continue;
                    q.push(j);//遍历到出现1的点，放进队列中
                }
            }
            ++res;
        }
        return res;
    }
};
/*手写二叉树的层序遍历*/
struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode():data(0),left(nullptr),right(nullptr){}
    TreeNode(int _data):data(_data),left(nullptr),right(nullptr){}
};
void cengxubianli(TreeNode* root)
{
    if (root == nullptr)
        return;
    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty())
    {
        TreeNode* t = Q.front();
        Q.pop();
        cout<<t->data<<endl;
        if (t->left != nullptr)
        {
            Q.push(t->left);
        }
        if (t->right != nullptr)
        {   
            Q.push(t->right);
        }
    }
}

int main()
{

    vector<vector<int> > isConnected = {
        {1,0,0,1},
        {0,1,1,0},
        {0,1,1,1},
        {1,0,1,1}};
    Solution3 s3;
    int num = s3.findCircleNum(isConnected);
    cout<<num<<endl;
    return 0;
}

// [
//     [1,0,0,1],
//     [0,1,1,0],
//     [0,1,1,1],
//     [1,0,1,1]
// ]