#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define TRIE_MAX_CHAR_NUM 26

struct TrieNode{
	TrieNode *child[TRIE_MAX_CHAR_NUM];
	bool is_end;
	TrieNode() : is_end(false){
		for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++){
			child[i] = 0;
		}
	}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
    }
    ~Trie() {
        for (int i = 0; i < _node_vec.size(); i++)
        {
            delete _node_vec[i];
        }
        
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode*ptr = &_root;
        for (int i = 0; i < word.size(); i++)
        {
            int pos = word[i] - 'a';
            if (ptr->child[pos] == nullptr)
            {
                ptr->child[pos] = new_node();
            }
            ptr = ptr->child[pos];
        }
        ptr->is_end = true;
        // preorder_trie(&_root,0);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode*ptr = &_root;
        for (int i = 0; i < word.size(); i++)
        {
            int pos = word[i] - 'a';
            if (ptr->child[pos] == nullptr)
            {
                return false;
            }
            ptr = ptr->child[pos];
        }
        return ptr->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode*ptr = &_root;
        for (int i = 0; i < prefix.size(); i++)
        {
            int pos = prefix[i] - 'a';
            if (ptr->child[pos] == nullptr)
            {
                return false;
            }
            ptr = ptr->child[pos];
        }
        return true;
    }

    void preorder_trie(TrieNode *node, int layer){
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++){
            if (node->child[i]){
                for (int j = 0; j < layer; j++){
                    printf("---");
                }
                printf("%c", i + 'a');
                if (node->child[i]->is_end){
                    printf("(end)");
                }
                printf("\n");
                preorder_trie(node->child[i], layer + 1);
            }
        }
    }

private:
    TrieNode* new_node()
    {
        TrieNode *node = new TrieNode();
		_node_vec.push_back(node);
        return node;
    }
    vector<TrieNode*> _node_vec;
    TrieNode _root;
};

int main()
{
    Trie trie;
    
    trie.insert("apple");
    cout<<trie.search("apple")<<endl;// 返回 true
    cout<<trie.search("app")<<endl;// 返回 false
    cout<<trie.startsWith("app")<<endl; // 返回 true
    trie.insert("app");   
    cout<<trie.search("app")<<endl;     // 返回 true

}