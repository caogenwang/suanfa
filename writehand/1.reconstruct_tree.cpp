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
    if(preOrder.size() == 0)
        return nullptr;
    
}
int main(int argc,char **argv)
{
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> in =  {4,7,2,1,5,3,8,6};

    TreeNode_t *root = Reconstruct(pre,in);
}