#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
#define TRIE_MAX_CHAR_NUM 26
struct TrieNode{
    TrieNode* child[TRIE_MAX_CHAR_NUM];//指针数组
    bool is_end;
    TrieNode():is_end(false){
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++)
        {
            child[i] = 0;
        }
    }
};

class TrieTree{
public:
    TrieTree(){
        _root = new_node();
	}
    void insert(const char*words){
        TrieNode *ptr = _root;
        while (*words){
            int pos = *words - 'a';
            if (!ptr->child[pos])
            {
                ptr->child[pos] = new_node();
            }
            ptr = ptr->child[pos];
            words++;
        }
        ptr->is_end = true;
    }

    bool search(const char*words){
        TrieNode *ptr = _root;
        while (*words)
        {
            int pos = *words - 'a';
            if (!ptr->child[pos])
            {
                return false;
            }
            ptr = ptr->child[pos];
            words++;
        }
        return ptr->is_end;
    }

    TrieNode *root(){
    	return _root;
    }

    bool startWith(const char* prefix){
        TrieNode *ptr = _root;
        while (*prefix)
        {
            int pos = *prefix - 'a';
            if (!ptr->child[pos])
            {
                return false;
            }
            ptr = ptr->child[pos];
            prefix++;
        }
        return ptr->is_end;
    }

    ~TrieTree(){
        for (int i = 0; i < _vec_nodes.size(); i++){
            delete _vec_nodes[i];
        }
    }
private:
    TrieNode *new_node(){
        TrieNode *node = new TrieNode();
        _vec_nodes.push_back(node);
        return node;
    }
    TrieNode *_root;
    vector<TrieNode*> _vec_nodes;
};

void preorder_trie(TrieNode *node, int layer){
    TrieNode *ptr = node;
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++)
    {
        
        if (ptr->child[i])
        {
            for (int j = 0; j < layer; j++){
				printf("-");
			}
            printf("%c",i+'a');
            if (ptr->child[i]->is_end)
            {
                 printf("(end)");
            }
            printf("\n");
            preorder_trie(ptr->child[i],layer + 1);
        }
    }
}

void get_all_word_from_trie(TrieNode *node, std::string &word,
				   std::vector<std::string> &word_list){
    TrieNode*ptr = node;
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++)
    {
        if(ptr->child[i]){
            word.push_back(i+'a');
            if (node->child[i]->is_end)
            {
                word_list.push_back(word);
            }
            get_all_word_from_trie(ptr->child[i],word,word_list);
            word.erase(word.length()-1, 1);//弹栈
        }
    }
}

int main(int argc,char**argv)
{
    TrieTree *tree = new TrieTree();
    tree->insert("abcd");
    tree->insert("abc");
	tree->insert("abd");
	tree->insert("b");
	tree->insert("bcd");
	tree->insert("efg");
    preorder_trie(tree->root(),0);
    string word;
    vector<string> word_list;
    get_all_word_from_trie(tree->root(),word,word_list);
    for (int i = 0; i < word_list.size(); i++){
		printf("%s\n", word_list[i].c_str());
	}
    delete tree;
}