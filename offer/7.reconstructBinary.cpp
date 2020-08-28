#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct TreeNode_t
{
    int val;
    struct TreeNode_t *left;
    struct TreeNode_t *right;
    TreeNode_t(int val):val(val),left(nullptr),
    right(nullptr){}
};

TreeNode_t *Reconstruct(vector<int> preOrder,vector<int> inOrder)
{
    //寻找头结点
    if(preOrder.size() == 0)
        return nullptr;
    int index = 0;
    int gen = preOrder[0];
    TreeNode_t *root = new TreeNode_t(gen);
    for (int i = 0; i < preOrder.size(); i++)
    {
        if (gen == inOrder[i]){
            index = i;
            break;
        }
    }
    vector<int> left_inOrder;
    vector<int> left_preOrder;
    vector<int> right_inOrder;
    vector<int> right_preOrder;
    for (int i = 0; i < index; i++)
    {
        left_preOrder.push_back(preOrder[i+1]);
        left_inOrder.push_back(inOrder[i]);
    }

    for (int i = index + 1; i < preOrder.size(); i++)
    {
        right_preOrder.push_back(preOrder[i]);
        right_inOrder.push_back(inOrder[i]);
    }
    root->left = Reconstruct(left_preOrder,left_inOrder);
    root->right = Reconstruct(right_preOrder,right_inOrder);
    return root;
}
void preOrderPrintf(TreeNode_t *root)
{
    if (root == nullptr)
        return;
    printf("%d ",root->val);
    if (root->left != nullptr)
        preOrderPrintf(root->left);
    
    if (root->right != nullptr)
        preOrderPrintf(root->right);
}

void inOrderPrintf(TreeNode_t *root)
{
    if (root == nullptr)
            return;
    if (root->left != nullptr)
        inOrderPrintf(root->left);
    printf("%d ",root->val);
    if (root->right != nullptr)
        inOrderPrintf(root->right);
}
//重建二叉树
int main(int argc,char **argv)
{
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> in =  {4,7,2,1,5,3,8,6};

    TreeNode_t *root = Reconstruct(pre,in);
    preOrderPrintf(root);
    printf("\n");
    inOrderPrintf(root);
    printf("\n");
}