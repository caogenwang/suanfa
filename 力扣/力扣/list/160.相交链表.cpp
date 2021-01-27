#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unistd.h>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA;
        ListNode *B = headB;
        int a=0;
        int b=0;
        while (A)
        {
            A=A->next;
            a++;
        }

        while (B)
        {
            B=B->next;
            b++;
        }
        A = headA;
        B = headB;
        if (b>a)
        {
            int count = b-a;
            while (count>0 && B)
            {
                B=B->next;
                count--;
            }
            while (A && B)
            {
                if (A == B)
                {
                    return A;
                }
                A=A->next;
                B=B->next;
            }
        }
        else
        {
            int count = a-b;
            while (count>0 && A)
            {
                A=A->next;
                count --;
            }
            while (A && B)
            {
                if (A == B)
                {
                    return A;
                }
                A=A->next;
                B=B->next;
            }
        }
        return nullptr;
    }
};
class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};
int main()
{

}