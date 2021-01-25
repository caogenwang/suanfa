#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *h1 = l1;
        ListNode *h2 = l2;
        ListNode *head = new ListNode(-1);
        ListNode *ptr = head;
        while (h1 && h2){
            if (h1->val < h2->val){
                ptr->next = h1;
                h1 = h1->next;
            }
            else if(h1->val < h2->val){
               ptr->next = h1;
                h1 = h1->next;
            }
            ptr = ptr->next; 
        }
        ptr->next = h1 ? h1 : h2;
        return  head->next;;
    }
};

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

class Solution3 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) 
            return l2;
        if (!l2) 
            return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

class Solution4 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *head = l1->val < l2->val ? l1 : l2;
        ListNode *nonhead = l1->val < l2->val ? l2 : l1;
        head->next = mergeTwoLists(head->next, nonhead);
        return head;
    }
};

int main()
{
    ListNode *l1 = new ListNode(2);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(4);
    // l1->next = node1;
    // node1->next = node2;
    // node2->next = nullptr;

    ListNode *l2 = new ListNode(1);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    // l2->next = node3;
    // node3->next = node4;
    // node4->next = nullptr;

    Solution2 so;
    ListNode *res = so.mergeTwoLists(l1,l2);
    while (res)
    {
        cout<<res->val<<endl;
        res = res->next;
    }
    
}