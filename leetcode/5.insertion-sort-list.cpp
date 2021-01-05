#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head)
            return head;
        ListNode tmp(0);
        ListNode* p, *q, *t;
        while (head) {
            p = &tmp;
            q = p->next;
            t = head;
            head = head->next;
            while (q && q->val < t->val) {
                p = p->next;
                q = q->next;
            }
            t->next = q;
            p->next = t;
        }
         
        return tmp.next;

    }
};

int main(int argc,char**argv)
{
    return 0;
}

class Solution2 {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next==NULL) return head;
        list<int> v;
        for(ListNode *p=head;p!=NULL;p=p->next){
            v.push_back(p->val);
        }
        v.sort();
        for(ListNode *p = head;p!=NULL;p=p->next){
            p->val=v.front();
            v.pop_front();
        }
        return head;
    }
};

class Solution3 {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next==NULL) 
            return head;
        ListNode temp(0);
        ListNode *p,*q,*t;
        while (head != nullptr)
        {
            p = &temp;
            t=p;
            p = p->next;
            q = head;
            head = head->next;
            while (p && p->val < q->val)
            {
                t = t->next;
                p = p->next;

            }
            q->next = p;
            t->next = q;
        }
    return temp.next;    
    }
};