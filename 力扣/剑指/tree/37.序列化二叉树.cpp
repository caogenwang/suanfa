#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:
    void BST_insert(TreeNode *node, TreeNode *insert_node)
    {
        if (insert_node->val <= node->val)//左子树
        {
            if (node->left)
                BST_insert(node->left,insert_node);
            else
                node->left = insert_node;
        }
        else
        {
            if(node->right)
                BST_insert(node->right,insert_node);
            else
                node->right = insert_node;
        }
    }

    void change_int_to_string(int val, std::string &str_val)
    {
        string tmp;
        while (val>0)
        {
            tmp += val%10 + '0';
            val = val / 10;
        }
        for (int i = tmp.length() - 1; i >= 0; i--)
        {
            str_val += tmp[i];
        }
        str_val += '#';
    }

    void BST_preorder(TreeNode *node, std::string &data){
	    if (!node){
		    return;
	    }
        std::string str_val;
        change_int_to_string(node->val, str_val);
        data += str_val;
        BST_preorder(node->left,data);
        BST_preorder(node->right,data);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        BST_preorder(root,data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int size = data.size();
        if (size == 0){
	    	return NULL;
	    }

        int val = 0;
        vector<TreeNode*> vec_nodes;
        for (int i = 0; i < size; i++)
        {
            if (data[i] == '#')
            {
                vec_nodes.push_back(new TreeNode(val));
                val = 0;
            }
            else
            {
                val = val*10+data[i]-'0';
            }
        }
        for (int i = 0; i < vec_nodes.size(); i++)
        {
            BST_insert(vec_nodes[0],vec_nodes[i]);
        }
        return vec_nodes[0];
    }
};

int main()
{
    return 0;
}