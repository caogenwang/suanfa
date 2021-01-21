#include <iostream>
#include <vector>

using namespace std;

/*Medium*/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() < 1)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);

        auto proot = find(inorder.begin(),inorder.end(),preorder[0]);

        vector<int> left_pre(preorder.begin()+1,preorder.begin()+1+(proot-inorder.begin())),
        left_in(inorder.begin(),proot),
        right_pre(preorder.begin()+(proot-inorder.begin())+1,preorder.end()),
        right_in(proot+1,inorder.end());
        
        root->left = buildTree(left_pre,left_in);
        root->right = buildTree(right_pre,right_in);
        return root;
    }
};

int main()
{
    
}