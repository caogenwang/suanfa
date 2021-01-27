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
    ListNode *detectCycle(ListNode *head) {
        std::set<ListNode *> node_set;
        while(head){
        	if (node_set.find(head) != node_set.end()){
	        	return head;
	        }
	        node_set.insert(head);
        	head = head->next;
        }
        return NULL;
    }
};

class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
    	ListNode *fast = head;
    	ListNode *slow = head;
    	ListNode *meet = NULL;
    	while(fast){
    		slow = slow->next;
    		fast = fast->next;
    		if (!fast){
		    	return NULL;
		    }
		    fast = fast->next;
            cout<<slow->val<<" "<<fast->val<<endl;
		    if (fast == slow){
    			meet = fast;
    			break;
    		}
	    }
	    if (meet == NULL){
    		return NULL;
    	}
        cout<<"---------------"<<endl;
    	while(head && meet){
            cout<<head->val<<" "<<meet->val<<endl;
	    	if (head == meet){
	    		return head;
	    	}
	    	head = head->next;
	    	meet = meet->next;
	    }
        cout<<"---------------"<<endl;
        return NULL;
    }
};

int main()
{
    ListNode * n1 = new ListNode(1);
    ListNode * n2 = new ListNode(2);
    ListNode * n3 = new ListNode(3);
    ListNode * n4 = new ListNode(4);
    ListNode * n5 = new ListNode(5);
    ListNode * n6 = new ListNode(6);
    ListNode * n7 = new ListNode(7);

    ListNode *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n4;

    Solution2 so;
    ListNode * res = so.detectCycle(head);
    cout<<"---------------"<<endl;
    cout<<res->val<<endl;
    // while (head)
    // {
    //     cout<<head->val<<endl;
    //     head = head->next;
    //     sleep(1);
    // }
    return 0;
}
