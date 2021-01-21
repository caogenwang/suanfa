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
    int kthLargest(TreeNode* root, int k) {
        if (!root)
            return 0;
        vector<int> vec;
        inorder(root,vec);
        reverse(vec.begin(),vec.end());
        if (k > vec.size())
            return 0;
        return vec[k-1]; 
    }

    void inorder(TreeNode* root,vector<int> &vec)
    {
        if (!root)
        {
            return;
        }
        if (root->left)
            inorder(root->left,vec);
        vec.push_back(root->val);
        if (root->right)
            inorder(root->right,vec);
    }
};

int main()
{

}