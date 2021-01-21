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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)   
    {       
        if(!(pRoot1&&pRoot2))//如果其中有一个为空，则返回false     
            return false;       
        if(pRoot1->val==pRoot2->val)//找到共同的节点        
        {           
            if(subTree(pRoot1,pRoot2)==true)               
                return true;       
        }       
        return HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2); //分左右树去遍历  
    }   
    bool subTree(TreeNode* pRoot1,TreeNode* pRoot2)       
    {       
        if(pRoot2==NULL)           
            return true;       
        if(pRoot1==NULL)           
            return false;       
        if(pRoot1->val==pRoot2->val)           
            return subTree(pRoot1->left,pRoot2->left)&&subTree(pRoot1->right,pRoot2->right);       
        return false;   
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == NULL)
            return false;
        vector<int> path_A;
        vector<int> path_B;
        preorder(A,path_A);
        preorder(A,path_B);

        int lenA = path_A.size();
        int lenB = path_B.size();
        int diff = lenA - lenB;
        if(diff < 0)
        {
            return false;
        }
        for(int i=0;i<lenB;i++)
        {
            if(path_A[i+diff] != path_B[i])
            {
                return false;
            }
        }
        return true;
    }
    void preorder(TreeNode* root,vector<int> &path)
    {
        if(root == NULL)
            return;
        path.push_back(root->val);
        if(root->left)
            preorder(root->left,path);
        if(root->right)
            preorder(root->right,path);

    }
};

int main()
{

}