#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     int level;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
    遍历每层的节点时，把下一层的节点都存入到queue中，每当开始新一层节点的遍历之前，
    先把新一层最后一个节点值存到结果中.
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<int> view;
        root->level = 0;
        Q.push(root);
        int level = 0;
        while (!Q.empty())
        {
            TreeNode* node = Q.front();
            Q.pop();
            level = node->level;//获取当前节点的level
            if (node->left)
            {
                node->left->level = level + 1;//下一层level + 1
                Q.push(node->left);
            }
            if (node->right)
            {
                node->right->level = level + 1;
                Q.push(node->right);
            }
        }
        return view;
    }
};
/*
    遍历每层的节点时，把下一层的节点都存入到queue中，每当开始新一层节点的遍历之前，
    先把新一层最后一个节点值存到结果中
*/
class Solution2 {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (!root) 
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            res.push_back(q.back()->val);//先把新一层最后一个节点值存到结果中
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) 
                    q.push(node->left);
                if (node->right) 
                    q.push(node->right);
            }
        }
        return res;
    }
};

class Solution2 {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> view;
    	std::queue<std::pair<TreeNode *, int> > Q;
    	if (root){
	    	Q.push(std::make_pair(root, 0));
	    }
    	while(!Q.empty()){
	    	TreeNode *node = Q.front().first;
	    	int depth = Q.front().second;
	    	Q.pop();
	    	if (view.size() == depth){
	    		view.push_back(node->val);
	    	}
	    	else{
	    		view[depth] = node->val;
	    	}
	    	if (node->left){
	    		Q.push(std::make_pair(node->left, depth + 1));
	    	}
	    	if (node->right){
	    		Q.push(std::make_pair(node->right, depth + 1));
	    	}
	    }
    	return view;
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
	TreeNode c(3);
	TreeNode d(5);
	TreeNode e(4);

	a.left = &b;
	a.right = &c;

	b.right = &d;
	c.right = &e;
    BFS_print(&a);
    Solution s;
    vector<int> res = s.rightSideView(&a);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}