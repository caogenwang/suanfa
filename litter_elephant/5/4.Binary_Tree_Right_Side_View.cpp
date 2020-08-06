#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
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
			std::cout<<"depth:"<<depth<<std::endl;
			std::cout<<"size:"<<view.size()<<std::endl;
	    	Q.pop();
	    	if (view.size() == depth){//相等的时候是要换层了
	    		view.push_back(node->val);
	    	}
	    	else{//不相等的时候更新
	    		view[depth] = node->val;
	    	}
			for (int i = 0; i < view.size(); i++)
			{
				std::cout<<view[i]<<" ";
			}
			std::cout<<std::endl;
			
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

int main(){
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
	Solution solve;
	std::vector<int> result = solve.rightSideView(&a);
	for (int i = 0; i < result.size(); i++){
		printf("[%d]\n", result[i]);	
	}
	return 0;
}