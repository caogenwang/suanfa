#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/*Medium*/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void preorder(TreeNode* node,
			  TreeNode *search,
		   	  std::vector<TreeNode*> &path,
		   	  std::vector<TreeNode*> &result,
			  int &finish){
	if (!node || finish){
		return;
	}
	path.push_back(node);
	if (node == search){
		finish = 1;
		result = path;
	}
	preorder(node->left, search, path, result, finish);
	preorder(node->right, search, path, result, finish);
	path.pop_back();
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> path;
        std::vector<TreeNode*> node_p_path;
        std::vector<TreeNode*> node_q_path;
        int finish = 0;
        preorder(root, p, path, node_p_path, finish);
        path.clear();
        finish = 0;

        preorder(root, q, path, node_q_path, finish);        
        int path_len = 0;
        if (node_p_path.size() < node_q_path.size()){
        	path_len = node_p_path.size();
        }
        else{
        	path_len = node_q_path.size();
        }
        TreeNode *result = 0;
        for (int i = 0; i < path_len; i++){
        	if (node_p_path[i] == node_q_path[i]){
	        	result = node_p_path[i];
	        }
        }
        return result;
    }
};

class Solution2 {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) 
			return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) 
		{
            ans = root;
        } 
        return lson || rson || (root->val == p->val || root->val == q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};

class Solution3 {
public:
    unordered_map<int, TreeNode*> fa;
    unordered_map<int, bool> vis;
    void dfs(TreeNode* root){
        if (root->left != nullptr) {
            fa[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != nullptr) {
            fa[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val] = nullptr;
        dfs(root);
        while (p != nullptr) 
		{
            vis[p->val] = true;
            p = fa[p->val];
        }
        while (q != nullptr) {
            if (vis[q->val]) 
				return q;
            q = fa[q->val];
        }
        return nullptr;
    }
};

class Solution4 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || p == root || q == root) 
			return root;
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p , q);
		if (left && right) 
			return root;
		return left ? left : right;
    }
};

class Solution5 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || p == root || q == root) 
			return root;
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		if(left && left != p && left != q) 
			return left;
		TreeNode *right = lowestCommonAncestor(root->right, p , q);
		if(left && right) 
			return root;
		return left ? left : right;
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
/* root = [3,5,1,6,2,0,8,null,null,7,4]*/
int main()
{
    TreeNode a(3);
	TreeNode b(5);
	TreeNode c(1);
	TreeNode d(6);
	TreeNode e(2);
	TreeNode f(0);
	TreeNode x(8);
	TreeNode y(7);
	TreeNode z(4);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &x;
	e.left = &y;
	e.right = &z;
	
	Solution solve;
	TreeNode *result = solve.lowestCommonAncestor(&a, &b, &f);
	printf("lowestCommonAncestor = %d\n", result->val);
	result = solve.lowestCommonAncestor(&a, &d, &z);
	printf("lowestCommonAncestor = %d\n", result->val);
	result = solve.lowestCommonAncestor(&a, &b, &y);
	printf("lowestCommonAncestor = %d\n", result->val);
	
	return 0;
}