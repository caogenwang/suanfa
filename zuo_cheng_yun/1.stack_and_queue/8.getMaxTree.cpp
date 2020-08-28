#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
using namespace std;

struct Node{
    int value;
    struct Node *left;
    struct Node *right;
    //结点的初始化
    Node(int data):value(data),left(nullptr),right(nullptr) {
    }
};

class Solution
{
    public:
        Node *getMaxTree(std::vector<int> &arr)
        {
            vector<Node*> nodes;
            for (int i = 0; i < arr.size(); i++)
            {
                Node *node = new Node(arr[i]);
                nodes.push_back(node);
            }
            std::map<Node*,Node*> lBigMap;
            std::map<Node*,Node*> rBigMap;
            std::stack<Node*> s;
            //从第一个开始
            // 找出所有数，左边第一个比自身大的数,键值对就是本身节点和左边第一个比自身大的数
            for (int i = 0; i != arr.size(); i++) 
            {
                Node *curNode = nodes[i];
                while ((!s.empty()) && (s.top())->value < curNode->value) {
                    popStackSetMap(s, lBigMap);//栈的一系列操作
                }
                s.push(curNode);
            }
            while (!s.empty()) 
            {
                popStackSetMap(s, lBigMap);
            }

            //从最后一个开始
            // 找出所有数，右边第一个比自身大的数，键值对就是本身节点和右边第一个比自身大的数
            for (int i = arr.size() - 1; i != -1; i--) {
                Node *curNode = nodes[i];
                while ((!s.empty()) && (s.top())->value < curNode->value) {
                    popStackSetMap(s, rBigMap);//栈的一系列操作
                }
                s.push(curNode);
            }

            while (!s.empty()) {
                popStackSetMap(s, rBigMap);
            }

            Node *head = nullptr; //声明头结点
            for (int i = 0; i != nodes.size(); i++) 
            {//遍历所有的节点
                Node *curNode = nodes[i];
                Node *left = lBigMap[curNode];
                Node *right = rBigMap[curNode];
                //左右都空，证明他是最大的头节点
                if (left == nullptr && right == nullptr) {
                    head = curNode;
                } else if (left == nullptr) {//左为空，就串在右的底下
                    if (right->left == nullptr) {//从左到右
                        right->left = curNode;
                    } else {
                        right->right = curNode;
                    }
                } else if (right == nullptr) {//右为空，就串在左的底下
                    if (left->left == nullptr) {//从左到右
                        left->left = curNode;
                    } else {
                        left->right = curNode;
                    }
                } else {
                    //选择左右较小的数为父节点
                    Node *parent = left->value < right->value ? left : right;
                    if (parent->left == nullptr) {//从左到右
                        parent->left = curNode;
                    } else {
                        parent->right = curNode;
                    }
                }
            }
            return head;
        }

        void popStackSetMap(stack<Node*> &s,map<Node*,Node*>&m)
        {
            Node* popNode = s.top();
            s.pop();
            if (s.empty()) {
                m.insert(std::pair<Node*,Node*>(popNode, nullptr));
            } else {
                m.insert(std::pair<Node*,Node*>(popNode, s.top())); //构造二叉树操作
            }
        }

         //二叉树的先序遍历
    void printPreOrder(Node *head) {
        if (head == nullptr) { return; }
        printf("%d ",head->value);
        printPreOrder(head->left);  //递归调用遍历二叉树
        printPreOrder(head->right);
    }

    //二叉树的中序遍历
    void printInOrder(Node *head) {
        if (head == nullptr) { return; }
        printInOrder(head->left);
        printf("%d ",head->value);
        printInOrder(head->right);
    }
};



int main()
{
    vector<int> arr = {3,4,5,1,2};
    Solution s;
    Node *head = s.getMaxTree(arr);
    s.printInOrder(head);
    printf("\n");
    s.printPreOrder(head);
    printf("\n");
}