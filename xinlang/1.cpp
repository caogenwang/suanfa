/*
两个链表的交点
*/
#include <iostream>
using namespace std;

typedef struct ListNode_s{
    int value;
    struct ListNode_s *next;
}ListNode;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode *a = headA;
        ListNode *b = headB;
        int n1 = 0,n2=2;
        while (a){
            n1++;
            a = a->next;
        }

        while (b){
            n2++;
            b = b->next;
        }
        if (n1>n2)
        {
            int diff = n1 - n2;a = headA;b=headB;
            while (diff && a != nullptr){
                a = a->next;
                diff --;
            }
            while (a && b)
            {
                if(a == b)
                    return a;
                a = a->next;
                b = b->next;
            }
        }
        else{
            int diff = n2 - n1;a = headA;b=headB;
            while (diff && b != nullptr){
                b = b->next;
                diff --;
            }
            while (a && b)
            {
                if(a == b)
                    return a;
                a = a->next;
                b = b->next;
            }
        }
    }
};
