#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*Medium*/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*寻找根节点，然后再递归*/
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

class Solution2 {
public:
    TreeNode* buildTree(vector<int> pre,vector<int> vin) {
        int len = vin.size();
        if(len == 0)
            return nullptr;
        TreeNode *root = new TreeNode(pre[0]);
        vector<int> left_pre,left_in,right_pre,right_in;
        int gen = 0;
        for(int i = 0;i < len;i ++)
        {
            if(vin[i] == pre[0])
            {
                gen = i;
                break;
            }
        }
        for(int i=0;i<gen;i++)
        {
            left_in.push_back(vin[i]);
            left_pre.push_back(pre[i+1]);
        }
        for(int i = gen + 1;i < len;i ++)
        {
            right_in.push_back(vin[i]);
            right_pre.push_back(pre[i+1]);
        }
        root->left = buildTree(left_pre,left_in);
        root->right = buildTree(right_pre,right_in);
        return root;
    }
};

class Solution3 {/*通过*/
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //递归分治
        return recursionBuild(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }

    //递归分治
    TreeNode* recursionBuild(vector<int>::iterator preBegin, vector<int>::iterator preEnd,vector<int>::iterator inBegin, vector<int>::iterator inEnd )
    {
        if(inEnd==inBegin) 
            return NULL;
        TreeNode* cur = new TreeNode(*preBegin);
        auto root = find(inBegin,inEnd,*preBegin);
        cur->left = recursionBuild(preBegin+1,preBegin+1+(root-inBegin),inBegin,root);
        cur->right = recursionBuild(preBegin+1+(root-inBegin),preEnd,root+1,inEnd);
        return cur;
    }
};

void BFS_print(TreeNode* root){
	std::queue<TreeNode *> Q;
	Q.push(root);
  	while(!Q.empty()){
  		TreeNode *node = Q.front();
   		Q.pop();
	   	printf("[%d]\n", node->val);
	   	if (node->left){
	   		Q.push(node->left);
	   	}
	   	if (node->right){
	   		Q.push(node->right);
	   	}
   	}
}
int main()
{
    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder{9,3,15,20,7};
    Solution s;
    TreeNode *root = s.buildTree(preorder,inorder);
    BFS_print(root);
}


class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)   
    {       
        if(!(pRoot1&&pRoot2))           
            return false;       
        if(pRoot1->val==pRoot2->val)           
        {           
            if(subTree(pRoot1,pRoot2)==true)               
                return true;       
        }       
        return HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);   
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
class Solution {
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