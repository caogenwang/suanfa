#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，
    并且每个节点只能存储一位数字。
    请你将两个数相加，并以相同形式返回一个表示和的链表。
    
    输入：l1 = [2,4,3], l2 = [5,6,4]
    输出：[7,0,8]
    解释：342 + 465 = 807.

    输入：
    [9,9,9,9,9,9,9]
    [9,9,9,9]
    输出：
    [8,9,9,9,10,9,9]
    预期：
    [8,9,9,9,0,0,0,1]
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0;
        ListNode* tl = l1;
        while (tl)
        {
            len1++;
            tl = tl->next;
        }

        int len2 = 0;;
        tl = l2;
        while (tl)
        {
            len2++;
            tl = tl->next;
        }

        int len = ::min(len1,len2);
        ListNode* lx = new ListNode();
        ListNode* lx2 = lx;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int sum = 0;
        int left = 0;
        int ap = 0;

        for (int i = 0; i < len; i++)
        {
            sum = t1->val + t2->val + ap;
            ap = 0;
            left = sum;
            if (sum >= 10)
            {
                left = sum - 10;
                ap = 1;
            }
            lx->next = new ListNode(left);
            lx = lx->next;

            t1 = t1->next;
            t2 = t2->next;
        }
        while (t1)
        {
            sum = t1->val + ap;
            left = sum;
            ap = 0;
            if (sum >= 10)
            {
                left = sum - 10;
                ap = 1;
            }

            lx->next = new ListNode(left);
            lx = lx->next;
            t1 = t1->next;
        }

        while (t2)
        {
            sum = t2->val + ap;
            left = sum;
            ap = 0;
            if (sum >= 10)
            {
                left = sum - 10;
                ap = 1;
            }

            lx->next = new ListNode(left);
            lx = lx->next;
            t2 = t2->next;
        }
        if (ap != 0)
        {
            lx->next = new ListNode(ap);
            lx = lx->next;
        }
        
        return lx2->next;
    }
};
void cteate_list(vector<int>&vec,ListNode* list)
{
    ListNode* t1 = list; 
    for (int i = 0; i < vec.size(); i++)
    {
        t1->next = new ListNode(vec[i]);
        t1 = t1->next;
    }
}

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        int carry = 0;
        while (l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) 
            cur->next = new ListNode(1);
        return dummy->next;
    }
};

int main()
{
    vector<int> v1{9,9,9,9,9,9,9};
    vector<int> v2{9,9,9,9};
    ListNode* list1 = new ListNode();
    cteate_list(v1,list1);
    list1 = list1->next;

    ListNode* list2 = new ListNode();
    cteate_list(v2,list2);
    list2 = list2->next;

    Solution1 s1;
    ListNode* res = s1.addTwoNumbers(list1,list2);
    while (res)
    {
        cout<<res->val<<endl;
        res = res->next;
    }
}   