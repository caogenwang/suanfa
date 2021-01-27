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
    void flatten(TreeNode* root) {

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
    TreeNode a(1);
	TreeNode b(2);
	TreeNode c(5);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(6);
    
	a.left = &b;
	a.right = &c;
	b.left = &d;
    b.right = &e;
    c.right = &f;

    
    BFS_print(&a);
    Solution s;
    s.flatten(&a);	
    return 0;
}
