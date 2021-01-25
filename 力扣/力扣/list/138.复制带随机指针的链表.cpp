#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *ptr = head;
        while (ptr)
        {
            Node *t = new Node(ptr->val);
            t->next = ptr->next;
            ptr->next = t;
            ptr = t->next;
        }
        ptr = head;
        while (ptr && ptr->next)
        {
            ptr->next->random = ptr->random->next;
            ptr = ptr->next->next;
        }
        ptr = head;
        Node *clone = head->next;
        Node *h = clone;
        while (ptr->next->next)
        {
            clone->next = ptr->next->next;
            clone = clone->next;
            ptr = ptr->next->next;
        }
        return h;
    }
};
class Solution2 {
    public:
/*复制每个链表的节点，形成A-A'-B-B'-C-C'-D-D'*/
    void CloneNode(Node* pHead)
    {
        Node* pNode = pHead;
        Node* pCloneNode;
        while(pNode != nullptr)
        {
            pCloneNode = new Node(pNode->val);
            pCloneNode->next = pNode->next;           
            pNode->next =  pCloneNode;
            pNode = pCloneNode->next;
        }       
    }
    void ConnectRandomNode(Node* pHead)
    {
        Node *pNode = pHead;
        while(pNode != NULL)
        {
            Node *pCloneNode = pNode->next;
            if(pNode->random != NULL)
            {
                pCloneNode->random = pNode->random->next;
            }
            pNode = pCloneNode->next;
        }
    }
     Node* CloneList(Node* pHead)
     {
         Node *pNode = pHead;
         Node *pCloneHead;
         Node *pCloneNode;
         pCloneHead = pHead->next;
         while(pNode != nullptr)
         {
             pCloneNode = pNode->next;
             pNode->next = pCloneNode->next;
             pNode = pNode->next;
             if (pNode != nullptr)          
                 pCloneNode->next = pNode->next;
         }
         return pCloneHead;
     }
public:
     
    Node* Clone(Node* pHead)
    {
        if(pHead == nullptr)
            return nullptr;
        CloneNode(pHead);
        ConnectRandomNode(pHead);
        return CloneList(pHead);;
    }
};

int main()
{

}