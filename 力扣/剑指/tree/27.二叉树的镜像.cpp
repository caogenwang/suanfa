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