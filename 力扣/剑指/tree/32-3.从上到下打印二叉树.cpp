#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
之字型打印
*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
      vector<vector<int> > res;
        if (!root)
            return res;
        vector<int> tmp;
        queue<pair<TreeNode *,int> > Q;
        int level = 0;
        int size = 0;
        Q.push(make_pair(root,0));
        while (!Q.empty())
        {
          level = Q.front().second;
          TreeNode * node = Q.front().first;
          size = Q.size();
          for (int i = 0; i < size; i++)
          {
                TreeNode * node = Q.front().first;
                tmp.push_back(node->val);
                Q.pop();

                if (node->left)
                    Q.push(make_pair(node->left,level+1));
                if (node->right)
                    Q.push(make_pair(node->right,level+1));
            }
          if (level%2==1)
          {
            std::reverse(tmp.begin(),tmp.end());
          }
          res.push_back(tmp);
          tmp.clear();
        }
      return res;
    }
};

int main()
{
  return 0;
}