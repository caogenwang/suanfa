//从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
/*
[
  [3],
  [9,20],
  [15,7]
]
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (!root)
            return res;
        vector<int> tmp;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            int size = Q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode * node = Q.front();
                tmp.push_back(node->val);
                Q.pop();

                if (node->left)
                    Q.push(node->left);
                if (node->right)
                    Q.push(node->right);
            }
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
    }
};

int main()
{

}