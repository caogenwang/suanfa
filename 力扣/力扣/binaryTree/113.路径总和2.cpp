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
		vector<vector<int> > res;
        vector<int> tmp;
		queue<TreeNode*> Q;
		int value = 0;
		Q.push(root);
		while (!Q.empty())
		{
			TreeNode*node = Q.front();
			value += node->val;
			cout<<value<<endl;
			tmp.push_back(node->val);
			Q.pop();
			if (value == sum && node->left == nullptr && node->right == nullptr)
			{
				res.push_back(tmp);
				value = 0;
				tmp.clear();
			}
			if (value > sum)
			{
				value -= node->val;
				tmp.pop_back();
			}
			
			if (node->left)
				Q.push(node->left);
			
			if (node->right)
				Q.push(node->right);
		}
		return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> out;
        helper(root, sum, out, res);
        return res;
    }
    void helper(TreeNode* node, int sum, vector<int>& out, vector<vector<int>>& res) {
        if (!node) 
			return;
        out.push_back(node->val);
        if (sum == node->val && !node->left && !node->right) {
            res.push_back(out);
			// out.clear();
			// return;
        }
        helper(node->left, sum - node->val, out, res);//先深度遍历左子树
        helper(node->right, sum - node->val, out, res);//再深度遍历右子树
        out.pop_back();//左右子树返回，则弹出换一个点
    }
};

class Solution2 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<TreeNode*> st;
        TreeNode *cur = root, *pre = nullptr;
        int val = 0;
        while (cur || !st.empty()) {
            while (cur) {
                st.push_back(cur);
                val += cur->val;
                cur = cur->left;
            }
            cur = st.back(); 
            if (!cur->left && !cur->right && val == sum) {
                vector<int> v;
                for (auto &a : st) v.push_back(a->val);
                res.push_back(v);
            }
            if (cur->right && cur->right != pre) {
                cur = cur->right;
            } else {
                pre = cur;
                val -= cur->val;
                st.pop_back();
                cur = nullptr;
            }
        }
        return res;
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
    // BFS_print(&a);
    Solution2 s;
    vector<vector<int> > res = s.pathSum(&a,22);
	cout<<res.size()<<endl;
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	
    return 0;
}