#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include "BinaryTree.h"
using namespace std;
/*****************************
1、minimum-depth-of-binary-tree
*****************************/
//递归:
class Solution {
public:
    int run(TreeNode *root) {
        if(root == nullptr)
            return 0;
        if(root->left == nullptr) return 1 + run(root->right);
        if(root->right == nullptr) return 1 + run(root->left);
        return 1 + min(run(root->left), run(root->right));
    }
};
//迭代
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            ++res;
            for (int i = q.size(); i > 0; --i) {//一层一层的遍历，一个for循环就是一层
                auto t = q.front(); q.pop();
                if (!t->left && !t->right) return res;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return -1;
    }
};

/*****************************
2、evaluate-reverse-polish-notation
*****************************/
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s; 
        size_t result = 0;
        for(size_t i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" ||
            tokens[i] == "*" ||tokens[i] == "/" )
            {
                if(s.size() < 2) return 0;
                int a = s.top();s.pop();
                int b = s.top();s.pop();
                if (tokens[i] == "+")
                {
                    result = a + b;
                    s.push(result);
                }else if(tokens[i] == "-")
                {
                    result = a - b;
                    s.push(result);
                }
                else if(tokens[i] == "*")
                {
                    result = a * b;
                    s.push(result);
                }
                else if(tokens[i] == "/")
                {
                    result = a / b;
                    s.push(result);
                }
                
            }
            else
            {
                s.push(atoi(tokens[i].c_str()));
            }
            
        } 
    }
};

/*****************************
3、max-points-on-a-line
一条线上最多的点
*****************************/
class Solution {
    struct Point {
        int x;
        int y;
        Point() : x(0), y(0) {}
        Point(int a, int b) : x(a), y(b) {}
 };
    
public:
    int maxPoints(vector<Point> &points) {
        size_t length = 0;
        length = points.size();
        
        if(length == 0)
            return 0;
        else if(length == 1)
            return 1;

        int ret = 0;
        for (size_t i = 0; i < length; i++)
        {
            int curmax = 1;
            map<double,int> mp;
            int vcnt = 0;
            int dup = 0;

            for (size_t j = 0; j < length; j++)
            {
                if(j != i)
                {
                    double x1 = points[i].x - points[j].x;
                    double y1 = points[i].y - points[j].y;
                    if(x1 == 0 && y1 == 0)
                    {
                        dup ++;
                    }
                    else if(x1 == 0)
                    {
                        if(vcnt == 0)
                            vcnt = 2;
                        else
                            vcnt ++;
                        curmax = max(vcnt,curmax);
                    }
                    else
                    {
                        double k = y1/x1;
                        if(mp[k] == 0)
                            mp[k] = 2;
                        else
                            mp[k]++;
                        curmax = max(mp[k],curmax);
                    } 
                }
            }
            ret = max(ret,curmax+dup);
        }
        return ret; 
    }
};

/*****************************
4、sort a link list by 归并排序
思路：
因为题目要求复杂度为O(nlogn),故可以考虑归并排序的思想。
归并排序的一般步骤为：
1）将待排序数组（链表）取中点并一分为二；
2）递归地对左半部分进行归并排序；
3）递归地对右半部分进行归并排序；
4）将两个半部分进行合并（merge）,得到结果。

所以对应此题目，可以划分为三个小问题：
1）找到链表中点 （快慢指针思路，快指针一次走两步，慢指针一次走一步，快指针在链表末尾时，慢指针恰好在链表中点）；
2）写出merge函数，即如何合并链表。 （见merge-two-sorted-lists 一题解析）
3）写出mergesort函数，实现上述步骤。
*****************************/
class Solution {
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
/*bottom-to-up算法*/
class Solution {
    struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        auto p = head;
        int length = 0;//计算链表长度
        while (p) {
            ++length;
            p = p->next;
        }
 
        for (int size = 1; size < length; size <<= 1) {
            auto cur = dummyHead.next;
            auto tail = &dummyHead;
 
            while (cur) {
                auto left = cur;
                auto right = cut(left, size); // left->@->@ right->@->@->@...
                cur = cut(right, size); // left->@->@ right->@->@  cur->@->...
 
                tail->next = merge(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        return dummyHead.next;
    }
 
    ListNode* cut(ListNode* head, int n) {
        auto p = head;
        while (--n && p) {
            p = p->next;
        }
 
        if (!p) return nullptr;
 
        auto next = p->next;
        p->next = nullptr;
        return next;
    }
 
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        auto p = &dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;      
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};

/*5.insert sort*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
    };
public:
    ListNode *insertionSortList(ListNode *head) {
        auto new_head =  head;
        auto cur = head;
        ListNode * next;
        while (next != nullptr)
        {
            cur = next;
            next = cur->next;
            insert(new_head,cur); 
        }
    }
     ListNode *insert(ListNode *head,ListNode *node)
     {
        auto c = head;
        auto n = head->next;
        while (c != nullptr)
        {
            if (c->val < node->val)
            {
                
            }
            
        }
        
        
     }
};