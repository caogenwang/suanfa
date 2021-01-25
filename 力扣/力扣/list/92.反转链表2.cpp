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

class Solution {//error
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pre = head;
        ListNode* next = head;
        ListNode* tmp = head;
        int range = n - m;
        while (pre && m>2)
        {
            pre = pre->next;
            m--;
        }
        tmp = pre->next;
        while (next && n>1)
        {
            next = next->next;
            n--;
        }
        // cout<<pre->val<<endl;
        // cout<<tmp->val<<endl;
        // cout<<next->val<<endl;
        while (range>0)
        {
            pre->next = tmp->next;
            tmp->next = next->next;
            next->next = tmp;

            tmp = pre->next;
            next = next->next;
            range --;
        }
        return head;
    }
};

class Solution2 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        vector<int> nodes;
        ListNode* ptr = head;
        while (ptr)
        {
            nodes.push_back(ptr->val);
            ptr = ptr->next;
        }
        reverse(nodes.begin()+m-1,nodes.begin()+n);        
        ptr = head;
        int i = 0; 
        while (ptr && i < nodes.size())
        {
            ptr->val = nodes[i];
            ptr = ptr->next;
            i ++;
        }
        return head;
    }
};

class Solution3 {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        for (int i = 0; i < m - 1; ++i) 
            pre = pre->next;
        ListNode *cur = pre->next;

        for (int i = m; i < n; ++i) 
        {
            ListNode *t = cur->next;
            cur->next = t->next;
            t->next = pre->next;
            pre->next = t;
            ListNode *h = dummy->next;
            while (h)
            {
                cout<<h->val<<endl;
                h = h->next;    
            }
            cout<<"---------"<<endl;
        }
        return dummy->next;
    }
};

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);
    ListNode* n7 = new ListNode(7);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = nullptr;
    Solution3 so;
    ListNode* h = so.reverseBetween(n1,2,6);
    while (h)
    {
        cout<<h->val<<endl;
        h = h->next;    
    }
    
}