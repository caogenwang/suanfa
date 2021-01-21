#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
   bool isBalanced(TreeNode* pRoot) {
        if(pRoot == nullptr)
            return true;
        int nleft = maxDepth(pRoot->left);
        int nright = maxDepth(pRoot->right);
        int diff = nleft - nright;
        if(diff > 1 || diff < -1)
            return false;
        return isBalanced(pRoot->left) && isBalanced(pRoot->right);
    }
    

    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (root->left || root->right)
        {
            return max(maxDepth(root->left),maxDepth(root->right)) + 1;
        }
        return 1;
    }
};

int main()
{

}