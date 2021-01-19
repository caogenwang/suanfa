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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        
    }
private:
    vector<vector<int> > tmp;
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
    TreeNode a(5);
	TreeNode b(4);
	TreeNode c(8);
	TreeNode d(11);
	TreeNode e(13);
	TreeNode f(4);
    TreeNode g(7);
	TreeNode h(2);
	TreeNode i(1);
	a.left = &b;
	a.right = &c;
	b.left = &d;
    c.left = &e;
    c.right = &f;
    d.left = &g;
    d.right = &h;
    f.right = &i;
    BFS_print(&a);
    Solution s;
    vector<vector<int> > res = s.pathSum(&a,22);
    return 0;
}