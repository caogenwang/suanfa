#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*二叉搜索树的特点*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (root == p || root == q)
            return root;
        
        if ((p->val < root->val && q->val > root->val) 
            || (q->val < root->val && p->val > root->val))//在左右子树两边
        {
            return root;
        }
        else if(p->val < root->val || q->val < root->val)//在左子树
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else//在右子树
        {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};

int main()
{

}



