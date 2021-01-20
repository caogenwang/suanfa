#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/*medium*/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*前序遍历*/
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        helper(root);
        for (int i = 1; i < tmp.size(); i++)
        {
            tmp[i-1]->left = NULL;
	    	tmp[i-1]->right = tmp[i];
        }
    }
    void helper(TreeNode* root)
    {
        if(!root)
            return;
        tmp.push_back(root);
        helper(root->left);
        helper(root->right);
    }
private:
    vector<TreeNode*> tmp;
};
/*
    利用 DFS 的思路找到最左子节点，然后回到其父节点，把其父节点和右子节点断开，
    将原左子结点连上父节点的右子节点上，然后再把原右子节点连到新右子节点的右子节点上，
    然后再回到上一父节点做相同操作
*/
class Solution2 {
public:
    void flatten(TreeNode *root) {
        if (!root) 
            return;
        if (root->left) 
            flatten(root->left);
        if (root->right) 
            flatten(root->right);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right) 
            root = root->right;
        root->right = tmp;
    }
};
/*
     1
    / \
   2   5
  / \   \
 3   4   6

     1
    / \
   2   5
    \   \
     3   6
      \    
       4

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

*/

/*
    从根节点开始出发，先检测其左子结点是否存在，如存在则将根节点和其右子节点断开，
    将左子结点及其后面所有结构一起连到原右子节点的位置，把原右子节点连到元左子结点最后面的右子节点之后
*/
class Solution3 {
public:
    void flatten(TreeNode *root) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) 
            {
                TreeNode *p = cur->left;
                while (p->right) 
                    p = p->right;
                p->right = cur->right;//把原右子节点连到元左子结点最后面的右子节点之后
                cur->right = cur->left;//左子结点及其后面所有结构一起连到原右子节点的位置
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};
/*
     1
    / \
   2   5
  / \   \
 3   4   6

   1
    \
     2
    / \
   3   4
        \
         5
          \
           6
           
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

class Solution4 {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *t = s.top(); 
            s.pop();
            if (t->left) 
            {
                TreeNode *r = t->left;
                while (r->right) 
                    r = r->right;
                r->right = t->right;
                t->right = t->left;
                t->left = NULL;
            }
            if (t->right) 
                s.push(t->right);
        }
    }
};

class Solution5 {
public:
    void flatten(TreeNode *root) {
        TreeNode *last = NULL;
        preorder(root, last);
    }
private:
	void preorder(TreeNode *node, TreeNode *&last){
		if (!node){
			return;
		}
		if (!node->left && !node->right){
			last = node;
			return;
		}
		TreeNode *left = node->left;
		TreeNode *right = node->right;
		TreeNode *left_last = NULL;
		TreeNode *right_last = NULL;
		if (left){
			preorder(left, left_last);
			node->left = NULL;
			node->right = left;
			last = left_last;
		}
		if (right){
			preorder(right, right_last);
			if (left_last){
				left_last->right = right;
			}
			last = right_last;
		}
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
    Solution2 s;
    s.flatten(&a);
    TreeNode* x = &a;
    while(x)
    {
        cout<<x->val<<endl;
        x = x->right;
    }
}