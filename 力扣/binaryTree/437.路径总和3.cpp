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
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        vector<TreeNode*> out;
        helper(root, sum, 0, out, res);
        return res;
    }
    void helper(TreeNode* node, int sum, int curSum, vector<TreeNode*>& out, int& res) {
        if (!node) 
            return;
        curSum += node->val;
        out.push_back(node);
        if (curSum == sum) 
            ++res;
        int t = curSum;
        for (int i = 0; i < out.size() - 1; ++i) {
            t -= out[i]->val;
            if (t == sum) 
                ++res;
        }
        helper(node->left, sum, curSum, out, res);
        helper(node->right, sum, curSum, out, res);
        out.pop_back();
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
    TreeNode a(10);
	TreeNode b(5);
	TreeNode c(-3);
	TreeNode d(3);
	TreeNode e(2);
	TreeNode f(11);
    TreeNode g(3);
	TreeNode h(-2);
	TreeNode i(1);
	a.left = &b;
	a.right = &c;
	b.left = &d;
    b.right = &e;
    c.right = &f;

    d.left = &g;
    d.right = &h;
    e.right = &i;
    BFS_print(&a);
    Solution s;
    int res = s.pathSum(&a,8);
	cout<<res<<endl;
	
	
    return 0;
}