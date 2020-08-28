#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
/*先复制，再分离*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead)
            return nullptr;
        
        RandomListNode *p;
        p = pHead;
        while(p)
        {
            RandomListNode *node = new RandomListNode(p->label);
            node->next = p->next;
            p->next = node;
            p = node->next;
        }
        RandomListNode *q,*cHeap;
        p = pHead;
        while (p && p->next && p->random)
        {
            q = p->next;
            q->random = p->random->next;
            p = q->next;
        }
        
        //拆分
        p = pHead;
        q = cHeap = p->next;
        while (p && q)
        {
            p->next = q->next;
            p = q->next;
            q->next = p->next;
            q = p->next;
        }
        return cHeap;
    }
};

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution2 {
    /*复制每个链表的节点，形成A-A'-B-B'-C-C'-D-D'*/
    void CloneNode(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        RandomListNode* pCloneNode;
        while(pNode != nullptr)
        {
            pCloneNode = new RandomListNode(pNode->label);
            pCloneNode->next = pNode->next;            
            pNode->next =  pCloneNode;
            pNode = pCloneNode->next;
        }        
    }
    void ConnectRandomNode(RandomListNode* pHead)
    {
        RandomListNode *pNode = pHead;
        while(pNode != NULL)
        {
            RandomListNode *pCloneNode = pNode->next;
            if(pNode->random != NULL)
            {
                pCloneNode->random = pNode->random->next;
            }
            pNode = pCloneNode->next;
        }
    }
     RandomListNode* CloneList(RandomListNode* pHead)
     {
         RandomListNode *pNode = pHead;
         RandomListNode *pCloneHead;
         RandomListNode *pCloneNode;
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
    
    RandomListNode* Clone(RandomListNode* pHead)
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