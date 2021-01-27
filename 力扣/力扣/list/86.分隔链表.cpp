#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。
输入：head = 1->4->3->2->5->2, x = 3
输出：1->2->2->4->3->5

*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* partition(ListNode* head, int x) {
    if(!head)
        return nullptr;
    ListNode* pre = head;
    while (pre->next && pre->next->val < x)//缺少从head就开始比较的那个步骤
        pre = pre->next;
    ListNode* cur = pre;
    while (cur->next)
    {
        if (cur->next->val < x)
        {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
            pre = pre->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    return head;
}

ListNode* partition2(ListNode* head, int x) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* pre = dummy;

    while (pre->next && pre->next->val < x)
        pre = pre->next;
    cout<<pre->val<<endl;

    ListNode* cur = pre;
    cur = pre;
    while (cur->next) {
        if (cur->next->val < x) {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
            pre = pre->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    return dummy->next;
}

int main()
{
    ListNode * n1 = new ListNode(2);
    ListNode * n2 = new ListNode(1);
    ListNode * n3 = new ListNode(3);
    ListNode * n4 = new ListNode(2);
    ListNode * n5 = new ListNode(5);
    ListNode * n6 = new ListNode(2);

    ListNode *head = n1;
    n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;
    // n5->next = n6;

    int x = 2;
    head = partition(head,x);
    while (head)
    {
        cout<<head->val<<endl;
        head = head->next;
    }
}