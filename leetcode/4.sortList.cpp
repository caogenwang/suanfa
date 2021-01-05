#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *f=head;
        ListNode *mid = head;
        while (f != nullptr)
        {
            f=f->next;
            if(f!=nullptr)
            {
                f=f->next;
                mid=mid->next;
            }
        } 
        ListNode* right = sortList(mid->next);
        mid->next = NULL;
        ListNode* left = sortList(head);  
        return merge(right,left);
    }
    ListNode*merge(ListNode*l1,ListNode*l2)
    {
        ListNode temp(0);
        ListNode *p = &temp;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) p->next = l1;
        if (l2) p->next = l2;
        return temp.next;
    }
        
};


int main(int argc,char**argv)
{
    return 0;
}

class Solution2 {
public:
    ListNode *sortList(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *mid = search_middle(head);
        ListNode *midnext = mid->next;
        mid->next = nullptr;
        return merge(sortList(head),sortList(midnext));
    }
    ListNode *search_middle(ListNode *head)
    {
        ListNode *f=head;
        ListNode *s = head;
        if(head!=nullptr)
        {
            while (f != nullptr)
            {
                f=f->next;
                if(f!=nullptr)
                {
                    f=f->next;
                    s=s->next;
                }
            }
        }
        return s;
    }
     
     ListNode * merge(ListNode * n1,ListNode *n2)//两个链表的合并
     {
        ListNode *preHead = new ListNode(0);
        ListNode *cur1 = n1;
        ListNode *cur2 = n2;
        ListNode *cur = preHead;
        while (cur1 != nullptr && cur2 != nullptr)
        {
            if(cur1->val < cur2->val)
            {
                cur->next = cur1;
                cur1 = cur1->next;
            }
            else
            {
                 
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur=cur->next;
        }
        if(cur1 != nullptr)
        {
            cur->next = cur1;
        }
        if(cur2 != nullptr)
        {
            cur->next = cur2;
        }
        return preHead->next;
   }
};