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
    vector<int> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        vector<int> res;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            TreeNode *node = Q.front();
            res.push_back(node->val);
            Q.pop();
            if (node->left)
                Q.push(node->left);
            if (node->right)
                Q.push(node->right);
        }
        return res;
    }
};

int main()
{

}