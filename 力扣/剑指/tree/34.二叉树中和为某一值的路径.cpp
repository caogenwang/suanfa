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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> tmp;
        if(!root)
            return res;
        helper(root,sum,tmp,res);
        return res;
    }
    void helper(TreeNode* root, int sum,vector<int> &tmp,vector<vector<int> > &res)
    {
        if (!root)
            return;
        tmp.push_back(root->val);
        if (sum == root->val && !root->left && !root->right)
        {
            res.push_back(tmp);
        }
        if(root->left != NULL)
            helper(root->left,sum-root->val,tmp,res);
        if(root->right != NULL)
            helper(root->right,sum-root->val,tmp,res);
        tmp.pop_back();
    }
};

int main()
{

    return 0;
}