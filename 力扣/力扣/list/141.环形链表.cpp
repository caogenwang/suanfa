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
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *f = head;
        ListNode *s = head->next;
        while (f && s && s->next)
        {
            if (f == s)
            {
                return true;
            }
            f = f->next;
            s = s->next->next;
        }
        return false;
    }
};
int main()
{

}
