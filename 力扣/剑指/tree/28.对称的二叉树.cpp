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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return false;
        
        TreeNode* mirror = mirrorTree(root);
        queue<pair<TreeNode*,TreeNode*> > Q;
        Q.push(make_pair(root,mirror));
        while (!Q.empty())
        {
            TreeNode *node1 = Q.front().first;
            TreeNode *node2 = Q.front().second;
            Q.pop();
            if (node1->val != node2->val)
            {
                return false;
            }
            
            if (node1->left && node2->left)
                Q.push(make_pair(node1->left,node2->left));
            if (node1->right && node2->right)
                Q.push(make_pair(node1->right,node2->right));
        }
        return true;
    }
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root)
            return nullptr;
        TreeNode* node;
        node = root->left;
        root->left = root->right;
        root->right = node;
        if(root->left)
            mirrorTree(root->left);
        if(root->right)
            mirrorTree(root->right);
        return root;
    }
};

int main()
{

}


class Solution2 {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
         if(pRoot == nullptr)
             return true;
        return isSymmetrical(pRoot,pRoot);
    }
    bool isSymmetrical(TreeNode*left,TreeNode*right)
    {
        if(right==nullptr && left == nullptr)
            return true;
        if(right==nullptr || left == nullptr)
            return false;
        if(right->val != left->val)
            return false;
        return isSymmetrical(left->left,right->right) && isSymmetrical(left->right,right->left);           
    }
};