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
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return nullptr;
        ListNode *f = head;
        ListNode *s = head->next;
        bool flag = false;
        int count = 0;
        while (f && s && s->next)
        {
            count ++;
            if (f == s)
            {
                flag = true;
                break;
            }
            f = f->next;
            s = s->next->next;
        }
        if (flag)//有环
        {
            
        }
        return nullptr;
    }
};
int main()
{

}
